/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:22:26 by mskinner          #+#    #+#             */
/*   Updated: 2021/06/04 17:31:07 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _NODE_HPP_
# define _NODE_HPP_

# include "Libraries.hpp"

namespace ft
{
	template < typename T >
	class Node
	{
	public:
		Node	*_previous;
		Node	*_next;
		T		_content;

		Node() : _previous(NULL), _next(NULL), _content() {};
		Node(const T &content) :
			_previous(NULL), _next(NULL), _content(content) {};
		Node(const Node &copy) : 
			_previous(copy._previous), _next(copy._next), _content(copy._content) {};
		~Node() {};
		Node& operator=(const Node &other) {
			if (this != &other) {
				_previous = other._previous;
				_next = other._next;
				_content = other._content;
			}
			return (*this);
		};
	};
};

#endif
