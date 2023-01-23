/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:16 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:58:17 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"

namespace ft {
	template <class Iter>
	class ra_iterator: public iterator
		<typename iterator_traits<Iter*>::iterator_category,
		typename iterator_traits<Iter*>::value_type,
		typename iterator_traits<Iter*>::difference_type,
		typename iterator_traits<Iter*>::pointer,
		typename iterator_traits<Iter*>::reference> {

	protected:
		typedef iterator_traits<Iter*>	itraits;

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
		ra_iterator() {
			_ptr = NULL;
			return ;
		}

		ra_iterator(const pointer &ptr) {
			_ptr = ptr;
			return ;
		}

		~ra_iterator() {};

		template <class U>
		ra_iterator(const ra_iterator<U> &src): _ptr(src.base()) {}

		ra_iterator&	operator=(ra_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}

		reference	operator*() const {
			return (*_ptr);
		}

		pointer	operator->() const {
			return (_ptr);
		}

		ra_iterator&	operator++() {
			++_ptr;
			return (*this);
		}

		ra_iterator	operator++(int) {
			return (ra_iterator(_ptr++));
		}

		ra_iterator&	operator--() {
			--_ptr;
			return (*this);
		}

		ra_iterator	operator--(int) {
			return (ra_iterator(_ptr--));
		}

		reference	operator[](difference_type n) const {
			return (_ptr[n]);
		}

		ra_iterator&	operator+=(difference_type n) {
			_ptr += n;
			return (*this);
		}

		ra_iterator	operator+(difference_type n) const {
			return (ra_iterator(_ptr + n));
		}

		ra_iterator&	operator-=(difference_type n) {
			_ptr -= n;
			return (*this);
		}

		ra_iterator	operator-(difference_type n) const {
			return (ra_iterator(_ptr - n));
		}

		const	pointer&	base() const {
			return (_ptr);
		}

		bool	operator==(ra_iterator const &rhs) const {
			return (_ptr == rhs._ptr);
		}

		bool	operator!=(ra_iterator const &rhs) const {
			return (_ptr != rhs._ptr);
		}

		bool	operator<(ra_iterator const &rhs) const {
			return (_ptr < rhs._ptr);
		}

		bool	operator>(ra_iterator const &rhs) const {
			return (_ptr > rhs._ptr);
		}

		bool	operator<=(ra_iterator const &rhs) const {
			return (_ptr <= rhs._ptr);
		}

		bool	operator>=(ra_iterator const &rhs) const {
			return (_ptr >= rhs._ptr);
		}
	};

	template <class Iter1, class Iter2>
	std::ptrdiff_t	operator-(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() - rhs.base());
	}

	template <class Iter1, class Iter2>
	std::ptrdiff_t	operator+(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() + rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator==(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() == rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator!=(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() != rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator>(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() > rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator>=(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator<(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() < rhs.base());
	}

	template <class Iter1, class Iter2>
	bool	operator<=(const ra_iterator<Iter1>& lhs,
								const ra_iterator<Iter2>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	template <class Iter>
	ra_iterator<Iter>	operator+(typename ra_iterator<Iter>::difference_type n,
		 const ra_iterator<Iter>& it) {
		return (ra_iterator<Iter>(it.base() + n));
	}

	template <class Iter>
	ra_iterator<Iter>	operator-(typename ra_iterator<Iter>::difference_type n,
		 const ra_iterator<Iter>& it) {
		return (ra_iterator<Iter>(it.base() - n));
	}
}

#endif