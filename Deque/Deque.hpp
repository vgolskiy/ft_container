/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@yandex.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 18:37:39 by mskinner          #+#    #+#             */
/*   Updated: 2021/06/04 20:15:59 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Double-ended queue is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end.
** In addition, insertion and deletion at either end of a deque never invalidates pointers or references to the rest of the elements.
** The elements of a deque are not stored contiguously: typical implementations use a sequence of individually allocated fixed-size arrays,
** with additional bookkeeping, which means indexed access to deque must perform two pointer dereferences.
** The storage of a deque is automatically expanded and contracted as needed. Expansion of a deque is cheaper because it does not involve
** copying of the existing elements to a new memory location. On the other hand, deques typically have large minimal memory cost.
** A deque holding just one element has to allocate its full internal array
** (e.g. 8 times the object size on 64-bit libstdc++; 16 times the object size or 4096 bytes, whichever is larger, on 64-bit libc++).
** The complexity (efficiency) of common operations on deques is as follows:
** - Random access - constant O(1)
** - Insertion or removal of elements at the end or beginning - constant O(1)
** - Insertion or removal of elements - linear O(n)
*/

#pragma once

#ifndef _DEQUE_HPP_
# define _DEQUE_HPP_

# include "Iterator.hpp"
# include "Node.hpp"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class deque
	{
	private:
		Node<T>		*_begin;
		Node<T>		*_end;
		Allocator	_allocator;
		std::size_t	_size;

	//https://en.cppreference.com/w/cpp/container/deque
	// Member types
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

	//https://en.cppreference.com/w/cpp/container/deque/deque
	//MEMBER FUNCTIONS
	//Default constructor. Constructs an empty container with a default-constructed allocator.
	deque(void) : _allocator(allocator_type()), _size(0) {};
		
	//Constructs an empty container with the given allocator alloc.
	explicit deque(const allocator_type &allocator) :
		_allocator(allocator), _size(0) {
		_begin = new Node<T>;
		_end = new Node<T>;
		_begin->_next = _end;
		_begin->_previous = _end;
		_end->_previous = _begin;
		_end->_next = _begin;
	};

	//Constructs the container with count copies of elements with value value.
	explicit deque(size_type count, const T &value = T(), const allocator_type &allocator = allocator_type()) :
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
	deque(InputIt first, InputIt last, const allocator_type &allocator = allocator_type()) :
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
	deque(const deque &copy) : _allocator(copy._allocator), _size(0), _capacity(copy.capacity()) {
		_begin = new Node<T>;
		_end = new Node<T>;
		_begin->_next = _end;
		_begin->_previous = _end;
		_end->_previous = _begin;
		_end->_next = _begin;
		assign(copy.begin(), copy.end());
	};

	//Destructor: clears allocator and deletes deque elements
	~deque(void) {
		clear();
		delete _begin;
		delete _end;
	};

	//https://en.cppreference.com/w/cpp/container/deque/operator%3D
	// Copy assignment operator. Replaces the contents with a copy
	// of the contents of other.
	deque&					operator=(const deque &other) {
		_allocator = other._allocator;
		assign(other.begin(), other.end());
		return (*this);
	};

	//https://en.cppreference.com/w/cpp/container/deque/assign
	//Replaces the contents with count copies of value value
	void					assign(size_type count, const_reference value) {
		clear();
		while (count--)
			push_back(value);
	};

	//Replaces the contents with copies of those in the range [first, last)
	template <class InputIt>
	void					assign(InputIt first, InputIt last) {
		InputIt	it;

		clear();
		for (it = first; it != last; ++it)
			push_back(*it);
	};

	// ELEMENT ACCESS
	//https://en.cppreference.com/w/cpp/container/deque/at
	//Returns a reference to the element at specified location pos.
	//If pos is not within the range of the container, std::out_of_range is thrown.
	reference				at(size_type pos) {
		if ((pos >= _size) || (pos < 0))
			throw (std::out_of_range("Position is out of range"));
		return (*(_deque + pos));
	};

	const_reference			at(size_type pos) const {
		if ((pos >= _size) || (pos < 0))
			throw (std::out_of_range("Position is out of range"));
		return (*(_deque + pos));
	};

	//https://en.cppreference.com/w/cpp/container/deque/operator_at
	//Returns a reference to the element at specified location pos.
	//No bounds checking is performed.
	reference				operator[](size_type pos) {
		return (*(_deque + pos));
	};

	const_reference			operator[](size_type pos) const {
		return (*(_deque + pos));
	};
	
	//https://en.cppreference.com/w/cpp/container/deque/front
	/*
	** Returns a reference to the first element in the container.
	** Calling front on an empty container is UB.
	*/
	reference				front(void) {
		return (*_deque);
	};

	const_reference			front(void) const {
		return (*_deque);
	};

	//https://en.cppreference.com/w/cpp/container/deque/back
	/*
	** Returns reference to the last element in the container.
	** Calling front on an empty container is UB.
	*/
	reference				back(void) {
		return (*(_deque + _size - 1));
	};

	const_reference			back(void) const {
		return (*(_deque + _size - 1));
	};

	//ITERATORS METHODS
	//https://en.cppreference.com/w/cpp/container/deque
	iterator				begin(void) {
		return (iterator(_deque));
	};

	iterator				end(void) {
		return (iterator(_deque + _size));
	};

	const_iterator			begin(void) const {
		return (const_iterator(_deque));
	};

	const_iterator			end(void) const {
		return (const_iterator(_deque + _size));
	};

	reverse_iterator		rbegin(void) {
		return (reverse_iterator(_deque + _size - 1));
	};

	reverse_iterator		rend(void) {
		return (reverse_iterator(_deque - 1));
	};

	const_reverse_iterator	rbegin(void) const {
		return (const_reverse_iterator(_deque + _size - 1));
	};

	const_reverse_iterator	rend(void) const {
		return (const_reverse_iterator(_deque - 1));
	};

	// CAPACITY
	//https://en.cppreference.com/w/cpp/container/deque/empty
	// Checks if the underlying container has no elements, i.e. whether begin() == end().
	bool					empty(void) const {
		return (begin() == end());
	};

	//https://en.cppreference.com/w/cpp/container/deque/size
	// Returns the number of elements in the underlying container, i.e. std::distance(begin(), end()).
	size_type				size(void) const {
		return (_size);
	};

	//https://en.cppreference.com/w/cpp/container/deque/max_size
	//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations.
	size_type				max_size(void) const {
		if (typeid(value_type) == typeid('c'))
			return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
		return (std::numeric_limits<size_type>::max() / sizeof(value_type));
	};

	// MODIFIERS
	//https://en.cppreference.com/w/cpp/container/deque/clear
	/*
	** Erases all elements from the container. After this call, size() returns zero.
	** Invalidates any references, pointers, or iterators referring to contained elements.
	** Any past-the-end iterators are also invalidated.
	*/
	void					clear(void) {
		erase(begin(), end());
	};

	//https://en.cppreference.com/w/cpp/container/deque/insert
		iterator				insert(iterator pos, const_reference value) {
			if (pos == end()) {
				push_back(value);
				pos = end();
			}
			else {
				pointer		tmp;
				iterator	it = begin();
				size_type	i = 0;

				while (it != pos) {
					i++;
					it++;
				}
				tmp = new T[_size - i];
				size_type j = 0;
				while (it != end()) {
					tmp[j] = *it;
					it++;
					j++;
				}
				if ((_size + 1) > max_size())
					throw std::length_error("Capacity exeeds limit");
				if ((_size + 1) > _capacity) {
					pointer		new_v;
					size_type	k = 0;;
					
					if (!_capacity)
						new_v = new T[1];
					else if (_capacity * 2 < max_size())
						new_v = new T[_capacity * 2];
					else
						new_v = new T[max_size()];
					while (k < _size) {
						new_v[k] = _vector[k];
						k++;
					}
					if (_capacity)
						delete [] _vector;
					_vector = new_v;
					if (!_capacity)
						_capacity++;
					else if (_capacity * 2 < max_size())
						_capacity *= 2;
					else
						_capacity = max_size();
				}
				_vector[i++] = value;
				pos = iterator(_vector + i);
				j = 0;
				while (i < _size + 1) {
					_vector[i] = tmp[j];
					i++;
					j++;
				}
				_size++;
			}
			return (--pos);
		};




	//https://en.cppreference.com/w/cpp/container/queue/push
	// Pushes the given element value to the top of the queue. Effectively calls c.push_back(value).
		void			push(const value_type &value) {
			_queue.push_back(value);
		};

	//https://en.cppreference.com/w/cpp/container/queue/pop
	// Removes the top element from the queue. Effectively calls c.pop_front()
		void			pop(void) {
			_queue.pop_front();
		};

	private:
		template <class A, class B>
		friend bool	operator==(const queue<A, B> &lhs, const queue<A, B> &rhs);

		template <class A, class B>
		friend bool	operator!=(const queue<A, B> &lhs, const queue<A, B> &rhs);

		template <class A, class B>
		friend bool	operator<(const queue<A, B> &lhs, const queue<A, B> &rhs);

		template <class A, class B>
		friend bool	operator<=(const queue<A, B> &lhs, const queue<A, B> &rhs);

		template <class A, class B>
		friend bool	operator>(const queue<A, B> &lhs, const queue<A, B> &rhs);

		template <class A, class B>
		friend bool	operator>=(const queue<A, B> &lhs, const queue<A, B> &rhs);
	};

	//NON-MEMBER FUNCTIONS OVERLOAD
	//https://en.cppreference.com/w/cpp/container/vector/operator_cmp
	/*
	** Compares the contents of the underlying containers of two container
	** adaptors. The comparison is done by applying the corresponding 
	** operator to the underlying containers.
	*/
	template <typename T, class Container>
	bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs._queue == rhs._queue);
	};

	template <typename T, class Container>
	bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs._queue != rhs._queue);
	};

	template <typename T, class Container>
	bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs._queue > rhs._queue);
	};

	template <typename T, class Container>
	bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs._queue < rhs._queue);
	};

	template <typename T, class Container>
	bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs._queue >= rhs._queue);
	};

	template <typename T, class Container>
	bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs) {
		return (lhs._queue <= rhs._queue);
	};
}

#endif
