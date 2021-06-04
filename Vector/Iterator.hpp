/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:43:11 by mskinner          #+#    #+#             */
/*   Updated: 2021/03/01 00:55:39 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _ITERATOR_HPP_
# define _ITERATOR_HPP_

# include "Libraries.hpp"

namespace ft
{
	template < typename T, class Category = random_access_iterator_tag >
	class Iterator 
	{
	protected:
		T		*_vector;

	public:
	/*
	** https://en.cppreference.com/w/cpp/iterator/iterator_traits
	** std::iterator_traits<It> should have member typedefs:
	** - value_type,
	** - difference_type,
	** - reference,
	** - pointer,
	** - iterator_category
	*/ 
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T				&reference;
		typedef T				*pointer;
		typedef Category		iterator_category;

		//Coplien form
		Iterator(void): _vector(NULL) {};
		explicit Iterator(pointer vector): _vector(vector) {};
		Iterator(const Iterator &copy) {
			*this = copy;
		};
		virtual ~Iterator() {};
		Iterator&	operator=(const Iterator &other) {
			_vector = other._vector;
			return (*this);
		};

		//Returns pointer address
		T*	get_vector(void) const {
			return (_vector);
		};

		//Operators
		bool		operator==(const Iterator &other) const {
			return (_vector == other._vector);
		};

		bool		operator!=(const Iterator &other) const {
			return (_vector != other._vector);
		};

		bool		operator>(const Iterator &other) const {
			return (_vector > other._vector);
		};

		bool		operator>=(const Iterator &other) const {
			return (!(_vector < other._vector));
		};
		
		bool		operator<=(const Iterator &other) const {
			return (!(_vector > other._vector));
		};

		bool		operator<(const Iterator &other) const {
			return (_vector < other._vector);
		};

		T&			operator*(void) {
			return (*_vector);
		};

		T*			operator->(void) {
			return (_vector);
		};

		//++it
		Iterator&	operator++(void) {
			_vector++;
			return (*this);
		};

		Iterator&	operator--(void) {
			_vector--;
			return (*this);
		};

		//it++
		Iterator	operator++(int) {
			Iterator	postfix(*this);

			_vector++;
			return (postfix);
		};

		Iterator	operator--(int) {
			Iterator	postfix(*this);

			_vector--;
			return (postfix);
		};

		Iterator&	operator+=(int n) {
			while (n < 0) {
				operator--();
				n++;
			}
			while (n > 0) {
				operator++();
				n--;
			}
			return (*this);
		};

		Iterator	operator+(int n) const {
			return (Iterator(_vector + n));
		};

		Iterator&	operator-=(int n) {
			while (n-- > 0)
				operator--();
			while (n++ < 0)
				operator++();
			return (*this);
		};

		Iterator	operator-(int n) const {
			return (Iterator(_vector - n));
		};
		
		T&			operator[](int n) const {
			return (*(_vector + n));
		};
	};

	template < typename T, class Category = random_access_iterator_tag >
	class ReverseIterator : public Iterator<T>
	{
	public:
		//Coplien form
		ReverseIterator(void) : Iterator<T>() {};
		explicit ReverseIterator(T *vector): Iterator<T>(vector) {};
		ReverseIterator(const ReverseIterator &copy) {
			*this = copy;
		};
		virtual ~ReverseIterator() {};
		ReverseIterator&	operator=(const ReverseIterator &other) {
			Iterator<T>::_vector = other._vector;
			return (*this);
		};

		//Operators
		//++it
		ReverseIterator&	operator++(void) {
			Iterator<T>::_vector--;
			return (*this);
		};

		ReverseIterator&	operator--(void) {
			Iterator<T>::_vector++;
			return (*this);
		};

		//it++
		ReverseIterator		operator++(int) {
			ReverseIterator	postfix(*this);

			Iterator<T>::_vector--;
			return (postfix);
		};

		ReverseIterator		operator--(int) {
			ReverseIterator	postfix(*this);

			Iterator<T>::_vector++;
			return (postfix);
		};

		ReverseIterator&	operator+=(int n) {
			while (n++ < 0)
				operator++();
			while (n-- > 0)
				operator--();
			return (*this);
		};

		ReverseIterator		operator+(int n) const {
			return (ReverseIterator(Iterator<T>::_vector - n));
		};

		ReverseIterator&	operator-=(int n) {
			while (n-- > 0)
				operator++();
			while (n++ < 0)
				operator--();
			return (*this);
		};

		ReverseIterator		operator-(int n) const {
			return (ReverseIterator(Iterator<T>::_vector + n));
		};
	};

	template <typename T, class Category = random_access_iterator_tag>
	class ConstantIterator : public Iterator<T>
	{
	public:
		typedef const T	&const_reference;
		typedef const T	*const_pointer;

		//Coplien form
		ConstantIterator(void): Iterator<T>() {};
		explicit ConstantIterator(T *vector): Iterator<T>(vector) {};
		ConstantIterator(const ConstantIterator &copy) {
			*this = copy;
		};
		virtual ~ConstantIterator() {};
		ConstantIterator&	operator=(const ConstantIterator &other) {
			Iterator<T>::_vector = other._vector;
			return (*this);
		};

		//Operators
		const_reference		operator*(void) {
			return (*Iterator<T>::_vector);
		};

		const_pointer		operator->(void) {
			return (Iterator<T>::_vector);
		};

		//++it
		ConstantIterator&	operator++(void) {
			Iterator<T>::_vector++;
			return (*this);
		};

		ConstantIterator&	operator--(void) {
			Iterator<T>::_vector--;
			return (*this);
		};

		//it++
		ConstantIterator	operator++(int) {
			ConstantIterator	postfix(*this);

			Iterator<T>::_vector++;
			return (postfix);
		};

		ConstantIterator	operator--(int) {
			ConstantIterator	postfix(*this);

			Iterator<T>::_vector--;
			return (postfix);
		};

		ConstantIterator&	operator+=(int n) {
			while (n < 0) {
				operator--();
				n++;
			}
			while (n > 0) {
				operator++();
				n--;
			}
			return (*this);
		};

		ConstantIterator	operator+(int n) const {
			return (ConstantIterator(Iterator<T>::_vector + n));
		};

		ConstantIterator&	operator-=(int n) {
			while (n-- > 0)
				operator--();
			while (n++ < 0)
				operator++();
			return (*this);
		};

		ConstantIterator	operator-(int n) const {
			return (ConstantIterator(Iterator<T>::_vector - n));
		};
	};

	template < typename T, class Category = random_access_iterator_tag >
	class ConstantReverseIterator : public Iterator<T>
	{
	public:
		typedef const T	&const_reference;
		typedef const T	*const_pointer;

		//Coplien form
		ConstantReverseIterator(void): Iterator<T>() {};
		explicit ConstantReverseIterator(T *vector): Iterator<T>(vector) {};
		ConstantReverseIterator(const ConstantReverseIterator &copy) {
			*this = copy;
		};
		virtual ~ConstantReverseIterator() {};
		ConstantReverseIterator&	operator=(const ConstantReverseIterator &other) {
			Iterator<T>::_vector = other._vector;
			return (*this);
		};

		//Operators
		const_reference				operator*(void) {
			return (*Iterator<T>::_vector);
		};

		const_pointer				operator->(void) {
			return (Iterator<T>::_vector);
		};

		//++it
		ConstantReverseIterator&	operator++(void) {
			Iterator<T>::_vector--;
			return (*this);
		};

		ConstantReverseIterator&	operator--(void) {
			Iterator<T>::_vector++;
			return (*this);
		};

		//it++
		ConstantReverseIterator		operator++(int) {
			ConstantReverseIterator	postfix(*this);

			Iterator<T>::_vector--;
			return (postfix);
		};

		ConstantReverseIterator		operator--(int) {
			ConstantReverseIterator	postfix(*this);

			Iterator<T>::_vector++;
			return (postfix);
		};

		ConstantReverseIterator		operator+(int n) const {
			return (ConstantReverseIterator(Iterator<T>::_vector - n));
		};

		ConstantReverseIterator&	operator-=(int n) {
			while (n-- > 0)
				operator++();
			while (n++ < 0)
				operator--();
			return (*this);
		};

		ConstantReverseIterator		operator-(int n) const {
			return (ConstantReverseIterator(Iterator<T>::_vector + n));
		};
	};
};

#endif
