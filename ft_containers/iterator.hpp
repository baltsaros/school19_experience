#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"
# include <type_traits>

namespace ft {
	template <class Iter>
	class reverse_iterator: public iterator
		<typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference> {

	private:
		Iter	_t;

	protected:
		Iter	_ptr;
		typedef iterator_traits<Iter>	itraits;

	public:
		typedef Iter								iterator_type;
		typedef typename itraits::difference_type	difference_type;
		typedef typename itraits::reference			reference;
		typedef typename itraits::pointer			pointer;
		typedef typename itraits::value_type		value_type;
		typedef typename itraits::iterator_category	iterator_category;

		reverse_iterator() {
			this->_ptr = NULL;
			this->_t = NULL;
			return ;
		}

		explicit reverse_iterator(iterator_type x) {
			this->_ptr = x;
			this->_t = x;
			return ;
		}

		template <class U>
		reverse_iterator(const reverse_iterator<U> &other) {
			this->_ptr = other.base();
			this->_t = other.base();
			return ;
		}

		template <class U>
		reverse_iterator&	operator=(const reverse_iterator<U> &rhs) {
			this->_ptr = rhs.base();
			this->_t = this->_ptr;
			return (*this);
		}

		iterator_type	base() const {
			return (this->_ptr);
		}

		reference	operator*() const {
			Iter	tmp;

			tmp = this->_ptr;
			--tmp;
			return (*tmp);
		}

		pointer	operator->() const {
			Iter	tmp;

			tmp = this->_ptr;
			--tmp;
			return &(*tmp);
		}

		reference	operator[](difference_type n) const {
			return *(*this + n);
		}

		reverse_iterator&	operator++() {
			--(this->_ptr);
			return (*this);
		}

		reverse_iterator	operator++(int) {
			reverse_iterator	tmp(*this);
			--(this->_ptr);
			return (tmp);
		}

		reverse_iterator&	operator--() {
			++(this->_ptr);
			return (*this);
		}

		reverse_iterator	operator--(int) {
			reverse_iterator	tmp(*this);
			++(this->_ptr);
			return (tmp);
		}

		reverse_iterator&	operator+=(difference_type n) {
			this->_ptr -= n;
			return (*this);
		}

		reverse_iterator	operator+(difference_type n) const {
			return (reverse_iterator(this->_ptr - n));
		}

		reverse_iterator&	operator-=(difference_type n) {
			this->_ptr += n;
			return (*this);
		}

		reverse_iterator	operator-(difference_type n) const {
			return (reverse_iterator(this->_ptr + n));
		}
	};


	template <class Iter1, class Iter2>
	std::ptrdiff_t	operator-(const reverse_iterator<Iter1>& lhs,
								const reverse_iterator<Iter2>& rhs) {
		return (rhs.base() - lhs.base());
	}

	template <class Iter1, class Iter2>
	std::ptrdiff_t	operator+(const reverse_iterator<Iter1>& lhs,
								const reverse_iterator<Iter2>& rhs) {
		return (lhs.base() + rhs.base());
	}

	template <class Iter>
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n,
		 const reverse_iterator<Iter>& it) {
		return (reverse_iterator<Iter>(it.base() - n));
	}

	template <class Iter>
	reverse_iterator<Iter>	operator-(typename reverse_iterator<Iter>::difference_type n,
		 const reverse_iterator<Iter>& it) {
		return (reverse_iterator<Iter>(it.base() + n));
	}

	template <class Iter1, class Iter2>
	bool	operator==(const reverse_iterator<Iter1> &lhs,
						const reverse_iterator<Iter2> &rhs){
		return (lhs.base() == rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator!=(const reverse_iterator<Iter1> &lhs,
						const reverse_iterator<Iter2> &rhs){
		return (lhs.base() != rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator<(const reverse_iterator<Iter1> &lhs,
						const reverse_iterator<Iter2> &rhs){
		return (lhs.base() > rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator<=(const reverse_iterator<Iter1> &lhs,
						const reverse_iterator<Iter2> &rhs){
		return (lhs.base() >= rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator>(const reverse_iterator<Iter1> &lhs,
						const reverse_iterator<Iter2> &rhs){
		return (lhs.base() < rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator>=(const reverse_iterator<Iter1> &lhs,
						const reverse_iterator<Iter2> &rhs){
		return (lhs.base() <= rhs.base());
	}

	template <class Iter>
	class vt_iterator: public iterator
		<typename iterator_traits<Iter*>::iterator_category,
		typename iterator_traits<Iter*>::value_type,
		typename iterator_traits<Iter*>::difference_type,
		typename iterator_traits<Iter*>::pointer,
		typename iterator_traits<Iter*>::reference> {

	protected:
		typedef ft::iterator<ft::random_access_iterator_tag, Iter>	itraits;

	public:
		typedef Iter								iterator_type;
		typedef typename itraits::difference_type	difference_type;
		typedef typename itraits::reference			reference;
		typedef typename itraits::pointer			pointer;
		typedef typename itraits::value_type		value_type;
		typedef typename itraits::iterator_category	iterator_category;
	
	protected:
		pointer	_ptr;
	
	public:
		vt_iterator() {
			this->_ptr = NULL;
			return ;
		}

		vt_iterator(const pointer &ptr) {
			this->_ptr = ptr;
			return ;
		}

		~vt_iterator() {};

		vt_iterator(vt_iterator const &src) {
			*this = src;
			return ;
		}

		operator	vt_iterator<Iter const>() const {
			return (vt_iterator<Iter const>(_ptr));
		}

		vt_iterator&	operator=(vt_iterator const &rhs) {
			this->_ptr = rhs._ptr;
			return (*this);
		}

		reference	operator*() const {
			return (*this->_ptr);
		}

		pointer	operator->() const {
			return (this->_ptr);
		}

		vt_iterator&	operator++() {
			++(this->_ptr);
			return (*this);
		}

		vt_iterator	operator++(int) {
			return (vt_iterator(this->_ptr++));
		}

		vt_iterator&	operator--() {
			--(this->_ptr);
			return (*this);
		}

		vt_iterator	operator--(int) {
			return (vt_iterator(this->_ptr--));
		}

		reference	operator[](difference_type n) const {
			return (this->_ptr[n]);
		}

		vt_iterator&	operator+=(difference_type n) {
			this->_ptr += n;
			return (*this);
		}

		vt_iterator	operator+(difference_type n) const {
			return (vt_iterator(this->_ptr + n));
		}

		vt_iterator&	operator-=(difference_type n) {
			this->_ptr -= n;
			return (*this);
		}

		vt_iterator	operator-(difference_type n) const {
			return (vt_iterator(this->_ptr - n));
		}

		const	pointer&	base() const {
			return (this->_ptr);
		}

		bool	operator==(vt_iterator const &rhs) const {
			return (this->_ptr == rhs._ptr);
		}

		bool	operator!=(vt_iterator const &rhs) const {
			return (this->_ptr != rhs._ptr);
		}

		bool	operator<(vt_iterator const &rhs) const {
			return (this->_ptr < rhs._ptr);
		}

		bool	operator>(vt_iterator const &rhs) const {
			return (this->_ptr > rhs._ptr);
		}

		bool	operator<=(vt_iterator const &rhs) const {
			return (this->_ptr <= rhs._ptr);
		}

		bool	operator>=(vt_iterator const &rhs) const {
			return (this->_ptr >= rhs._ptr);
		}
	};

	template <class Iter1, class Iter2>
	std::ptrdiff_t	operator-(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template <class Iter1, class Iter2>
	std::ptrdiff_t	operator+(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() + rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator==(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator!=(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator>(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator>=(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator<(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() < rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator<=(const vt_iterator<Iter1>& lhs,
								const vt_iterator<Iter2>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <class Iter>
	vt_iterator<Iter>	operator+(typename vt_iterator<Iter>::difference_type n,
		 const vt_iterator<Iter>& it) {
		return (vt_iterator<Iter>(it.base() + n));
	}

	template <class Iter>
	vt_iterator<Iter>	operator-(typename vt_iterator<Iter>::difference_type n,
		 const vt_iterator<Iter>& it) {
		return (vt_iterator<Iter>(it.base() - n));
	}
}

#endif