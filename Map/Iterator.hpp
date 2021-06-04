/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:43:11 by mskinner          #+#    #+#             */
/*   Updated: 2021/03/01 02:03:59 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _ITERATOR_HPP_
# define _ITERATOR_HPP_

# include "RBTree.hpp"

namespace ft
{
	template < typename Key, typename T, class Category = bidirectional_iterator_tag >
	class Iterator 
	{
	protected:
		Node<Key, T>	*_root;

	public:
	/*
	** std::iterator_traits<It> should have member typedefs:
	** - value_type,
	** - difference_type,
	** - reference,
	** - pointer,
	** - iterator_category
	*/ 
		typedef std::pair<Key, T>	value_type;
		typedef std::ptrdiff_t		difference_type;
		typedef std::pair<Key, T>	&reference;
		typedef std::pair<Key, T>	*pointer;
		typedef Category			iterator_category;

		//Coplien form
		Iterator(void): _root(NULL) {};
		explicit Iterator(Node<Key, T> *root): _root(root) {};
		Iterator(const Iterator &copy) {
			*this = copy;
		};
		virtual ~Iterator() {};
		Iterator&	operator=(const Iterator &other) {
			_root = other._root;
			return (*this);
		};

		//Returns pointer address
		Node<Key, T>*	get_root(void) const {
			return (_root);
		};

		//Operators
		bool		operator==(const Iterator &other) const {
			return (_root == other._root);
		};

		bool		operator!=(const Iterator &other) const {
			return (_root != other._root);
		};

		reference	operator*(void) const {
			return (_root->_content);
		};

		pointer		operator->(void) const {
			return (&_root->_content);
		};

		//++it
		Iterator&	operator++(void) {
			_root = _root->successor(_root);
			return (*this);
		};

		Iterator&	operator--(void) {
			_root = _root->predecessor(_root);
			return (*this);
		};

		//it++
		Iterator	operator++(int) {
			Iterator	postfix(*this);

			_root = _root->successor(_root);
			return (postfix);
		};

		Iterator	operator--(int) {
			Iterator	postfix(*this);

			_root = _root->predecessor(_root);
			return (postfix);
		};
	};

	template < typename Key, typename T, class Category = bidirectional_iterator_tag >
	class ReverseIterator : public Iterator<Key, T>
	{
	public:
		//Coplien form
		ReverseIterator(void) : Iterator<Key, T>() {};
		explicit ReverseIterator(Node<Key, T> *root): Iterator<Key, T>(root) {};
		ReverseIterator(const ReverseIterator &copy) {
			*this = copy;
		};
		virtual ~ReverseIterator() {};
		ReverseIterator&	operator=(const ReverseIterator &other) {
			Iterator<Key, T>::_root = other._root;
			return (*this);
		};

		//Operators
		//++it
		ReverseIterator&	operator++(void) {
			Iterator<Key, T>::_root =
				Iterator<Key, T>::_root->predecessor(Iterator<Key, T>::_root);
			return (*this);
		};

		ReverseIterator&	operator--(void) {
			Iterator<Key, T>::_root =
				Iterator<Key, T>::_root->successor(Iterator<Key, T>::_root);
			return (*this);
		};

		//it++
		ReverseIterator	operator++(int) {
			ReverseIterator	postfix(*this);

			operator++();
			return (postfix);
		};

		ReverseIterator	operator--(int) {
			ReverseIterator	postfix(*this);

			operator--();
			return (postfix);
		};
	};

	template < typename Key, typename T, class Category = bidirectional_iterator_tag >
	class ConstantIterator : public Iterator<Key, T>
	{
	public:
		typedef const std::pair<Key, T>	&const_reference;
		typedef const std::pair<Key, T>	*const_pointer;

		//Coplien form
		ConstantIterator(void): Iterator<Key, T>() {};
		explicit ConstantIterator(Node<Key, T> *root): Iterator<Key, T>(root) {};
		ConstantIterator(const ConstantIterator &copy) {
			*this = copy;
		};
		virtual ~ConstantIterator() {};
		ConstantIterator&	operator=(const ConstantIterator &other) {
			Iterator<Key, T>::_root = other._root;
			return (*this);
		};

		//Operators
		const_reference		operator*(void) const {
			return (Iterator<Key, T>::_root->_content);
		};

		const_pointer		operator->(void) const {
			return (&Iterator<Key, T>::_root->_content);
		};

		//++it
		ConstantIterator&	operator++(void) {
			Iterator<Key, T>::_root =
				Iterator<Key, T>::_root->successor(Iterator<Key, T>::_root);
			return (*this);
		};

		ConstantIterator&	operator--(void) {
			Iterator<Key, T>::_root->_root = 
				Iterator<Key, T>::_root->predecessor(Iterator<Key, T>::_root);
			return (*this);
		};

		//it++
		ConstantIterator	operator++(int) {
			ConstantIterator	postfix(*this);

			operator++();
			return (postfix);
		};

		ConstantIterator	operator--(int) {
			ConstantIterator	postfix(*this);

			operator--();
			return (postfix);
		};
	};

	template < typename Key, typename T, class Category = bidirectional_iterator_tag >
	class ConstantReverseIterator : public Iterator<Key, T>
	{
	public:
		typedef const std::pair<Key, T>	&const_reference;
		typedef const std::pair<Key, T>	*const_pointer;

		//Coplien form
		ConstantReverseIterator(void): Iterator<Key, T>() {};
		explicit ConstantReverseIterator(Node<Key, T> *root): Iterator<Key, T>(root) {};
		ConstantReverseIterator(const ConstantReverseIterator &copy) {
			*this = copy;
		};
		virtual ~ConstantReverseIterator() {};
		ConstantReverseIterator&	operator=(const ConstantReverseIterator &other) {
			Iterator<Key, T>::_root = other._root;
			return (*this);
		};

		//Operators
		const_reference				operator*(void) const {
			return (Iterator<Key, T>::_root->_content);
		};

		const_pointer				operator->(void) const {
			return (&Iterator<Key, T>::_root->_content);
		};

		//++it
		ConstantReverseIterator&	operator++(void) {
			Iterator<Key, T>::_root =
				Iterator<Key, T>::_root->predecessor(Iterator<Key, T>::_root);
			return (*this);
		};

		ConstantReverseIterator&	operator--(void) {
			Iterator<Key, T>::_root =
				Iterator<Key, T>::_root->successor(Iterator<Key, T>::_root);
			return (*this);
		};

		//it++
		ConstantReverseIterator		operator++(int) {
			ConstantReverseIterator	postfix(*this);

			operator++();
			return (postfix);
		};

		ConstantReverseIterator		operator--(int) {
			ConstantReverseIterator	postfix(*this);

			operator--();
			return (postfix);
		};
	};
};

#endif
