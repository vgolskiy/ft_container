/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:22:26 by mskinner          #+#    #+#             */
/*   Updated: 2021/06/04 17:57:16 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _NODE_HPP_
# define _NODE_HPP_

# include "Libraries.hpp"

namespace ft
{
	enum color_t {BLACK, RED, END};

	template <typename T>
	void	swap_element(T &x, T &y) {
		T	tmp;

		tmp = x;
		x = y;
		y = tmp;
	};

	template < typename Key, typename T >
	class Node
	{
	public:
		Node				*_parent;
		Node				*_left;
		Node				*_right;
		std::pair<Key, T>	_content;
		enum color_t		_color;
	
		Node() : _parent(NULL), _left(NULL), _right(NULL), _content(), _color(RED) {};
		Node(const Key &key, const T &content) :
			_parent(NULL), _left(NULL), _right(NULL) {
				_content = std::make_pair(key, content);
				_color = RED;
			};
		Node(const Node &copy) :
			_parent(copy._parent), _left(copy._left), _right(copy._right), _content(copy._content),
			_color(copy._color) {};
		~Node() {};
		Node&	operator=(const Node &other) {
			if (this != &other) {
				_parent = other._previous;
				_left = other._next;
				_right = other._right;
				_content = other._content;
				_color = other._color;
			}
			return (*this);
		};
		
		//Searching for a brother between parent children
		Node*	sibling(void) {
			if (!_parent)
				return (NULL);
			if (isLeft())
				return (_parent->_right);
			return (_parent->_left);
		};
		
		bool	isLeft(void) {
			return (this == _parent->_left);
		};

		bool	hasRedChild(void) {
			return ((_left && (_left->_color == RED))
					|| (_right && (_right->_color == RED)));
		};

		//Finds node in current subtree that does not have a left child
		Node*	minimum(Node *current) {
			while ((current->_left) && (current->_left->_color != END))
				current = current->_left;
			return (current);
		};
		
		Node*	maximum(Node *current) {
			while ((current->_right) && (current->_right->_color != END))
				current = current->_right;
			return (current);
		};
		
		//Finds the successor of a given node
		Node*	successor(Node	*current) {
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
			Node	*parent = current->_parent;
			while (parent && (current == parent->_right)) {
				current = parent;
				parent = parent->_parent;
			}
			return (parent);
		};

		//Finds the predecessor of a given node
		Node*	predecessor(Node *current) {
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
			Node	*parent = current->_parent;
			while (parent && (current == parent->_left)) {
				current = parent;
				parent = parent->_parent;
			}
			return (parent);
		};
	};
};

#endif
