/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:42:39 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/28 21:09:56 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The queue class is a container adapter that gives the programmer
** the functionality of a queue - specifically, a FIFO (first-in, first-out)
** data structure.
** The class template acts as a wrapper to the underlying container - 
** only a specific set of functions is provided. The queue pushes 
** the elements on the back of the underlying container and pops them 
** from the front.
*/

#pragma once

#ifndef _QUEUE_HPP_
# define _QUEUE_HPP_

# include "../List/List.hpp"

namespace ft
{
	template <typename T, class Container = ft::list<T> >
	class queue
	{
	private:
		Container	_queue;

	//https://en.cppreference.com/w/cpp/container/queue
	// Member types
	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	//https://en.cppreference.com/w/cpp/container/queue/queue
	// Default constructor. Value-initializes the container.
		explicit queue(const Container &cont = Container()) : _queue(cont) {};

	// Copy constructor. The adaptor is copy-constructed with the contents of other.c.
		queue(const queue &copy) : _queue(copy._queue) {};

	//https://en.cppreference.com/w/cpp/container/queue/%7Equeue
	/*
	** Destructs the queue. The destructors of the elements are called
	** and the used storage is deallocated.
	** Note, that if the elements are pointers, the pointed-to objects
	** are not destroyed.
	*/
		~queue(void) {};

	//https://en.cppreference.com/w/cpp/container/queue/operator%3D
	// Copy assignment operator. Replaces the contents with a copy
	// of the contents of other. Effectively calls c = other.c
		queue&			operator=(const queue &other) {
			if (this != &other)
				_queue = other._queue;
			return (*this);
		};

	// ELEMENT ACCESS
	//https://en.cppreference.com/w/cpp/container/queue/front
	/*
	** Returns reference to the first element in the queue.
	** This element will be the first element to be removed
	** on a call to pop(). Effectively calls c.front().
	*/
		reference		front(void) {
			return (_queue.front());
		};

		const_reference	front(void) const {
			return (_queue.front());
		};

	//https://en.cppreference.com/w/cpp/container/queue/back
	/*
	** Returns reference to the last element in the queue.
	** This is the most recently pushed element.
	** Effectively calls c.back().
	*/

		reference		back(void) {
			return (_queue.back());
		};

		const_reference	back(void) const {
			return (_queue.back());
		};
	
	// CAPACITY
	//https://en.cppreference.com/w/cpp/container/queue/empty
	// Checks if the underlying container has no elements, i.e. whether c.empty().
		bool			empty(void) const {
			return (_queue.empty());
		};

	//https://en.cppreference.com/w/cpp/container/queue/size
	// Returns the number of elements in the underlying container, that is, c.size().
		size_type		size(void) const {
			return (_queue.size());
		};

	// MODIFIERS
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
