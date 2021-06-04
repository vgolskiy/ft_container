/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 16:26:56 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/28 20:29:22 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The stack class is a container adapter that gives the programmer
** the functionality of a stack - specifically, a LIFO (last-in, first-out) data structure.
** The class template acts as a wrapper to the underlying container - only
** a specific set of functions is provided. The stack pushes and pops the
** element from the back of the underlying container, known as the top of the stack.
*/

#pragma once

#ifndef _STACK_HPP_
# define _STACK_HPP_

# include "../Vector/Vector.hpp"

namespace ft
{
	template <typename T, class Container = ft::vector<T> >
	class stack
	{
	private:
		Container	_stack;

	//https://en.cppreference.com/w/cpp/container/stack
	// Member types
	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	//https://en.cppreference.com/w/cpp/container/stack/stack
	// MEMBER FUNCTIONS
	// Default constructor. Value-initializes the container.
		explicit stack(const Container &cont = Container()) : _stack(cont) {};

	// Copy constructor. The adaptor is copy-constructed with the contents of other.c.
		stack(const stack &copy) : _stack(copy._stack) {};
	
	//https://en.cppreference.com/w/cpp/container/stack/%7Estack
	/*
	** Destructs the stack. The destructors of the elements are called
	** and the used storage is deallocated.
	** Note, that if the elements are pointers, the pointed-to objects
	** are not destroyed.
	*/
		~stack(void) {};

	//https://en.cppreference.com/w/cpp/container/stack/operator%3D
	// Copy assignment operator. Replaces the contents with a copy
	// of the contents of other. Effectively calls c = other.c
		stack&			operator=(const stack &other) {
			if (this != &other)
				_stack = other._stack;
			return (*this);
		};

	// ELEMENT ACCESS
	//https://en.cppreference.com/w/cpp/container/stack/top
	/*
	** Returns reference to the top element in the stack. 
	** This is the most recently pushed element. This element
	** will be removed on a call to pop(). Effectively calls c.back().
	*/
		reference		top(void) {
			return (_stack.back());
		};

		const_reference	top(void) const {
			return (_stack.back());
		};
	
	// CAPACITY
	//https://en.cppreference.com/w/cpp/container/stack/empty
	// Checks if the underlying container has no elements, i.e. whether c.empty().
		bool			empty(void) const {
			return (_stack.empty());
		};

	//https://en.cppreference.com/w/cpp/container/stack/size
	// Returns the number of elements in the underlying container, that is, c.size().
		size_type		size(void) const {
			return (_stack.size());
		};

	// MODIFIERS
	//https://en.cppreference.com/w/cpp/container/stack/push
	// Pushes the given element value to the top of the stack. Effectively calls c.push_back(value).
		void			push(const value_type &value) {
			_stack.push_back(value);
		};

	//https://en.cppreference.com/w/cpp/container/stack/pop
	// Removes the top element from the stack. Effectively calls c.pop_back()
		void			pop(void) {
			_stack.pop_back();
		};

	private:
		template <class A, class B>
		friend bool	operator==(const stack<A, B> &lhs, const stack<A, B> &rhs);

		template <class A, class B>
		friend bool	operator!=(const stack<A, B> &lhs, const stack<A, B> &rhs);

		template <class A, class B>
		friend bool	operator<(const stack<A, B> &lhs, const stack<A, B> &rhs);

		template <class A, class B>
		friend bool	operator<=(const stack<A, B> &lhs, const stack<A, B> &rhs);

		template <class A, class B>
		friend bool	operator>(const stack<A, B> &lhs, const stack<A, B> &rhs);

		template <class A, class B>
		friend bool	operator>=(const stack<A, B> &lhs, const stack<A, B> &rhs);
	};

	//NON-MEMBER FUNCTIONS OVERLOAD
	//https://en.cppreference.com/w/cpp/container/vector/operator_cmp
	/*
	** Compares the contents of the underlying containers of two container
	** adaptors. The comparison is done by applying the corresponding 
	** operator to the underlying containers.
	*/
	template <typename T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs._stack == rhs._stack);
	};

	template <typename T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs._stack != rhs._stack);
	};

	template <typename T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs._stack > rhs._stack);
	};

	template <typename T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs._stack < rhs._stack);
	};

	template <typename T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs._stack >= rhs._stack);
	};

	template <typename T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
		return (lhs._stack <= rhs._stack);
	};
};

#endif
