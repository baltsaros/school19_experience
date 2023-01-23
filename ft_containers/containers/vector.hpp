/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:02 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 08:23:54 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>
# include <cstring>
# include "../utilities/iterator.hpp"
# include "../utilities/reverse_iterator.hpp"
# include "../utilities/enable_if.hpp"
# include "../utilities/is_integral.hpp"
# include "../utilities/lexi_compare.hpp"


namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// TYPEDEFS
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef ra_iterator<T>							iterator;
			typedef ra_iterator<const T>					const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


		private:
			allocator_type	_alloc;
			size_type		_count, _cap;
			value_type*		_head;



		public:
			// CONSTRUCTORS
			vector() :
				_alloc(), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(const allocator_type& alloc) :
				_alloc(alloc), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(size_type count, const T& value = T(),
				const Allocator& alloc = Allocator()) :
				_alloc(alloc), _count(count), _cap(count) {
				_head = _alloc.allocate(_count);
				for (size_t i = 0; i < _count; ++i) {
					_alloc.construct(_head + i, value);
				}
				return ;
			}

			template <class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
					typename enable_if<!is_integral<InputIt>::value>::type* = NULL) :
				_alloc(alloc), _count(0), _cap(0), _head(0) {
				assign(first, last);
				return ;
			}

			vector(const vector& other) :
				_alloc(), _count(0), _cap(0), _head(0) {
				*this = other;
				return ;
			}

			//	DESTRUCTOR
			~vector() {
				if (!_head)
					return ;
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				return ;
			}

			// ASSIGN OPERATOR
			vector&	operator=(const vector& other) {
				if (this != &other)
					assign(other.begin(), other.end());
				return (*this);
			}

			// ASSIGN
			void	assign(size_type count, const value_type& value){
				if (count <= 0)
					return ;
				if (count > _cap)
					reserve(count);
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_count = count;
				for (size_t i = 0; i < _count; ++i) {
					_alloc.construct(_head + i, value);
				}
				return ;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last,
							typename enable_if<!is_integral<InputIt>::value>::type* = NULL) {
				clear();
				for (; first != last; ++first) {
					push_back(*first);
				}
				return ;
			}

			// GET_ALLOCATOR
			allocator_type	get_allocator() const {
				return (_alloc);
			}

			// ELEMENT ACCESS
			reference at(size_type pos) {
				if (pos >= _count)
					throw OutOfRange();
				return (_head[pos]);
			}

			const_reference at(size_type pos) const {
				if (pos >= _count)
					throw OutOfRange();
				return (_head[pos]);
			}

			reference	operator[](size_type pos) {
				if (pos >= _count)
					throw OutOfBounds();
				return (_head[pos]);
			}

			const_reference	operator[](size_type pos) const {
				if (pos >= _count)
					throw OutOfBounds();
				return (_head[pos]);
			}

			reference	front() {
				if (!_head)
					throw EmptyContainer();
				return (*_head);
			}

			const_reference	front() const {
				if (!_head)
					throw EmptyContainer();
				return (*_head);
			}

			reference	back() {
				if (!_head)
					throw EmptyContainer();
				return (_head[_count - 1]);
			}

			const_reference	back() const {
				if (!_head)
					throw EmptyContainer();
				return (_head[_count - 1]);
			}

			T*	data() {
				return (_head);
			}

			const T*	data() const {
				return (_head);
			}

			// ITERATORS
			iterator	begin() {
				return (iterator(_head));
			}

			const_iterator	begin() const {
				return (const_iterator(_head));
			}

			iterator	end() {
				return (iterator(_head + _count));
			}

			const_iterator	end() const {
				return (const_iterator(_head + _count));
			}

			reverse_iterator	rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(end()));
			}

			reverse_iterator	rend() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(begin()));
			}

			// CAPACITY
			bool empty() const {
				return (_head == _head + _count);
			}

			size_type	size() const {
				return (_count);
			}

			size_type	max_size() const {
				return (_alloc.max_size());
			}

			void	reserve(size_type new_cap) {
				if (new_cap > max_size())
					throw LengthError();
				if (new_cap <= _cap)
					return ;
				T*	tmp;

				tmp = _alloc.allocate(new_cap);
				if (_count > 0) {
					for (size_t i = 0; i < _count; ++i) {
						_alloc.construct(tmp + i, _head[i]);
					}
					for (size_t i = 0; i < _count; ++i) {
						_alloc.destroy(_head + i);
					}
					_alloc.deallocate(_head, _cap);
				}
				_cap = new_cap;
				_head = tmp;
			}

			size_type	capacity() const {
				return (_cap);
			}

			// MODIFIERS
			void	clear() {
				if (_count == 0)
					return ;
				for (size_t i = 0; i < _count; ++i) {
						_alloc.destroy(_head + i);
					}
				_count = 0;
			}

			iterator	insert(iterator pos, const T& value) {
				difference_type	dif = pos - begin();
				T				*tmp;
				size_t			j = 0;

				if (pos == end()) {
					push_back(value);
					return (_head + dif);
				}
				if (pos > end() || pos < begin())
					throw LengthError();
				if (_count >= _cap)
					reserve(_cap + ((_cap + 2) / 2));
				tmp = _alloc.allocate(_cap);
				for (size_t i = 0; i != _count; ++i) {
					if (i == (size_t)dif) {
						_alloc.construct(tmp + i + j, value);
						++j;
					}
					_alloc.construct(tmp + i + j, _head[i]);
				}
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				_head = tmp;
				++_count;
				return (_head + dif);
			}

			void	insert(iterator pos, size_type count, const T& value) {
				difference_type	dif = pos - begin();
				T				*tmp;
				size_t			j = 0;

				if (pos == end()) {
					while (j < count) {
						push_back(value);
						++j;
					}
					return ;
				}
				if (pos > end() || pos < begin())
					throw LengthError();
				if (_count + count >= _cap)
					reserve(_cap + count + ((_cap + 2) / 2));
				tmp = _alloc.allocate(_cap);
				for (size_t i = 0; i != _count; ++i) {
					if (i == (size_t)dif) {
						while (j < count) {
							_alloc.construct(tmp + i + j, value);
							++j;
						}
					}
					_alloc.construct(tmp + i + j, _head[i]);
				}
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				_head = tmp;
				_count += count;
				return ;
			}

			template <class InputIt>
			void	insert(iterator pos, InputIt first, InputIt last,
						typename enable_if<!is_integral<InputIt>::value>::type* = NULL) {
				difference_type	dif = pos - begin();
				T				*tmp;
				size_t			j = 0;
				size_t			count = 0;
				InputIt			it = first;

				if (pos > end() || pos < begin())
					throw LengthError();
				if (pos == end()) {
					for (; first != last; ++first) {
						push_back(*first);
					}
					return ;
				}
				for (; it != last; ++it) {
					++count;
				}
				if (_count + count >= _cap)
					_cap = _cap + count + ((_cap + 2) / 2);
				tmp = _alloc.allocate(_cap);
				for (size_t i = 0; i != _count; ++i) {
					if (i == (size_t)dif) {
						while (j < count) {
							_alloc.construct(tmp + i + j, *first);
							++j;
							++first;
						}
					}
					_alloc.construct(tmp + i + j, _head[i]);
				}
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				_head = tmp;
				_count += count;
				return ;
			}

			iterator	erase(iterator pos) {
				difference_type	dif = pos - begin();
				T				*tmp;
				size_t			j = 0;

				if (pos == end() - 1) {
					pop_back();
					return (_head + dif);
				}
				if (pos < begin())
					dif = 0;
				else if (pos >= end())
					throw LengthError();
				tmp = _alloc.allocate(_cap);
				for (size_t i = 0; i != _count; ++i) {
					if (i == (size_t)dif)
						continue;
					_alloc.construct(tmp + j, _head[i]);
					j++;
				}
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				_head = tmp;
				--_count;
				return (_head + dif);
			}

			iterator	erase(iterator first, iterator last) {
				T		*tmp;
				size_t	j = 0;
				size_t	ret = 0;

				tmp = _alloc.allocate(_cap);
				for (iterator it = begin(); it != end(); ++it) {
					if (it == first && first != last) {
						++first;
						continue ;
					}
					_alloc.construct(tmp + j, *it);
					++j;
					if (it < first)
						++ret;
				}
				if (last == end())
					ret = j;
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				_head = tmp;
				_count = j;
				return (_head + ret);
			}

			void	push_back(const T& value) {
				if (_count < _cap) {
					_alloc.construct(_head + _count, value);
				}
				else {
					reserve(_cap + ((_cap + 2) / 2));
					_alloc.construct(_head + _count, value);
				}
				_count++;
			}

			void	pop_back() {
				if (!_head)
					throw EmptyContainer();
				_alloc.destroy(_head + _count);
				_count--;
			}

			void	resize(size_type count, T value = T()) {
				T	*tmp;

				if (count > max_size())
					throw LengthError();
				if (_count == count)
					return ;
				else if (_cap < count) {
					tmp = _alloc.allocate(count);
					_cap = count;
				}
				else
					tmp = _alloc.allocate(_cap);
				for (size_t i = 0; i < count; ++i) {
					if (i < _count)
						_alloc.construct(tmp + i, _head[i]);
					else
						_alloc.construct(tmp + i, value);
				}
				for (size_t i = 0; i < _count; ++i) {
					_alloc.destroy(_head + i);
				}
				_alloc.deallocate(_head, _count);
				_head = tmp;
				_count = count;
				return ;
			}

			void	swap(vector& other) {
				vector<T>	tmp;

				tmp._count = _count;
				tmp._cap = _cap;
				tmp._alloc = _alloc;
				tmp._head = _head;

				_count = other._count;
				_cap = other._cap;
				_alloc = other._alloc;
				_head = other._head;

				other._count = tmp._count;
				other._cap = tmp._cap;
				other._alloc = tmp._alloc;
				other._head = tmp._head;

				tmp._head = NULL;
			}
		private:
			// EXCEPTIONS
			class OutOfRange: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::vector.at() is out of range");
				}
			};

			class OutOfBounds: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::vector[] index is out of bounds");
				}
			};

			class EmptyContainer: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::vector is empty");
				}
			};

			class LengthError: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::vector begin is ahead of end");
				}
			};

	};

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc>& lhs,
						const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		if (lhs.capacity() != rhs.capacity())
			return (false);
		if (lhs.get_allocator() != rhs.get_allocator())
			return (false);
		for (size_t i = 0; i != lhs.size(); ++i) {
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc>& lhs,
						const vector<T,Alloc>& rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc>& lhs,
						const vector<T,Alloc>& rhs) {
		bool	ret;

		ret = lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		return (ret);
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc>& lhs,
						const vector<T,Alloc>& rhs) {
		bool	ret;

		ret = lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		return (ret || (lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc>& lhs,
						const vector<T,Alloc>& rhs) {
		return (!(lhs <= rhs));
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc>& lhs,
						const vector<T,Alloc>& rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs) {
		vector<T, Alloc>	tmp;

		tmp = rhs;
		rhs = lhs;
		lhs = tmp;
		return ;
	}
}

#endif