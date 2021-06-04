/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:22:26 by mskinner          #+#    #+#             */
/*   Updated: 2021/03/01 02:06:01 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _RBTREE_HPP_
# define _RBTREE_HPP_

# include "Node.hpp"

namespace ft
{		
	template < typename Key, typename T, class Compare = std::less<Key> >
	class RBTree
	{
	public:
		Node<Key, T>	*_root;
		Node<Key, T>	*_end_left;
		Node<Key, T>	*_end_right;
		size_t			_size;

		RBTree() : _root(NULL), _size(0) {
			_end_left = new Node<Key, T>();
			_end_left->_color = END;
			_end_right = new Node<Key, T>();
			_end_right->_color = END;
		};
		RBTree(const Key &key, const T &content) : _root(NULL), _size(0) {
			insert(key, content);
		};
		RBTree(const RBTree &copy) : _root(NULL), _size(0) {
			copy(copy._root);
		};
		~RBTree() {
			clear();
			delete _end_left;
			delete _end_right;
		};
		RBTree& operator=(const RBTree &other) {
			if (this != &other) {
				clear();
				_root = NULL;
				copy(other._root);
			}
			return (*this);
		};

	private:
		//Filling tree
		Node<Key, T>*	RBTInsert(Node<Key, T> *root, Node<Key, T> *current, Compare compare = Compare()) {
			//Inserting the first node, if not root
			if (!root)
				return (current);
			//Otherwise, performing recursion down the tree
			if (compare(root->_content.first, current->_content.first)) {
				root->_right = RBTInsert(root->_right, current);
				root->_right->_parent = root;
			}
			else {
				root->_left = RBTInsert(root->_left, current);
				root->_left->_parent = root;
			}
			return (root);
		};

		void	rotateLeft(Node<Key, T> *&root, Node<Key, T> *&current) {
			Node<Key, T>	*current_right = current->_right;

			current->_right = current->_right->_left;
			if (current->_right)
				current->_right->_parent = current;
			current_right->_parent = current->_parent;
			if (!current->_parent)
				root = current_right;
			else if (current == current->_parent->_left)
				current->_parent->_left = current_right;
			else
				current->_parent->_right = current_right;
			current_right->_left = current;
			current->_parent = current_right;
		};

		void	rotateRight(Node<Key, T> *&root, Node<Key, T> *&current) {
			Node<Key, T>	*current_left = current->_left;

			current->_left = current->_left->_right;
			if (current->_left)
				current->_left->_parent = current;
			current_left->_parent = current->_parent;
			if (!current->_parent)
				root = current_left;
			else if (current == current->_parent->_left)
				current->_parent->_left = current_left;
			else
				current->_parent->_right = current_left;
			current_left->_right = current;
			current->_parent = current_left;
		};

		//Fixing violations caused by BST insertion
		void	fixViolation(Node<Key, T> *&root, Node<Key, T> *&current) {
			Node<Key, T>	*parent = NULL;
			Node<Key, T>	*grandparent = NULL;

			while (current && (current->_color != BLACK)
			&& (current->_parent) && (current->_parent->_color == RED)) {
				parent = current->_parent;
				grandparent = current->_parent->_parent;

			//A: Parent of pt is left child  of Grand-parent of pt
				if (parent == grandparent->_left) {
					Node<Key, T> *uncle = grandparent->_right;
					
				//1) The uncle of pt is also red (recoloring only)
					if (uncle && (uncle->_color == RED)) {
						grandparent->_color = RED;
						parent->_color = BLACK;
						uncle->_color = BLACK;
						current = grandparent;
					}
					else {
				//2) pt is right child of its parent (left-rotation required)
						if (current == parent->_right) {
							rotateLeft(root, parent);
							current = parent;
							parent = current->_parent;
						}
				//3) pt is left child of its parent (right-rotation required)
						rotateRight(root, grandparent);
						swap_element(parent->_color, grandparent->_color);
						current = parent;
		            }
		        } 
		    //B: Parent of pt is right child of Grand-parent of pt
				else {
					Node<Key, T>	*uncle = grandparent->_left; 

		        //1) The uncle of pt is also red (recoloring only)
					if (uncle && (uncle->_color == RED)) {
						grandparent->_color = RED;
						parent->_color = BLACK;
						uncle->_color = BLACK;
						current = grandparent; 
		            } 
		            else
		            {
				//2) pt is left child of its parent (right-rotation required)
						if (current == parent->_left) {
							rotateRight(root, parent);
							current = parent;
							parent = current->_parent;
						}
						
				//3) pt is right child of its parent (left-rotation required)
						rotateLeft(root, grandparent);
						swap_element(parent->_color, grandparent->_color);
						current = parent;
					}
				}
			}
			root->_color = BLACK;
		};

		Node<Key, T>*	RBTReplace(Node<Key, T> *old) {
			//Node is a leaf
			if (!old->_left && !old->_right)
				return (NULL);
			//Node has both children
			if (old->_left && old->_right)
				return (minimum(old->_right));
			//Node has one child
			if (!old->_left)
				return (old->_right);
			else
				return (old->_left);
		};
		
		void	fixBlacks(Node<Key, T> *fix) {
			if (fix == _root)
				return ;

			Node<Key, T>*	sibling = fix->sibling();
			Node<Key, T>*	parent = fix->_parent;
			
			if (!sibling)
				fixBlacks(parent);
			else {
				if (sibling->_color == RED) {
					parent->_color = RED;
					sibling->_color = BLACK;
					if (sibling->isLeft())
						rotateRight(_root, parent);
					else
						rotateLeft(_root, parent);
					fixBlacks(fix);
				}
				else {
					if (sibling->hasRedChild()) {
						if (sibling->_left && (sibling->_left->_color == RED)) {
							if (sibling->isLeft()) {
								sibling->_left->_color = sibling->_color;
								sibling->_color = parent->_color;
								rotateRight(_root, parent);
							}
							else {
								sibling->_left->_color = parent->_color;
								rotateRight(_root, sibling);
								rotateLeft(_root, parent);
							}
						}
						else {
							if (sibling->isLeft()) {
								sibling->_right->_color = parent->_color;
								rotateLeft(_root, sibling);
								rotateRight(_root, parent);
							}
							else {
								sibling->_right->_color = sibling->_color;
								sibling->_color = parent->_color;
								rotateLeft(_root, parent);
							}
						}
						parent->_color = BLACK;
					}
					else {
						sibling->_color = RED;
						if (parent->_color == BLACK)
							fixBlacks(parent);
						else
							parent->_color = BLACK;
					}
				}
			}
		};

		void	RBTDelete(Node<Key, T> *old) {
			Node<Key, T>	*replace = RBTReplace(old);
			Node<Key, T>	*parent = old->_parent;
			bool	blacks = (((!replace) || (replace->_color == BLACK))
			&& (old->_color == BLACK));

			if (!replace) {
				if (old == _root)
					_root = NULL;
				else {
					if (blacks)
						fixBlacks(old);
					else {
						if (old->sibling())
							old->sibling()->_color = RED;
					}
				}
				if (old->isLeft())
					parent->_left = NULL;
				else
					parent->_right = NULL;
				delete old;
				return ;
			}
			if ((!old->_left) || (!old->_right)) {
				if (old == _root) {
					old->_content = replace->_content;
					old->_left = NULL;
					old->_right = NULL;
					delete replace;
				}
				else {
					if (old->isLeft())
						parent->_left = replace;
					else
						parent->_right = replace;
					delete old;
					replace->_parent = parent;
					if (blacks)
						fixBlacks(replace);
					else
						replace->_color = BLACK;
				}
				return ;
			}
			swap_element(old->_content, replace->_content);
			RBTDelete(replace);
		};

	public:
		Node<Key, T>*	insert(const Key &key, const T &value) {
			Node<Key, T>	*pt = new Node<Key, T>(key, value);
			Node<Key, T>	*maxi;
			Node<Key, T>	*mini;

			if (_root) {
				maximum(_root)->_right = NULL;
				minimum(_root)->_left = NULL;
			}
			_root = RBTInsert(_root, pt);
			fixViolation(_root, pt);
			_size++;
			maxi = maximum(_root);
			maxi->_right = _end_right;
			_end_right->_parent = maxi;
			mini = minimum(_root);
			mini->_left = _end_left;
			_end_left->_parent = mini;
			return (pt);
		};
		
		Node<Key, T>*	insert(Node<Key, T> *pos, const Key &key, const T &value) {
			Node<Key, T>	*pt = new Node<Key, T>(key, value);
			Node<Key, T>	*maxi;
			Node<Key, T>	*mini;

			if (_root) {
				maximum(_root)->_right = NULL;
				minimum(_root)->_left = NULL;
			}
			if (pos == _root)
				_root = RBTInsert(pos, pt);
			else
				RBTInsert(pos, pt);
			fixViolation(_root, pt);
			_size++;
			maxi = maximum(_root);
			maxi->_right = _end_right;
			_end_right->_parent = maxi;
			mini = minimum(_root);
			mini->_left = _end_left;
			_end_left->_parent = mini;
			return (pt);
		};

		//Searches tree node with given key
		Node<Key, T>*	search(const Key &key, Compare compare = Compare()) {
			Node<Key, T>	*tmp = _root;

			while ((tmp) && (tmp != _end_left)
				&& (tmp != _end_right)) {
				if (compare(key, tmp->_content.first))
					tmp = tmp->_left;
				else if (key == tmp->_content.first)
					break ;
				else
					tmp = tmp->_right;
			}
			return (tmp);
		};
		
		//Counts tree nodes with given key
		size_t			count_node(Node<Key, T> *node, const Key &key, Compare compare = Compare()) {
			size_t			res = 0;

			if ((node) && ((node != _end_left)
				|| (node != _end_right))) {
				if (compare(key, node->_content.first))
					res += count_node(node->_left, key);
				else if (key == node->_content.first) {
					res++;
					res += count_node(node->_left, key);
					res += count_node(node->_right, key);
				}
				else
					res += count_node(node->_right, key);
			}
			return (res);
		};

		size_t			count(const Key &key, Compare compare = Compare()) {
			Node<Key, T>	*tmp = _root;
			size_t			res = 0;

			if ((tmp) && ((tmp != _end_left)
				|| (tmp != _end_right))) {
				if (compare(key, tmp->_content.first))
					res += count_node(tmp->_left, key);
				else if (key == tmp->_content.first) {
					res++;
					res += count_node(tmp->_left, key);
					res += count_node(tmp->_right, key);
				}
				else
					res += count_node(tmp->_right, key);
			}
			return (res);
		};

		//Deletes tree node with given key
		Key				erase(const Key &key) {
			Key	tmp = '\0';

			if (_root) {
				Node<Key, T>	*founded = search(key);
				Node<Key, T>	*maxi;
				Node<Key, T>	*mini;

				if (founded) {
					maximum(_root)->_right = NULL;
					minimum(_root)->_left = NULL;
					tmp = successor(founded)->_content.first;
					RBTDelete(founded);
					_size--;
					maxi = maximum(_root);
					maxi->_right = _end_right;
					_end_right->_parent = maxi;
					mini = minimum(_root);
					mini->_left = _end_left;
					_end_left->_parent = mini;
				}
				else
					throw std::out_of_range("Key is out of range");
			}
			return (tmp);
		};

		//Finds node in current subtree that does not have a left child
		Node<Key, T>*	minimum(Node<Key, T> *current) {
			while ((current->_left) && (current->_left != _end_left))
				current = current->_left;
			return (current);
		};
		
		Node<Key, T>*	maximum(Node<Key, T> *current) {
			while ((current->_right) && (current->_right != _end_right))
				current = current->_right;
			return (current);
		};
		
		//Finds the successor of a given node
		Node<Key, T>*	successor(Node<Key, T>	*current) {
			/*
			** If the right subtree is not null, the successor is
			** the leftmost node in the right subtree
			*/
			if (current->_right)
				return (minimum(current->_right));

			/*
			** Else it is the lowest ancestor of current node whose
			** right child is also an ancestor of current node
			*/
			Node<Key, T>	*parent = current->_parent;
			while (parent && (current == parent->_right)) {
				current = parent;
				parent = parent->_parent;
			}
			return (parent);
		};

		//Finds the predecessor of a given node
		Node<Key, T>*	predecessor(Node<Key, T> *current) {
			/*
			** If the left subtree is not null, the predecessor is
			** the rightmost node in the left subtree
			*/
			if (current->_left)
				return (maximum(current->_left));

			/*
			** Else it is the lowest ancestor of current node whose
			** left child is also an ancestor of current node
			*/
			Node<Key, T>	*parent = current->_parent;
			while (parent && (current == parent->_left)) {
				current = parent;
				parent = parent->_parent;
			}
			return (parent);
		};

		//To perform clear of tree as a whole you need to set _root as a node
		void			clear(void) {
			if (_root) {
				maximum(_root)->_right = NULL;
				minimum(_root)->_left = NULL;
			}
			clear_nodes(_root);
			_root = NULL;
			_end_right->_parent = NULL;
			_end_left->_parent = NULL;
		};
		
		//Performing tree nodes clearing one by one
		void			clear_nodes(Node<Key, T> *root) {
			if (!root)
				return ;

			//Performing recursive deleting of both subtrees at first
			clear_nodes(root->_left);
			clear_nodes(root->_right);
			
			//Deleting the current node
			delete root;
			_size--;
		};

		//Copy for a tree
		void			copy(Node<Key, T> *root) {
			if (!root)
				return ;
			insert(root->_content.first, root->_content.second);
			copy(root->_left);
			copy(root->_right);
		};
	};
};

#endif
