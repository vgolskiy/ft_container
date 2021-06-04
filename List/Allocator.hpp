/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:33:07 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/08 13:22:27 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef _ALLOCATOR_HPP_
# define _ALLOCATOR_HPP_

# include "Libraries.hpp"

namespace ft
{
	//https://en.cppreference.com/w/cpp/memory/allocator
	template <typename T>
	class Allocator
	{
	//Member types
	public:
		typedef T											value_type;
		typedef T											&reference;
		typedef T											*pointer;
		typedef const T										&const_reference;
		typedef const T										*const_pointer;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;

		////https://en.cppreference.com/w/cpp/memory/allocator/allocator
		template<typename U>
		struct conv {
			typedef Allocator<U> other;
		};

		Allocator() {};
		~Allocator() {};
	    Allocator(const Allocator &) {};

		template<typename U>
		Allocator(const Allocator<U> &) {};

		//Getting located memory pointers
		pointer			address(reference ref) const {
			return (&ref);
		};
		
		const_pointer	address(const_reference ref) const {
			return (&ref);
		};

		//https://stackoverflow.com/questions/1183700/what-is-the-meaning-of-this-c-error-stdlength-error
		//Allocates n * sizeof(T) bytes of uninitialized storage by calling ::operator new(std::size_t)
		pointer			allocate(size_type cnt, const void * = 0) { 
			if ((cnt * sizeof(T)) > max_size())
				throw std::bad_alloc();
			return (reinterpret_cast<pointer>(::operator new(cnt * sizeof(T)))); 
		};

		/*
		** Deallocates the storage referenced by the pointer p, which must be a pointer obtained by an earlier call to allocate().
		** The argument n must be equal to the first argument of the call to allocate() that originally produced p; otherwise, UB.
		** Calls ::operator delete(void*)
		*/
		void			deallocate(pointer p, size_type) { 
			::operator delete(p); 
		};

		/*
		** Returns the maximum theoretically possible value of n, for which the call allocate(n, 0) could succeed.
		** In most implementations, this returns std::numeric_limits<size_type>::max() / sizeof(value_type).
		*/
		size_type		max_size() const { 
		    return std::numeric_limits<size_type>::max() / sizeof(value_type);
		};

		/*
		** Constructs an object of type T in allocated uninitialized storage pointed to by p, using placement-new
		** Calls new((void *)p) T(val)
		*/
		void			construct(pointer p, const_reference val) {
			new(p) T(val);
		};

		/*
		** Calls the destructor of the object pointed to by p
		** Calls ((T*)p)->~T()
		*/
		void			destroy(pointer p) {
			p->~T();
		};
	};

	/*
	** Compares two default allocators.
	** Since default allocators are stateless, two default allocators are always equal.
	** Always true
	*/ 
	template <class T1, class T2>
	bool			operator==(const Allocator<T1> &lhs, const Allocator<T2> &rhs) {
		(void)lhs;
		(void)rhs;
		return (true);
	};
	//Always false
	template <class T1, class T2>
	bool			operator!=(const Allocator<T1> &lhs, const Allocator<T2> &rhs) {
		(void)lhs;
		(void)rhs;
		return (false);
	};
}

#endif
