/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:43:11 by mskinner          #+#    #+#             */
/*   Updated: 2021/03/01 01:23:01 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _ITERATOR_HPP_
# define _ITERATOR_HPP_

# include "Node.hpp"

namespace ft
{
	template < typename T, class Category = bidirectional_iterator_tag >
	class Iterator 
	{
	protected:
		Node<T>	*_list;

	public:
	/*
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
		Iterator(void): _list(NULL) {};
		explicit Iterator(Node<T> *list): _list(list) {};
		Iterator(const Iterator &copy) {
			*this = copy;
		};
		virtual ~Iterator() {};
		Iterator&	operator=(const Iterator &other) {
			_list = other._list;
			return (*this);
		};

		//Returns pointer address
		Node<T>*	get_list(void) const {
			return (_list);
		};

		//Operators
		bool		operator==(const Iterator &other) const {
			return (_list == other._list);
		};

		bool		operator!=(const Iterator &other) const {
			return (_list != other._list);
		};

		bool		operator>(const Iterator &other) const {
			return (_list > other._list);
		};

		bool		operator>=(const Iterator &other) const {
			return (!(_list < other._list));
		};

		bool		operator<(const Iterator &other) const {
			return (_list < other._list);
		};

		bool		operator<=(const Iterator &other) const {
			return (!(_list > other._list));
		};

		T&	operator*(void) const {
			return (_list->_content);
		};

		T*	operator->(void) const {
			return (&_list->_content);
		};

		//++it
		Iterator&	operator++(void) {
			_list = _list->_next;
			return (*this);
		};

		Iterator&	operator--(void) {
			_list = _list->_previous;
			return (*this);
		};

		//it++
		Iterator	operator++(int) {
			Iterator	postfix(*this);

			_list = _list->_next;
			return (postfix);
		};

		Iterator	operator--(int) {
			Iterator	postfix(*this);

			_list = _list->_previous;
			return (postfix);
		};
	};

	template < typename T, class Category = bidirectional_iterator_tag >
	class ReverseIterator : public Iterator<T>
	{
	public:
		//Coplien form
		ReverseIterator(void) : Iterator<T>() {};
		explicit ReverseIterator(Node<T> *list): Iterator<T>(list) {};
		ReverseIterator(const ReverseIterator &copy) {
			*this = copy;
		};
		virtual ~ReverseIterator() {};
		ReverseIterator&	operator=(const ReverseIterator &other) {
			Iterator<T>::_list = other._list;
			return (*this);
		};

		//Operators
		//++it
		ReverseIterator&	operator++(void) {
			Iterator<T>::_list = Iterator<T>::_list->_previous;
			return (*this);
		};

		ReverseIterator&	operator--(void) {
			Iterator<T>::_list = Iterator<T>::_list->_next;
			return (*this);
		};

		//it++
		ReverseIterator	operator++(int) {
			ReverseIterator	postfix(*this);

			Iterator<T>::_list = Iterator<T>::_list->_previous;
			return (postfix);
		};

		ReverseIterator	operator--(int) {
			ReverseIterator	postfix(*this);

			Iterator<T>::_list = Iterator<T>::_list->_next;
			return (postfix);
		};
	};

	template < typename T, class Category = bidirectional_iterator_tag >
	class ConstantIterator : public Iterator<T>
	{
	public:
		typedef const T	&const_reference;
		typedef const T	*const_pointer;

		//Coplien form
		ConstantIterator(void): Iterator<T>() {};
		explicit ConstantIterator(Node<T> *list): Iterator<T>(list) {};
		ConstantIterator(const ConstantIterator &copy) {
			*this = copy;
		};
		virtual ~ConstantIterator() {};
		ConstantIterator&	operator=(const ConstantIterator &other) {
			Iterator<T>::_list = other._list;
			return (*this);
		};

		//Operators
		const_reference		operator*(void) const {
			return (Iterator<T>::_list->_content);
		};

		const_pointer		operator->(void) const {
			return (&Iterator<T>::_list->_content);
		};

		//++it
		ConstantIterator&	operator++(void) {
			Iterator<T>::_list = Iterator<T>::_list->_next;
			return (*this);
		};

		ConstantIterator&	operator--(void) {
			Iterator<T>::_list = Iterator<T>::_list->_previous;
			return (*this);
		};

		//it++
		ConstantIterator	operator++(int) {
			ConstantIterator	postfix(*this);

			Iterator<T>::_list = Iterator<T>::_list->_next;
			return (postfix);
		};

		ConstantIterator	operator--(int) {
			ConstantIterator	postfix(*this);

			Iterator<T>::_list = Iterator<T>::_list->_previous;
			return (postfix);
		};
	};

	template < typename T, class Category = bidirectional_iterator_tag >
	class ConstantReverseIterator : public Iterator<T>
	{
	public:
		typedef const T	&const_reference;
		typedef const T	*const_pointer;

		//Coplien form
		ConstantReverseIterator(void): Iterator<T>() {};
		explicit ConstantReverseIterator(Node<T> *list): Iterator<T>(list) {};
		ConstantReverseIterator(const ConstantReverseIterator &copy) {
			*this = copy;
		};
		virtual ~ConstantReverseIterator() {};
		ConstantReverseIterator&	operator=(const ConstantReverseIterator &other) {
			Iterator<T>::_list = other._list;
			return (*this);
		};

		//Operators
		const_reference				operator*(void) const {
			return (Iterator<T>::_list->_content);
		};

		const_pointer				operator->(void) const {
			return (&Iterator<T>::_list->_content);
		};

		//++it
		ConstantReverseIterator&	operator++(void) {
			Iterator<T>::_list = Iterator<T>::_list->_previous;
			return (*this);
		};

		ConstantReverseIterator&	operator--(void) {
			Iterator<T>::_list = Iterator<T>::_list->_next;
			return (*this);
		};

		//it++
		ConstantReverseIterator		operator++(int) {
			ConstantReverseIterator	postfix(*this);

			Iterator<T>::_list = Iterator<T>::_list->_previous;
			return (postfix);
		};

		ConstantReverseIterator		operator--(int) {
			ConstantReverseIterator	postfix(*this);

			Iterator<T>::_list = Iterator<T>::_list->_next;
			return (postfix);
		};
	};
};

#endif
