/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   List.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:10:54 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/04 13:07:59 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Lists are sequence containers (linked elements):
** + constant time insert and erase operations anywhere within the sequence,
** + iteration in both directions (doubly-linked),
** + perform better in inserting, extracting and moving elements in any position within the container,
** + faster sorting algorithms;
** - lack direct access to the elements by their position (linear time ietration),
** - consume some extra memory to keep the linking information associated to each element.
*/

#pragma once

#ifndef _LIST_HPP_
# define _LIST_HPP_

# include "Node.hpp"
# include "Iterator.hpp"
# include "Allocator.hpp"

namespace ft
{
	template <typename T, class Allocator = ft::Allocator<T> >
	class List
	{
	private:
		Node<T>		*_begin;
		Node<T>		*_end;
		Allocator	_allocator;
		std::size_t	_size;

		void	swap_element(T &x, T &y) {
			T	tmp;

			tmp = x;
			x = y;
			y = tmp;
		};

	//https://en.cppreference.com/w/cpp/container/list
	//Member types
	public:
		typedef T											value_type;
		typedef T											&reference;
		typedef T											*pointer;
		typedef std::size_t									size_type;
		typedef const T										&const_reference;
		typedef const T										*const_pointer;
		typedef Allocator									allocator_type;
		typedef ft::Iterator<T>								iterator;
		typedef ft::ReverseIterator<T>						reverse_iterator;
		typedef ft::ConstantIterator<T>						const_iterator;
		typedef ft::ConstantReverseIterator<T>				const_reverse_iterator;
		typedef typename ft::Iterator<T>::difference_type	difference_type;

		//https://en.cppreference.com/w/cpp/container/list/list
		//MEMBER FUNCTIONS
		//Default constructor. Constructs an empty container with a default-constructed allocator.
		List(void) : _allocator(allocator_type()), _size(0) {
			_begin = new Node<T>;
			_end = new Node<T>;
			_begin->_next = _end;
			_begin->_previous = _end;
			_end->_previous = _begin;
			_end->_next = _begin;
		};
		
		//Constructs an empty container with the given allocator alloc.
		explicit List(const allocator_type &allocator) :
			_allocator(allocator), _size(0) {
				_begin = new Node<T>;
				_end = new Node<T>;
				_begin->_next = _end;
				_begin->_previous = _end;
				_end->_previous = _begin;
				_end->_next = _begin;
		};

		//Constructs the container with count copies of elements with value value.
		explicit List(size_type count, const_reference value = T(), const allocator_type &allocator = allocator_type()) :
			_allocator(allocator), _size(0) {
				_begin = new Node<T>;
				_end = new Node<T>;
				_begin->_next = _end;
				_begin->_previous = _end;
				_end->_previous = _begin;
				_end->_next = _begin;
				while (count--)
					push_back(value);
		};

		//Constructs the container with the contents of the range [first, last).
		template <class InputIt>
		List(InputIt first, InputIt last, const allocator_type &allocator = allocator_type()) :
			_allocator(allocator), _size(0) {
				_begin = new Node<T>;
				_end = new Node<T>;
				_begin->_next = _end;
				_begin->_previous = _end;
				_end->_previous = _begin;
				_end->_next = _begin;
				assign<InputIt>(first, last);
		};

		//Copy constructor. Constructs the container with the copy of the contents of other
		List(const List &copy) : _allocator(copy._allocator), _size(0) {
			_begin = new Node<T>;
			_end = new Node<T>;
			_begin->_next = _end;
			_begin->_previous = _end;
			_end->_previous = _begin;
			_end->_next = _begin;
			assign(copy.begin(), copy.end());
		};

		//Destructor: clears allocator and deletes list elements
		~List(void) {
			clear();
			delete _begin;
			delete _end;
		};

		//https://en.cppreference.com/w/cpp/container/list
		//Replaces content of one container to another
		List&					operator=(const List &other) {
			_allocator = other._allocator;
			assign(other.begin(), other.end());
			return (*this);
		};

		//Replaces the contents with count copies of value
		void					assign(size_type count, const_reference value) {
			clear();
			while (count--)
				push_back(value);
		};

		//Replaces the contents with count copies of value (in case of problems with size_t)
		void					assign(int count, const_reference value) {
			if (count > 0) {
				clear();
				while (count--)
					push_back(value);
			}
		};

		//Replaces the contents with copies of those in the range [first, last)
		template <class InputIt>
		void					assign(InputIt first, InputIt last) {
			InputIt	it;

			clear();
			for (it = first; it != last; ++it)
				push_back(*it);
		};


		//https://en.cppreference.com/w/cpp/container/list
		//ELEMENT ACCESS METHODS
		reference				front(void) {
			return (_begin->_next->_content);
		};

		const_reference			front(void) const {
			return (_begin->_next->_content);
		};

		reference				back(void) {
			return (_end->_previous->_content);
		};

		const_reference			back(void) const {
			return (_end->_previous->_content);
		};

		//https://en.cppreference.com/w/cpp/header/list
		//https://en.cppreference.com/w/cpp/container/list
		//ITERATORS METHODS
		iterator				begin(void) {
			return (iterator(_begin->_next));
		};

		iterator				end(void) {
			return (iterator(_end));
		};

		const_iterator			begin(void) const {
			return (const_iterator(_begin->_next));
		};

		const_iterator			end(void) const {
			return (const_iterator(_end));
		};

		reverse_iterator		rbegin(void) {
			return (reverse_iterator(_end->_previous));
		};

		reverse_iterator		rend(void) {
			return (reverse_iterator(_begin));
		};

		const_reverse_iterator	rbegin(void) const {
			return (const_reverse_iterator(_end->_previous));
		};

		const_reverse_iterator	rend(void) const {
			return (const_reverse_iterator(_begin));
		};

		//https://en.cppreference.com/w/cpp/container/list
		//CAPACITY: getting container size
		bool					empty(void) const {
			return (_size == 0);
		};

		size_type				size(void) const {
			return (_size);
		};

		//https://en.cppreference.com/w/cpp/container/list/max_size
		size_type				max_size(void) const {
			return (std::numeric_limits<size_type>::max() / sizeof(Node<T>));
		};

		//https://en.cppreference.com/w/cpp/container/list
		//MODIFIERS: work with container elements
		void					clear(void) {
			while (_size)
				pop_back();
		};

		//Inserts value before pos
		iterator				insert(iterator pos, const_reference value) {
			if (pos == begin()) {
				push_front(value);
				return (pos);
			}
			else if (pos == end()) {
				push_back(value);
				return (pos);
			}
			else {
				Node<T>	*add = new Node<T>(value);
				Node<T>	*old = pos.get_list();

				//Splitting old list to 2 parts and inserting new list element
				if (old->_previous) {
					add->_previous = old->_previous;
					old->_previous->_next = add;
				}
				add->_next = old;
				old->_previous = add;
				_size++;
				return (--pos);
			}
		};

		//Inserts value before pos
		void					insert(iterator pos, size_type count, const_reference value) {
			while (count--)
				insert(pos, value);
		};

		void					insert(iterator pos, int count, const_reference value) {
			if (count > 0)
				while (count--)
					insert(pos, value);
		};

		//Inserts elements from range [first, last) before pos.
		template <class InputIt>
		void					insert(iterator pos, InputIt first, InputIt last) {
			InputIt	it;
			
			for (it = first; it != last; ++it)
				insert(pos, *it);
		};

		//Removes the element at pos (the end() iterator cannot be used as a value for pos)
		iterator				erase(iterator pos) {
			Node<T> *next = pos.get_list()->_next;
			Node<T> *prev = pos.get_list()->_previous;

			next->_previous = prev;
			prev->_next = next;
			delete pos.get_list();
			_size--;
			return (iterator(next));
		};

		//Removes the elements in the range [first, last).
		iterator				erase(iterator first, iterator last) {
			iterator	it;
			
			for (it = first; it != last; ++it)
				erase(it);
			if (last == end())
				return (iterator(_end));
			return (last);
		};

		//Appends the given element value to the end of the container.
		void					push_back(const_reference value) {
			Node<T>	*add = new Node<T>(value);

			add->_next = _end;
			add->_previous = _end->_previous;
			_end->_previous->_next = add;
			_end->_previous = add;
			_size++;
		};

		//Removes the last element of the container. UB on empty list
		void					pop_back(void) {
			if (_size) {
				Node<T>	*old = _end->_previous;

				_end->_previous->_previous->_next = _end;
				_end->_previous = _end->_previous->_previous;
				delete old;
				_size--;
			}
		};

		//Prepends the given element value to the beginning of the container.
		void					push_front(const_reference value) {
			Node<T>	*add = new Node<T>(value);

			add->_next = _begin->_next;
			add->_previous = _begin;
			_begin->_next->_previous = add;
			_begin->_next = add;
			_size++;
		};

		//Removes the first element of the container. UB on empty list
		void					pop_front(void) {
			if (_size) {
				Node<T> *old = _begin->_next;

				_begin->_next->_next->_previous = _begin;
				_begin->_next = _begin->_next->_next;
				delete old;
				_size--;
			}
		};

		/*
		** Resizes the container to contain count elements.
		** If the current size is greater than count, the container is reduced to its first count elements.
		** If the current size is less than count,
		** 1) additional default-inserted elements are appended
		** 2) additional copies of value are appended.
		*/
		void					resize(size_type count, value_type value = T()) {
			while (_size > count)
				pop_back();
			while (_size < count)
				push_back(value);
		};

		//Exchanges the contents of the container with those of other.
		//Does not invoke any move, copy, or swap operations on individual elements.
		void					swap(List &other) {
			List<T>	tmp;

			tmp = *this;
			*this = other;
			other = tmp;
		};

		//https://en.cppreference.com/w/cpp/container/list
		//OPERATIONS
		/*
		** Merges two sorted lists into one.
		** The lists should be sorted into ascending order.
		** No elements are copied. 
		** The container other becomes empty after the operation.
		** The function does nothing if other refers to the same object as *this.
		*/
		void					merge(List &other) {
			if ((this != &other) && (!other.empty())) {
				iterator	it = begin();
				iterator	ito = other.begin();

				while (ito != other.end()) {
					while ((it != end()) && (*it < *ito))
						it++;
					if (it != end())
						splice(it, other, ito);
					else
					{
						push_back(*ito);
						other.erase(ito);
					}
					ito++;
				}
			}
		};

		//Comp - comparison function object which returns ​true if the first argument is less than (i.e. is ordered before) the second. 
		template <class Compare> 
		void					merge(List &other, Compare comp) {
			if ((this != &other) && (!other.empty())) {
				iterator	it = begin();
				iterator	ito = other.begin();

				while (ito != other.end()) {
					while ((it != end()) && (comp(*it, *ito)))
						it++;
					if (it != end())
						splice(it, other, ito);
					else
					{
						push_back(*ito);
						other.erase(ito);
					}
					ito++;
				}
			}
		};

		/*
		** Transfers all elements from other into *this. 
		** The elements are inserted before the element pointed to by pos. 
		** The container other becomes empty after the operation.
		** UB if other refers to the same object as *this.
		*/
		void					splice(iterator pos, List &other) {
			insert(pos, other.begin(), other.end());
			other.clear();
		};

		//Transfers the element pointed to by it from other into *this before the *this element pointed to by pos.
		void					splice(iterator pos, List &other, iterator it) {
			insert(pos, *it);
			other.erase(it);
		};

		/*
		** Transfers the elements in the range [first, last) from other into *this.
		** The elements are inserted before the element pointed to by pos.
		** UB if pos is an iterator in the range [first,last).
		*/
		template <class InputIt>
		void					splice(iterator pos, List &other,
            InputIt first, InputIt last) {
			insert<InputIt>(pos, first, last);
			other.erase(first, last);
		};

		//Removes all elements that are equal to value.
		void					remove(const_reference value) {
			if (_size) {
				iterator	it;

                for (it = begin(); it != end(); ++it) {
					if (*it == value)
						erase(it);
                }
			}
		};

		//Removes all elements for which predicate p returns true.
		template <class UnaryPredicate>
		void					remove_if(UnaryPredicate p) {
			if (_size) {
				iterator	it;

				for (it = begin(); it != end(); ++it)
					if (p(*it))
						erase(it);
			}			
		};

		//Reverses the order of the elements in the container.
		void					reverse(void) {
			if (_size > 1) {
                size_type        count = _size;
				reverse_iterator it;
                for (it = rbegin(); it != rend(); ++it)
                    push_back(*it);
                while (count--)
                    pop_front();
			}
		};

		/*
		** Removes all consecutive duplicate elements from the container.
		** Only the first element in each group of equal elements is left.
		** Uses operator== to compare the elements.
		** List should be sorted in case you need pure unique elements!
		*/
		void					unique(void) {
			if (_size > 1) {
				iterator	it = begin();
				iterator	tmp = begin();

				tmp = it + 1;
				while ((tmp != end()) && (it != end())) {
					if (*tmp == *it)
						tmp = erase(tmp);
					else {
						tmp++;
						it++;
					}
				}
			}
		};

		/*
		** Removes all consecutive duplicate elements from the container. 
		** Only the first element in each group of equal elements is left.
		** Uses the given binary predicate p to compare the elements.
		*/
		template <class BinaryPredicate>
		void					unique(BinaryPredicate p) {
			if (_size > 1) {
				iterator	it = begin();
				iterator	tmp = begin() + 1;

				while (it != end()) {
					while (tmp != end()) {
						if (p(*tmp, *it))
							tmp = erase(tmp);
						else
							tmp++;
					}
					it++;
				}
			}		
		};

		/*
		** Sorts the elements in ascending order.
		** The order of equal elements is preserved.
		** Uses operator< to compare the elements.
		*/
		void					sort(void) {
			if (_size > 1) {
				iterator	it;
				iterator	tmp;

				for (it = begin(); it != end(); ++it) {
					for (tmp = it; tmp != end(); ++tmp) {
						if (*tmp < *it)
							swap_element(*it, *tmp);
					}
				}
			}
		};

		/*
		** Sorts the elements in ascending order.
		** The order of equal elements is preserved.
		** Uses the given comparison function comp.
		*/
		template <class Compare> 
		void					sort(Compare comp) {
			if (_size > 1) {
				iterator	it;
				iterator	tmp;

				for (it = begin(); it != end(); ++it) {
					for (tmp = it; tmp != end(); ++tmp) {
						if (comp(*tmp, *it))
							swap_element(*it, *tmp);
					}
				}
			}
		};
	};

	//https://en.cppreference.com/w/cpp/container/list/operator_cmp
	//NON-MEMBER FUNCTIONS OVERLOAD
	/*
	** Checks if the contents of lhs and rhs are equal,
	** that is, they have the same number of elements and 
	** each element in lhs compares equal with the element
	** in rhs at the same position.
	*/
	template <class T, class Alloc>
	bool	operator==(const List<T, Alloc> &lhs,
        const List<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);

		typename List<T, Alloc>::const_iterator	lit;
		typename List<T, Alloc>::const_iterator	rit = rhs.begin();

		for (lit = lhs.begin(); lit != lhs.end(); lit++) {
			if (*lit != *rit)
				return (false);
			rit++;
		}
		return (true);
	};

	//Checks if the contents of lhs and rhs are not equal.
	template <class T, class Alloc>
	bool	operator!=(const List<T, Alloc> &lhs,
        const List<T, Alloc> &rhs) {
		return (!(rhs == lhs));
	};

	//Compares the contents of lhs and rhs lexicographically.
	template <class T, class Alloc>
	bool	operator<(const List<T, Alloc> &lhs,
    	const List<T, Alloc> &rhs) {
		if ((!lhs.size() && !rhs.size()) || (!rhs.size()))
			return (false);
		if (!lhs.size())
			return (true);

		typename List<T, Alloc>::const_iterator	lit = lhs.begin();
		typename List<T, Alloc>::const_iterator	rit = rhs.begin();

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
	template <class T, class Alloc>
	bool	operator<=( const List<T, Alloc> &lhs,
        const List<T, Alloc> &rhs ) {
		return ((lhs < rhs) || (lhs == rhs));
	};

	//Compares the contents of lhs and rhs lexicographically.
	template <class T, class Alloc>
	bool	operator>(const List<T, Alloc> &lhs,
        const List<T, Alloc> &rhs) {
		return (!(lhs <= rhs));
	};

	//Compares the contents of lhs and rhs lexicographically.
	template <class T, class Alloc>
	bool	operator>=(const List<T, Alloc> &lhs,
        const List<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	};

	/*
	** Specializes the std::swap algorithm for std::list. 
	** Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/
	template <class T, class Alloc>
	void	swap(List<T, Alloc> &lhs, 
        List<T, Alloc> &rhs) {
		lhs.swap(rhs);
	};
};

#endif
