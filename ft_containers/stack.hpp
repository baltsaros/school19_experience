#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack {
		public:
			// TYPEDEFS
			typedef Container								container_type;
			typedef T										value_type;
			typedef std::size_t								size_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;

		protected:
			container_type	_cont;

		public:
			explicit stack(const Container& cont = Container()) {
				_cont = cont;
			}

			stack(const stack& other) {
				_cont = other._cont;
			}

			~stack() {}

			stack&	operator=(const stack& other) {
				_cont = other._cont;
				return (*this);
			}

			reference	top() {
				return (_cont.back());
			}

			const_reference top() const {
				return (_cont.back());
			}

			bool	empty() const {
				return (_cont.empty());
			}

			size_type	size() const {
				return (_cont.size());
			}

			void	push(const value_type& value) {
				_cont.push_back(value);
			}

			void	pop() {
				_cont.pop_back();
			}

			friend bool	operator==(const stack& lhs, const stack& rhs) {
				return (lhs._cont == rhs._cont);
			}

			friend bool	operator!=(const stack& lhs, const stack& rhs) {
				return (lhs._cont != rhs._cont);
			}

			friend bool	operator<(const stack& lhs, const stack& rhs) {
				return (lhs._cont < rhs._cont);
			}

			friend bool	operator<=(const stack& lhs, const stack& rhs) {
				return (lhs._cont <= rhs._cont);
			}

			friend bool	operator>(const stack& lhs, const stack& rhs) {
				return (lhs._cont > rhs._cont);
			}

			friend bool	operator>=(const stack& lhs, const stack& rhs) {
				return (lhs._cont >= rhs._cont);
			}
	};
}

#endif