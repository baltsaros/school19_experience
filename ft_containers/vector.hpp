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
			typedef std::size_t size_type;

		private:
			Allocator	_alloc;
			size_type	_count, _cap;
			T*			_head;



		public:
			// CONSTRUCTORS
			vector() :
				_alloc(), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(const Allocator& alloc) :
				_alloc(alloc), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(size_t count, const T& value = T(), const Allocator& alloc = Allocator()) :
				_alloc(alloc), _count(count), _cap(count) {
				this->_head = this->_alloc.allocate(this->_count);
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.construct(this->_head + i, value);
				}
				return ;
			}

			// template <class InputIt>
			// vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) :
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
			void	assign(size_t count, const T& value){

				return ;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last) {
				return ;
			}

			// GET_ALLOCATOR
			Allocator	get_allocator() const {
				return (this->_alloc);
			}

			// ELEMENT ACCESS
			T& at(size_t pos) {
				if (pos >= this->_count)
					throw OutOfRange();
				return (this->_head[pos]);
			}

			const T& at(size_t pos) const {
				if (pos >= this->_count)
					throw OutOfRange();
				return (this->_head[pos]);
			}

			T&	operator[](size_t pos) {
				if (pos >= this->_count)
					throw OutOfBounds();
				return (this->_head[pos]);
			}

			const T&	operator[](size_t pos) const {
				if (pos >= this->_count)
					throw OutOfBounds();
				return (this->_head[pos]);
			}

			T&	front() {
				if (!this->_head)
					throw EmptyContainer();
				return (*this->_head);
			}

			const T&	front() const {
				if (!this->_head)
					throw EmptyContainer();
				return (*this->_head);
			}

			T&	back() {
				if (!this->_head)
					throw EmptyContainer();
				return (this->_head[this->_count - 1]);
			}

			const T&	back() const {
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


			// CAPACITY
			bool empty() const {
				return (this->_head == this->_head + this->_count);
			}

			size_t	size() const {
				return (this->_count);
			}

			size_t	max_size() const {
				return (this->_alloc.max_size());
			}

			void	reserve(size_t new_cap) {
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

			size_t	capacity() const {
				return (this->_cap);
			}

			// MODIFIERS


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