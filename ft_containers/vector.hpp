#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>
# include <algorithm>
# include <cstring>
# include <vector>
# include "iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"


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
			typedef vt_iterator<T*>							iterator;
			typedef vt_iterator<const T*>					const_iterator;
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
				this->_head = this->_alloc.allocate(this->_count);
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.construct(this->_head + i, value);
				}
				return ;
			}

			template <class InputIt>
			vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
					typename enable_if<!is_integral<InputIt>::value>::type* = nullptr) :
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
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				return ;
			}

			// ASSIGN OPERATOR
			vector&	operator=(const vector& other) {
				if (this == &other)
					return (*this);
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_count = other._count;
				this->_cap = other._cap;
				this->_alloc = other._alloc;
				this->_head = this->_alloc.allocate(this->_count);
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.construct(this->_head + i, other[i]);
				}
				return (*this);
			}

			// ASSIGN
			void	assign(size_type count, const value_type& value){
				if (count <= 0)
					return ;
				if (count > this->_cap)
					reserve(count);
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_count = count;
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.construct(this->_head + i, value);
				}
				return ;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last,
							typename enable_if<!is_integral<InputIt>::value>::type* = nullptr) {
				clear();
				for (; first != last; ++first) {
					push_back(*first);
				}
				return ;
			}

			// GET_ALLOCATOR
			allocator_type	get_allocator() const {
				return (this->_alloc);
			}

			// ELEMENT ACCESS
			reference at(size_type pos) {
				if (pos >= this->_count)
					throw OutOfRange();
				return (this->_head[pos]);
			}

			const_reference at(size_type pos) const {
				if (pos >= this->_count)
					throw OutOfRange();
				return (this->_head[pos]);
			}

			reference	operator[](size_type pos) {
				if (pos >= this->_count)
					throw OutOfBounds();
				return (this->_head[pos]);
			}

			const_reference	operator[](size_type pos) const {
				if (pos >= this->_count)
					throw OutOfBounds();
				return (this->_head[pos]);
			}

			reference	front() {
				if (!this->_head)
					throw EmptyContainer();
				return (*this->_head);
			}

			const_reference	front() const {
				if (!this->_head)
					throw EmptyContainer();
				return (*this->_head);
			}

			reference	back() {
				if (!this->_head)
					throw EmptyContainer();
				return (this->_head[this->_count - 1]);
			}

			const_reference	back() const {
				if (!this->_head)
					throw EmptyContainer();
				return (this->_head[this->_count - 1]);
			}

			T*	data() {
				return (this->_head);
			}

			T*	data() const {
				return (this->_head);
			}

			// ITERATORS
			iterator	begin() {
				return (iterator(this->_head));
			}

			const_iterator	begin() const {
				return (const_iterator(this->_head));
			}

			iterator	end() {
				return (iterator(this->_head + this->_count));
			}

			const_iterator	end() const {
				return (const_iterator(this->_head + this->_count));
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
				return (this->_head == this->_head + this->_count);
			}

			size_type	size() const {
				return (this->_count);
			}

			size_type	max_size() const {
				return (this->_alloc.max_size());
			}

			void	reserve(size_type new_cap) {
				if (new_cap > max_size())
					throw LengthError();
				if (new_cap <= this->_cap)
					return ;
				T*	tmp;

				tmp = this->_alloc.allocate(new_cap);
				if (this->_count > 0) {
					for (size_t i = 0; i < this->_count; ++i) {
						this->_alloc.construct(tmp + i, this->_head[i]);
					}
					for (size_t i = 0; i < this->_count; ++i) {
						this->_alloc.destroy(this->_head + i);
					}
					this->_alloc.deallocate(this->_head, this->_count);
				}
				this->_cap = new_cap;
				this->_head = tmp;
				// INVALIDATE ITERATORS
			}

			size_type	capacity() const {
				return (this->_cap);
			}

			// MODIFIERS
			void	clear() {
				if (this->_count == 0)
					return ;
				for (size_t i = 0; i < this->_count; ++i) {
						this->_alloc.destroy(this->_head + i);
					}
				this->_count = 0;
			}

			iterator	insert(iterator pos, const T& value) {
				difference_type	dif = pos - begin();
				T				*tmp;
				size_t			j = 0;

				if (pos == end()) {
					push_back(value);
					return (this->_head + dif);
				}
				if (pos > end() || pos < begin())
					throw LengthError();
				if (this->_count >= this->_cap)
					reserve(this->_cap + ((this->_cap + 2) / 2));
				tmp = this->_alloc.allocate(this->_cap);
				for (size_t i = 0; i != this->_count; ++i) {
					if (i == dif) {
						this->_alloc.construct(tmp + i + j, value);
						++j;
					}
					this->_alloc.construct(tmp + i + j, this->_head[i]);
				}
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_head = tmp;
				++(this->_count);
				return (this->_head + dif);
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
				if (this->_count + count >= this->_cap)
					reserve(this->_cap + count + ((this->_cap + 2) / 2));
				tmp = this->_alloc.allocate(this->_cap);
				for (size_t i = 0; i != this->_count; ++i) {
					if (i == dif) {
						while (j < count) {
							this->_alloc.construct(tmp + i + j, value);
							++j;
						}
					}
					this->_alloc.construct(tmp + i + j, this->_head[i]);
				}
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_head = tmp;
				this->_count += count;
				return ;
			}

			template <class InputIt>
			void	insert(iterator pos, InputIt first, InputIt last,
						typename enable_if<!is_integral<InputIt>::value>::type* = nullptr) {
				difference_type	dif = pos - begin();
				T				*tmp;
				size_t			j = 0;
				size_t			count = 0;
				InputIt			it;

				if (pos > end() || pos < begin() || first > last)
					throw LengthError();
				if (pos == end()) {
					for (; first != last; ++first) {
						push_back(*first);
					}
					return ;
				}
				it = first;
				for (; it != last; ++it) {
					++count;
				}
				if (this->_count + count >= this->_cap)
					reserve(this->_cap + count + ((this->_cap + 2) / 2));
				tmp = this->_alloc.allocate(this->_cap);
				for (size_t i = 0; i != this->_count; ++i) {
					if (i == dif) {
						while (j < count) {
							this->_alloc.construct(tmp + i + j, *first);
							++j;
							++first;
						}
					}
					this->_alloc.construct(tmp + i + j, this->_head[i]);
				}
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_head = tmp;
				this->_count += count;
				return ;
			}

			iterator	erase(iterator pos) {
				difference_type	dif = pos - begin();
				T				*tmp;
				size_t			j = 0;

				if (pos == end() - 1) {
					pop_back();
					return (this->_head + dif);
				}
				if (pos < begin())
					dif = 0;
				else if (pos >= end())
					throw LengthError();
				tmp = this->_alloc.allocate(this->_cap);
				for (size_t i = 0; i != this->_count; ++i) {
					if (i == dif)
						continue;
					this->_alloc.construct(tmp + j, this->_head[i]);
					j++;
				}
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_head = tmp;
				--(this->_count);
				return (this->_head + dif);
				// return (end() - 1);
			}

			iterator	erase(iterator first, iterator last) {
				T		*tmp;
				size_t	j = 0;
				size_t	ret = 0;

				tmp = this->_alloc.allocate(this->_cap);
				for (iterator it = begin(); it != end(); ++it) {
					if (it == first && first != last) {
						++first;
						continue ;
					}
					if (it == last)
						ret = j;
					this->_alloc.construct(tmp + j, *it);
					++j;
				}
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_head = tmp;
				this->_count = j;
				return (this->_head + ret);
			}

			void	push_back(const T& value) {
				if (this->_count < this->_cap) {
					this->_alloc.construct(this->_head + this->_count, value);
				}
				else {
					this->reserve(this->_cap + ((this->_cap + 2) / 2));
					this->_alloc.construct(this->_head + this->_count, value);
				}
				this->_count++;
				// INVALIDATE ITERATORS
			}

			void	pop_back() {
				if (!this->_head)
					throw EmptyContainer();
				this->_alloc.destroy(this->_head + this->_count);
				this->_count--;
				// INVALIDATE ITERATORS
			}

			// void	resize(size_type count) {
			// 	T	*tmp;

			// 	if (count > max_size())
			// 		throw LengthError();
			// 	if (this->_count == count)
			// 		return ;
			// 	else if (this->_cap < count)
			// 		tmp = this->_alloc.allocate(count);
			// 	else
			// 		tmp = this->_alloc.allocate(this->_cap);
			// 	for (size_t i = 0; i < count; ++i) {
			// 		if (i < this->_count)
			// 			this->_alloc.construct(tmp + i, this->_head[i]);
			// 		else
			// 			this->_alloc.construct(tmp + i, 0);
			// 	}
			// 	for (size_t i = 0; i < this->_count; ++i) {
			// 		this->_alloc.destroy(this->_head + i);
			// 	}
			// 	this->_alloc.deallocate(this->_head, this->_count);
			// 	this->_head = tmp;
			// 	this->_count = count;
			// 	return ;
			// }

			void	resize(size_type count, T value = T()) {
				T	*tmp;

				if (count > max_size())
					throw LengthError();
				if (this->_count == count)
					return ;
				else if (this->_cap < count)
					tmp = this->_alloc.allocate(count);
				else
					tmp = this->_alloc.allocate(this->_cap);
				for (size_t i = 0; i < count; ++i) {
					if (i < this->_count)
						this->_alloc.construct(tmp + i, this->_head[i]);
					else
						this->_alloc.construct(tmp + i, value);
				}
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_head = tmp;
				this->_count = count;
				return ;
			}

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
}

#endif