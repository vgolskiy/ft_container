/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskinner <v.golskiy@ya.ru>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:19:34 by mskinner          #+#    #+#             */
/*   Updated: 2021/02/24 14:33:59 by mskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Vectors are sequence containers (arrays that can change in size):
** + contiguous storage locations for their elements (can be accessed using offsets on regular
** pointers to its elements),
** + size can change dynamically, with their storage being handled automatically by the container,
** - memory relocation is a relatively expensive task in terms of processing time,
** - vector containers may allocate some extra storage to accommodate for possible growth,
**
** Compared to the other dynamic sequence containers (deques, lists, vectors are very
** efficient accessing its elements (just like arrays) and relatively efficient adding
** or removing elements from its end. For operations that involve inserting or removing
** elements at positions other than the end, they perform worse than the others, and have
** less consistent iterators and references than lists.
*/

#pragma once

#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

# include "Iterator.hpp"

namespace ft
{
	template <typename T>
	void	swap_element(T &x, T &y) {
		T	tmp;
	
		tmp = x;
		x = y;
		y = tmp;
	};

	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
	private:
		T				*_vector;
		Allocator		_allocator;
		size_t			_size;
		size_t			_capacity;
		
		template <class InputIt>
		size_t	distance(InputIt first, InputIt last) {
			size_t	i = 0;
		
			while (first != last) {
				i++;
				first++;
			}
			return (i);
		};

	//https://en.cppreference.com/w/cpp/container/vector
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

		//https://en.cppreference.com/w/cpp/container/vector/vector
		//MEMBER FUNCTIONS
		//Default constructor. Constructs an empty container with a default-constructed allocator.
		vector(void) : _allocator(allocator_type()), _size(0), _capacity(0) {};
		
		//Constructs an empty container with the given allocator alloc.
		explicit vector(const allocator_type &allocator) :
			_allocator(allocator), _size(0), _capacity(0) {};

		//Constructs the container with count copies of elements with value value.
		explicit vector(size_type count, const T &value = T(), const allocator_type &allocator = allocator_type()) :
			_allocator(allocator), _size(0) {
				if ((count > max_size()) || (count < 0))
					throw std::length_error("Capacity exeeds limit");
				else {
					_capacity = count;
					_vector = new T[_capacity];
					assign(count, value);
				}
		};
		
		explicit vector(int count, const T &value = T(), const allocator_type &allocator = allocator_type()) :
			_allocator(allocator), _size(0) {
				if (count > 0) {
					if (static_cast<size_type>(count) > max_size())
						throw std::length_error("Capacity exeeds limit");
					else {
						_capacity = count;
						_vector = new T[_capacity];
						assign(count, value);
					}
				}
		};

		//Constructs the container with the contents of the range [first, last).
		template <class InputIt>
		vector(InputIt first, InputIt last, const allocator_type &allocator = allocator_type()) :
			_allocator(allocator), _size(0) {
				_capacity = distance(first, last);
				_vector = new T[_capacity];
				assign<InputIt>(first, last);
		};

		//Copy constructor. Constructs the container with the copy of the contents of other
		vector(const vector &copy) : _allocator(copy._allocator), _size(0), _capacity(copy.capacity()) {
			_vector = new T[_capacity];
			assign(copy.begin(), copy.end());
		};

		//Destructor: clears allocator and deletes vector elements
		~vector(void) {
			if (_capacity)
				delete [] _vector;
		};

		//https://en.cppreference.com/w/cpp/container/vector/operator%3D
		//Replaces content of one container to another
		vector&					operator=(const vector &other) {
			_allocator = other._allocator;
			if (other.capacity() > _capacity) {
				if (_capacity)
					delete [] _vector;
				_capacity = other.capacity();
				_vector = new T[_capacity];
			}
			assign(other.begin(), other.end());
			return (*this);
		};

		//https://en.cppreference.com/w/cpp/container/vector/assign
		//Replaces the contents with count copies of value value
		void					assign(size_type count, const_reference value) {
			clear();
			while (count--)
				push_back(value);
		};
		
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
			clear();
			while (first != last)
				push_back(*(first++));
		};

		//https://en.cppreference.com/w/cpp/container/vector
		//ELEMENT ACCESS METHODS
		//Returns a reference to the element at specified location pos.
		//If pos is not within the range of the container, std::out_of_range is thrown.
		reference				at(size_type pos) {
			if ((pos >= _size) || (pos < 0))
				throw (std::out_of_range("Position is out of range"));
			return (*(_vector + pos));
		};
		
		const_reference			at(size_type pos) const {
			if ((pos >= _size) || (pos < 0))
				throw (std::out_of_range("Position is out of range"));
			return (*(_vector + pos));
		};

		//Returns a reference to the element at specified location pos.
		//No bounds checking is performed.
		reference				operator[](size_type pos) {
			return (*(_vector + pos));
		};

		const_reference			operator[](size_type pos) const {
			return (*(_vector + pos));
		};

		//Returns a reference to the first element in the container.
		//Calling front on an empty container is UB.
		reference				front(void) {
			return (*_vector);
		};

		const_reference			front(void) const {
			return (*_vector);
		};

		//Returns a reference to the last element in the container.
		//Calling back on an empty container is UB.
		reference				back(void) {
			return (*(_vector + _size - 1));
		};

		const_reference			back(void) const {
			return (*(_vector + _size - 1));
		};
		
		//ITERATORS METHODS
		//https://en.cppreference.com/w/cpp/container/vector
		iterator				begin(void) {
			return (iterator(_vector));
		};

		iterator				end(void) {
			return (iterator(_vector + _size));
		};

		const_iterator			begin(void) const {
			return (const_iterator(_vector));
		};

		const_iterator			end(void) const {
			return (const_iterator(_vector + _size));
		};

		reverse_iterator		rbegin(void) {
			return (reverse_iterator(_vector + _size - 1));
		};

		reverse_iterator		rend(void) {
			return (reverse_iterator(_vector - 1));
		};

		const_reverse_iterator	rbegin(void) const {
			return (const_reverse_iterator(_vector + _size - 1));
		};

		const_reverse_iterator	rend(void) const {
			return (const_reverse_iterator(_vector - 1));
		};

		//https://en.cppreference.com/w/cpp/container/vector
		//CAPACITY: getting container size
		//Checks if the container has no elements, i.e. whether begin() == end().
		bool					empty(void) const {
			return (begin() == end());
		};

		//Returns the number of elements in the container, i.e. std::distance(begin(), end()).
		size_type				size(void) const {
			return (_size);
		};

		//Returns the maximum number of elements the container is able to hold due to system or library implementation limitations.
		size_type				max_size(void) const {
			if (typeid(value_type) == typeid('c'))
				return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		};

		//https://en.cppreference.com/w/cpp/container/vector/reserve
		/*
		** Increase the capacity of the vector to a value that's greater or equal to new_cap.
		** If new_cap is greater than the current capacity(), new storage is allocated, otherwise - nothing.
		** reserve() does not change the size of the vector.
		** If new_cap is greater than capacity(), all iterators, including the past-the-end iterator, 
		** and all references to the elements are invalidated, otherwise - not.
		*/
		void					reserve(size_type new_cap) {
			if (new_cap > max_size())
				throw std::length_error("Capacity exeeds limit");
			if (new_cap > _capacity) {
				pointer		tmp;
				size_type	i = -1;
				
				if (!_capacity)
					tmp = new T[1];
				else
					tmp = new T[new_cap];
				while (++i < _size)
					tmp[i] = _vector[i];
				if (_capacity)
					delete [] _vector;
				_vector = tmp;
				_capacity = new_cap;
			}
		};

		//https://en.cppreference.com/w/cpp/container/vector/capacity
		//Returns the number of elements that the container has currently allocated space for.
		size_type				capacity(void) const {
			return (_capacity);
		};

		//MODIFIERS: work with container elements
		//https://en.cppreference.com/w/cpp/container/vector/clear
		//Erases all elements from the container. After this call, size() returns zero.
		//Leaves the capacity() of the vector unchanged.
		void					clear(void) {
			erase(begin(), end());
		};

		//https://en.cppreference.com/w/cpp/container/vector/insert
		//Inserts value before pos
		//Returns iterator pointing to the inserted value
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

		//Inserts count copies of the value before pos
		void					insert(iterator pos, size_type count, const_reference value) {
			while (count--)
				pos = insert(pos, value);
		};
		
		void					insert(iterator pos, int count, const_reference value) {
			if (count > 0)
				while (count--)
					pos = insert(pos, value);
		};

		//Inserts elements from range [first, last) before pos.
		template <class InputIt>
		void					insert(iterator pos, InputIt first, InputIt last) {
			size_type	n = distance(first, last);
			if (first != last) {
				if (pos == end()) {
					while (first != last)
						push_back(*(first++));
				}
				else {
					pointer		tmp;
					iterator	it;
					size_type	i = 0;

					for (it = begin(); it != pos; it++)
						i++;
					tmp = new T[_size - i];
					size_type j = 0;
					while (it != end())
						tmp[j++] = *(it++);
					if ((_size + n) > max_size())
						throw std::length_error("Capacity exeeds limit");
					if ((_size + n) > _capacity) {
						try {
							reserve(_capacity * 2);
						}
						catch (const std::exception& e) {
							std::cerr << e.what() << std::endl;
							return ;
						}
					}
					while (first != last)
						_vector[i++] = *(first++);
					j = 0;
					while (i < _size + n)
						_vector[i++] = tmp[j++];
					_size += n;
				}
			}
		};

		//https://en.cppreference.com/w/cpp/container/vector/erase
		//Removes the element at pos.
		//Returns iterator following the last removed element.
		iterator				erase(iterator pos) {
			iterator	it = end();
			vector<T>	tmp = *this;
			iterator	cit = tmp.end();

			while (it != pos) {
				--it;
				*it = *cit;
				cit--;
			}
			_size--;
			return (it);
		};

		//Removes the elements in the range [first, last).
		//Returns iterator following the last removed element.
		iterator				erase(iterator first, iterator last) {
			iterator	it = first;
			
			while (it != last) {
				it = erase(it);
				last--;
			}
			return (last);
		};

		//https://en.cppreference.com/w/cpp/container/vector/push_back
		/*
		** Appends the given element value to the end of the container.
		** 1) The new element is initialized as a copy of value.
		** 2) value is moved into the new element.
		** If the new size() is greater than capacity() then all iterators and references (including the past-the-end iterator)
		** are invalidated. Otherwise only the past-the-end iterator is invalidated.
		*/
		void					push_back(const_reference value) {
			if ((_size + 1) > _capacity) {
				try {
					if (!_capacity)
						reserve(1);
					else
						reserve(_capacity * 2);
				} catch (const std::exception& e) {
		   			std::cerr << e.what() << std::endl;
					return ;
				}
			}
			_vector[_size++] = value;
		};

		//https://en.cppreference.com/w/cpp/container/vector/pop_back
		/*
		** Removes the last element of the container.
		** Calling pop_back on an empty container results in UB.
		** Iterators and references to the last element, as well as the end() iterator, are invalidated.
		*/
		void					pop_back() {
			erase(end());
		};
		
		//https://en.cppreference.com/w/cpp/container/vector/resize
		/*
		** Resizes the container to contain count elements.
		** If the current size is greater than count,
		** the container is reduced to its first count elements.
		** If the current size is less than count,
		** additional copies of value are appended.
		** Vector capacity is never reduced when resizing to smaller size.
		*/
		void					resize(size_type count, T value = T()) {
			if (_size > count) {
				iterator	it(_vector + count);

				erase(it, end());
			}
			if (_size < count) {
				if (_capacity < count) {
					try {
						reserve(count);
					}
					catch (const std::exception& e) {
						std::cerr << e.what() << std::endl;
						return ;
					}
				}
				while (_size < count)
					push_back(value);
			}
		};

		//https://en.cppreference.com/w/cpp/container/vector/swap
		//Exchanges the contents of the container with those of other.
		//Does not invoke any move, copy, or swap operations on individual elements.
		void					swap(vector& other) {
			swap_element(_allocator, other._allocator);
			swap_element(_capacity, other._capacity);
			swap_element(_vector, other._vector);
			swap_element(_size, other._size);
		};
	};

	//NON-MEMBER FUNCTIONS OVERLOAD
	//https://en.cppreference.com/w/cpp/container/vector/operator_cmp
	/*
	** Checks if the contents of lhs and rhs are equal,
	** that is, they have the same number of elements and
	** each element in lhs compares equal with the element
	** in rhs at the same position.
	*/
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &lhs,
		const vector<T, Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return (false);
	
		typename vector<T, Alloc>::const_iterator	lit;
		typename vector<T, Alloc>::const_iterator	rit = rhs.begin();
	
		for (lit = lhs.begin(); lit != lhs.end(); lit++) {
			if (*lit != *rit)
				return (false);
			rit++;
		}
		return (true);
	};
	
	//Checks if the contents of lhs and rhs are not equal.
	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &lhs,
		const vector<T, Alloc> &rhs) {
		return (!(rhs == lhs));
	};
	
	//Compares the contents of lhs and rhs lexicographically.
	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &lhs,
		const vector<T, Alloc> &rhs) {
		if ((!lhs.size() && !rhs.size()) || (!rhs.size()))
			return (false);
		if (!lhs.size())
			return (true);
	
		typename vector<T, Alloc>::const_iterator	lit = lhs.begin();
		typename vector<T, Alloc>::const_iterator	rit = rhs.begin();
	
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
	bool	operator<=( const vector<T, Alloc> &lhs,
		const vector<T, Alloc> &rhs ) {
		return ((lhs < rhs) || (lhs == rhs));
	};
	
	//Compares the contents of lhs and rhs lexicographically.
	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &lhs,
		const vector<T, Alloc> &rhs) {
		return (!(lhs <= rhs));
	};
	
	//Compares the contents of lhs and rhs lexicographically.
	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &lhs,
		const vector<T, Alloc> &rhs) {
		return (!(lhs < rhs));
	};
	
	/*
	** Specializes the std::swap algorithm for std::list.
	** Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/
	template <class T, class Alloc>
	void	swap(vector<T, Alloc> &lhs,
		vector<T, Alloc> &rhs) {
		lhs.swap(rhs);
	};
};

#endif
