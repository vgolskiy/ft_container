/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 10:41:18 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/18 16:35:51 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Map - sorted associative container that contains key-value pairs with unique keys.
** Keys are sorted by using the comparison function Compare.
** Search, removal, and insertion operations have logarithmic complexity.
** Maps are usually implemented as red-black trees.
*/

#pragma once

#ifndef _MAP_HPP_
# define _MAP_HPP_

# include "Iterator.hpp"

namespace ft {
	template <typename Key, typename T, class Compare = std::less<Key> , class Allocator = std::allocator<std::pair<const Key, T> > >
	class map {

	private:
		Allocator		_allocator;
		Compare			_compare;
		RBTree<Key, T>	*_tree;

	//https://en.cppreference.com/w/cpp/container/map
	//Member types
	public:
		typedef Key												key_type;
		typedef T												mapped_type;
		typedef std::pair<const Key, T>							value_type;
		typedef std::size_t										size_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;
		typedef value_type										&reference;
		typedef value_type										*pointer;
		typedef const value_type								&const_reference;
		typedef const value_type								*const_pointer;
		typedef ft::Iterator<Key, T>							iterator;
		typedef ft::ReverseIterator<Key, T>						reverse_iterator;
		typedef ft::ConstantIterator<Key, T>					const_iterator;
		typedef ft::ConstantReverseIterator<Key, T>				const_reverse_iterator;
		typedef typename ft::Iterator<Key, T>::difference_type	difference_type;

		//https://en.cppreference.com/w/cpp/container/map/value_compare
		// value_compare is a function object that compares objects of value_type
		// (key-value pairs) by comparing of the first components of the pairs.
		class value_compare
		{
		protected:
			Compare _compare;
			
		public:
			value_compare(void) : _compare() {}
			value_compare(Compare compare) : _compare(compare) {};
			value_compare(const value_compare &copy) : _compare(copy._compare) {};
			value_compare&	operator=(const value_compare &other) {
				if (this != &other)
					_compare = other._compare;
				return (*this);
			};

			typedef bool 		result_type;
			typedef value_type	first_argument_type;
			typedef value_type	second_argument_type;

			bool operator() (const value_type& lhs, const value_type& rhs) const {
				return (_compare(lhs.first, rhs.first));
			};
		};
		
		//https://en.cppreference.com/w/cpp/container/map/map
		//MEMBER FUNCTIONS
		//Default constructor. Constructs an empty container with a default-constructed allocator.
		map(void) : _allocator(allocator_type()), _compare() {
			_tree = new RBTree<Key, T>();
		};
		
		//Constructs an empty container with the given allocator.
		explicit map(const Compare& compare, const Allocator& allocator = Allocator()) :
			_allocator(allocator), _compare(compare) {
				_tree = new RBTree<Key, T>();
			};

		//Constructs the container with the contents of the range [first, last).
		template <class InputIt>
		map(InputIt first, InputIt last, const Compare& compare = Compare(), const Allocator& allocator = Allocator()) :
			_allocator(allocator), _compare(compare) {
				_tree = new RBTree<Key, T>();
				insert(first, last);
			};

		//Copy constructor. Constructs the container with the copy of the contents of other
		map(const map &copy) : _allocator(copy._allocator), _compare(copy._compare) {
			_tree = new RBTree<Key, T>();
			insert(copy.begin(), copy.end());
		};

		//https://en.cppreference.com/w/cpp/container/map/%7Emap
		//Destructor: clears allocator and deletes list elements
		~map(void) {
			delete _tree;
		};

		//https://en.cppreference.com/w/cpp/container/map/operator%3D
		//Replaces content of one container to another
		map&						operator=(const map &other) {
			if (this != &other) {
				_allocator = other._allocator;
				_compare = other._compare;
				clear();
				insert(other.begin(), other.end());
			}
			return (*this);
		};

		//https://en.cppreference.com/w/cpp/container/map/operator_at
		//ELEMENT ACCESS METHODS
		//Returns a reference to the value that is mapped to a key 
		//equivalent to key, performing an insertion if such key does not already exist.
		T&							operator[](const Key &key) {
			iterator	it = find(key);

			if (it == end())
				return (insert(std::make_pair(key, T())).first->second);
			return (it->second);
		};

		//ITERATORS METHODS
		//https://en.cppreference.com/w/cpp/container/vector
		//If tree is empty return end()
		iterator					begin(void) {
			if (_tree->_root)
				return (iterator(_tree->_end_left->_parent));
			else
				return (iterator(_tree->_end_right));
		};

		iterator					end(void) {
			return (iterator(_tree->_end_right));
		};

		const_iterator				begin(void) const {
			if (_tree->_root)
				return (const_iterator(_tree->_end_left->_parent));
			else
				return (const_iterator(_tree->_end_right));			
		};

		const_iterator				end(void) const {
			return (const_iterator(_tree->_end_right));
		};

		reverse_iterator			rbegin(void) {
			if (_tree->_root)
				return (reverse_iterator(_tree->_end_right->_parent));
			else
				return (reverse_iterator(_tree->_end_left));
		};

		reverse_iterator			rend(void) {
			return (reverse_iterator(_tree->_end_left));
		};

		const_reverse_iterator		rbegin(void) const {
			if (_tree->_root)
				return (const_reverse_iterator(_tree->_end_right->_parent));
			else
				return (const_reverse_iterator(_tree->_end_left));
		};

		const_reverse_iterator		rend(void) const {
			return (const_reverse_iterator(_tree->_end_left));
		};
		
		//CAPACITY: getting container size
		//https://en.cppreference.com/w/cpp/container/map/empty
		//Checks if the container has no elements, i.e. whether begin() == end().
		bool						empty(void) const {
			return (!_tree->_size);
		};

		//https://en.cppreference.com/w/cpp/container/map/size
		//Returns the number of elements in the container, i.e. std::distance(begin(), end()).
		size_type					size(void) const {
			return (_tree->_size);
		};

		//https://en.cppreference.com/w/cpp/container/map/max_size
		//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations.
		size_type					max_size(void) const {
			return (std::numeric_limits<size_type>::max() / sizeof(ft::Node<key_type, mapped_type>));
		};

		//MODIFIERS METHODS
		//https://en.cppreference.com/w/cpp/container/map/clear
		//Erases all elements from the container. After this call, size() returns zero.
		void						clear(void) {
			_tree->clear();
		};

		//https://en.cppreference.com/w/cpp/container/map/insert
		//Inserts value, returns iterator pointing to the inserted value.
		std::pair<iterator,bool>	insert(const value_type& value) {
			Node<Key, T>	*tmp = _tree->search(value.first);
			Key				key = value.first;

			if (tmp && (tmp != _tree->_end_left)
				&& (tmp != _tree->_end_right))
				return (std::make_pair(iterator(tmp), false));
			_tree->insert(value.first, value.second);
			tmp = _tree->search(key);
			return (std::make_pair(iterator(tmp), true));
		};

		/*
		** Inserts value in the position as close as possible to hint.
		** The function optimizes its insertion time if position points
		** to the element that will precede the inserted element.
		** Notice that this is just a hint and does not force the new element
		** to be inserted at that position within the map container
		** (the elements in a map always follow a specific order depending on their key).
		*/
		iterator					insert(iterator hint, const value_type& value) {
			Node<Key, T>	*tmp = _tree->search(value.first);
			iterator		it = upper_bound(value.first);
			
			if (tmp && (tmp != _tree->_end_left)
				&& (tmp != _tree->_end_right))
				return (iterator(tmp));
			if ((!_tree->_root) || (hint->first > it->first))
				return (iterator(_tree->insert(value.first, value.second)));
			return (iterator(_tree->insert(hint.get_root(), value.first, value.second)));
		};

		//Inserts elements from range [first, last).
		//If multiple elements in the range have keys that compare equivalent, it is unspecified which element is inserted.
		template < class InputIt >
		void						insert(InputIt first, InputIt last) {
			while (first != last) {
				insert(*first);
				first++;
			}
		};

		//https://en.cppreference.com/w/cpp/container/map/erase
		//Removes the element at pos.
		void						erase(iterator pos) {
			_tree->erase(pos.get_root()->_content.first);
		};

		//Removes the elements in the range [first; last), which must be a valid range in *this.
		void						erase(iterator first, iterator last) {
			Key	current = first->first;
			Key	end = last->first;

			while (current != end)
				current = _tree->erase(current);
		};

		//Removes the element (if one exists) with the key equivalent to key.
		size_type					erase(const key_type &key) {
			_tree->erase(key);
			return (_tree->_size);
		};

		//https://en.cppreference.com/w/cpp/container/map/swap
		//Exchanges the contents of the container with those of other.
		//Does not invoke any move, copy, or swap operations on individual elements.
		void						swap(map& other) {
			swap_element(_tree, other._tree);
			swap_element(_allocator, other._allocator);
			swap_element(_compare, other._compare);
		};
		
		//LOOKUP METHODS
		//https://en.cppreference.com/w/cpp/container/map/count
		//Returns the number of elements with key that compares equivalent to the specified argument,
		//which is either 1 or 0 since this container does not allow duplicates.
		size_type					count(const Key &key) const {
			return (_tree->count(key));
		};

		//https://en.cppreference.com/w/cpp/container/map/find
		//Finds an element with key equivalent to key.
		iterator					find(const Key &key) {
			Node<Key, T>	*tmp = _tree->search(key);
			
			if (tmp)
				return (iterator(tmp));
			return (iterator(_tree->_end_right));
		};

		const_iterator				find(const Key &key) const {
			return (const_iterator(_tree->search(key)));
		};

		//https://en.cppreference.com/w/cpp/container/map/equal_range
		/*
		** Compares the keys to key.
		** Returns a range containing all elements with the given key in the container.
		** The range is defined by two iterators, one pointing to the first element
		** that is not less than key and another pointing to the first element greater than key.
		** Alternatively, the first iterator may be obtained with lower_bound(),
		** and the second with upper_bound().
		*/
		std::pair<iterator,iterator>	equal_range(const Key &key) {
			return (std::make_pair<iterator, iterator>(lower_bound(key), upper_bound(key)));
		};

		std::pair<const_iterator, const_iterator>	equal_range(const Key &key) const {
			return (std::make_pair<const_iterator, const_iterator>(lower_bound(key), upper_bound(key)));
		};

		//https://en.cppreference.com/w/cpp/container/map/lower_bound
		//Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		iterator					lower_bound(const Key &key) {
			iterator	it = begin();
			Compare		compare;

			while ((it != end()) && (compare(it->first, key)))
				it++;
			return (it);
		};

		const_iterator				lower_bound(const Key &key) const {
			const_iterator	it = begin();
			Compare			compare;

			while ((it != end()) && (compare(it->first, key)))
				it++;
			return (it);
		};

		//https://en.cppreference.com/w/cpp/container/map/upper_bound
		//Returns an iterator pointing to the first element that is greater than key.
		iterator					upper_bound(const Key &key) {
			iterator	it = begin();
			Compare		compare;

			while ((it != end()) && (compare(it->first, key)))
				it++;
			if ((it != end()) && (it->first == key))
				return (++it);
			return (it);
		};

		const_iterator				upper_bound(const Key &key) const {
			const_iterator	it = begin();
			Compare			compare;

			while ((it != end()) && (compare(it->first, key)))
				it++;
			if ((it != end()) && (it->first == key))
				return (++it);
			return (it);
		};

		//OBSERVERS METHODS
		//Returns the function object that compares the keys,
		//which is a copy of this container's constructor argument comp.
		key_compare					key_comp(void) const {
			return (Compare());
		};

		//https://en.cppreference.com/w/cpp/container/map/value_comp
		//Returns a function object that compares objects of type std::map::value_type (key-value pairs)
		//by using key_comp to compare the first components of the pairs.
		value_compare				value_comp(void) const {
			return (value_compare());
		};
	};

	//NON-MEMBER FUNCTIONS OVERLOAD
	//https://en.cppreference.com/w/cpp/container/map/operator_cmp
	/*
	** Checks if the contents of lhs and rhs are equal,
	** that is, they have the same number of elements and
	** each element in lhs compares equal with the element
	** in rhs at the same position.
	*/
	template <class Key, class T, class Compare, class Alloc>
	bool	operator==(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
	
		typename map<Key, T, Compare, Alloc>::const_iterator	lit;
		typename map<Key, T, Compare, Alloc>::const_iterator	rit = rhs.begin();
	
		for (lit = lhs.begin(); lit != lhs.end(); lit++) {
			if (*lit != *rit)
				return (false);
			rit++;
		}
		return (true);
	};
	
	//Checks if the contents of lhs and rhs are not equal.
	template <class Key, class T, class Compare, class Alloc>
	bool	operator!=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {
		return (!(rhs == lhs));
	};
	
	//Compares the contents of lhs and rhs lexicographically.
	template <class Key, class T, class Compare, class Alloc>
	bool	operator<(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {
		if ((!lhs.size() && !rhs.size()) || (!rhs.size()))
			return (false);
		if (!lhs.size())
			return (true);
	
		typename map<Key, T, Compare, Alloc>::const_iterator	lit = lhs.begin();
		typename map<Key, T, Compare, Alloc>::const_iterator	rit = rhs.begin();
	
		while ((lit != lhs.end()) && (rit != rhs.end())) {
			if (*lit < *rit)
				return (true);
			else if (*lit > *rit)
				return (false);
			lit++;
			rit++;
		}
		return (lhs.size() < rhs.size() ? true : false);
	};
	
	//Compares the contents of lhs and rhs lexicographically.
	template <class Key, class T, class Compare, class Alloc>
	bool	operator<=( const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs ) {
		return ((lhs < rhs) || (lhs == rhs));
	};
	
	//Compares the contents of lhs and rhs lexicographically.
	template <class Key, class T, class Compare, class Alloc>
	bool	operator>(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {
		return (!(lhs <= rhs));
	};
	
	//Compares the contents of lhs and rhs lexicographically.
	template <class Key, class T, class Compare, class Alloc>
	bool	operator>=(const map<Key, T, Compare, Alloc> &lhs,
		const map<Key, T, Compare, Alloc> &rhs) {
		return (!(lhs < rhs));
	};
	
	/*
	** Specializes the std::swap algorithm for std::list.
	** Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/
	template <class Key, class T, class Compare, class Alloc>
	void	swap(map<Key, T, Compare, Alloc> &lhs,
				 map<Key, T, Compare, Alloc> &rhs) {
		lhs.swap(rhs);
	};

}

#endif
