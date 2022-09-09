#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
// # include <vector>
# include <exception>

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		private:
			Allocator	_alloc;
			size_t		_count, _cap;
			T*			_head;


		public:
			// CONSTRUCTORS //
			vector() :
				_alloc(), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(const Allocator& alloc) :
				_alloc(alloc), _count(0), _cap(0), _head(0) {
				return ;
			}

			explicit vector(T count, const T& value = T(), const Allocator& alloc = Allocator()) :
				_alloc(alloc), _count(count), _cap(count) {
				_head = _alloc.allocate(_count);
				for (size_t i = 0; i < _count; ++i) {
					_alloc.construct(_head + i, value);
				}
				return ;
			}

			template <class InputIt>
			vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) :
				_alloc(alloc), _count(0), _cap(0), _head(0) {
				return ;
			}

			vector(const vector& other) {
				*this = other;
				return ;
			}

			//	DESTRUCTOR //
			~vector() {
				for (size_t i = 0; i < this->_count; ++i) {
					this->_alloc.destroy(this->_head + i);
				}
				this->_alloc.deallocate(this->_head, this->_count);
				return ;
			}

			// ASSIGN OPERATOR //
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

			// ASSIGN //
			void	assign(T count, const T& value){
				return ;
			}

			template <class InputIt>
			void	assign(InputIt first, InputIt last) {
				return ;
			}

			// ELEMENT ACCESS //
			T& at(T pos) {
				if (pos >= this->_count)
					throw OutOfRange();
				return (this->_head[pos]);
			}

			const T& at(T pos) const {
				if (pos >= this->_count)
					throw OutOfRange();
				return (this->_head[pos]);
			}

			T&	operator[](T pos) {
				if (pos >= this->_count)
					throw OutOfBounds();
				return (this->_head[pos]);
			}

			const T&	operator[](T pos) const {
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