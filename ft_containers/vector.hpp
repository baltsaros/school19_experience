#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <exception>
# include <algorithm>
# include <cstring>
# include <vector>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			// TYPEDEFS
			typedef T					value_type;
			typedef Allocator			allocator_type;
			typedef std::size_t			size_type;
			typedef std::ptrdiff_t		difference_type;
			typedef value_type&			reference;
			typedef const value_type&	const_reference;

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

			explicit vector(size_type count, const value_type& value = value_type(),
				const allocator_type& alloc = allocator_type()) :
				_alloc(alloc), _count(count), _cap(count) {
				this->_head = this->_alloc.allocate(this->_count);
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.construct(this->_head + i, value);
				}
				return ;
			}

			// template <class InputIt>
			// vector(InputIt first, InputIt last, const allocator_type& alloc = allocator_type()) :
			// 	_alloc(alloc), _count(0), _cap(0), _head(0) {
			// 	return ;
			// }

			vector(const vector& other) {
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

				return ;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last) {
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
				return ;
			}

			const_iterator	begin() {
				return ;
			}

			iterator	end() {
				return ;
			}

			const_iterator	end() {
				return ;
			}

			reverse_iterator	rbegin() {
				return ;
			}

			const_reverse_iterator	rbegin() {
				return ;
			}

			reverse_iterator	rend() {
				return ;
			}

			const_reverse_iterator	rend() {
				return ;
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
				if (new_cap <= this->_cap)
					return ;
				T	*tmp;
				tmp = this->_alloc.allocate(new_cap);
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.construct(tmp + i, this->_head[i]);
				}
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				this->_cap = new_cap;
				this->_head = tmp;
				// INVALIDATE ITERATORS
			}

			size_type	capacity() const {
				return (this->_cap);
			}

			// MODIFIERS
			void	clear() {
				for (size_t i = 0; i < this->_count; ++i) {
						this->_alloc.destroy(this->_head + i);
					}
				this->_count = 0;
			}

			// iterator	insert(iterator pos, const T& value) {
			
			// 	return ;
			// }

			// void	insert(iterator pos, size_type count, const T&& value) {

			// 	return ;
			// }

			// template <class InputIt>
			// void	insert(iterator pos, InputIt first, InputIt last) {

				// return ;
			// }

			// iterator	erase(iterator pos) {
			
			// 	return ;
			// }

			// iterator	erase(iterator first, iterator last) {

			// 	return ;
			// }

			void	push_back(const T& value) {
				if (this->_count < this->_cap)
					this->_alloc.construct(this->_head + this->_count, value);
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

	};
}

#endif