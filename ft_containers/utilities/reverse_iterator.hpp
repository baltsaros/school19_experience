/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:38 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:58:39 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <cstddef>
# include "iterator_traits.hpp"

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

		reverse_iterator(): _t(NULL), _ptr(NULL) {}

		explicit reverse_iterator(iterator_type x) {
			_t = x;
			_ptr = x;
			return ;
		}

		template <class U>
		reverse_iterator(const reverse_iterator<U> &other) {
			_ptr = other.base();
			_t = other.base();
			return ;
		}

		template <class U>
		reverse_iterator&	operator=(const reverse_iterator<U> &rhs) {
			_ptr = rhs.base();
			_t = _ptr;
			return (*this);
		}

		iterator_type	base() const {
			return (_ptr);
		}

		reference	operator*() const {
			Iter	tmp;

			tmp = _ptr;
			--tmp;
			return (*tmp);
		}

		pointer	operator->() const {
			Iter	tmp;

			tmp = _ptr;
			--tmp;
			return &(*tmp);
		}

		reference	operator[](difference_type n) const {
			return *(*this + n);
		}

		reverse_iterator&	operator++() {
			--_ptr;
			return (*this);
		}

		reverse_iterator	operator++(int) {
			reverse_iterator	tmp(*this);
			--_ptr;
			return (tmp);
		}

		reverse_iterator&	operator--() {
			++_ptr;
			return (*this);
		}

		reverse_iterator	operator--(int) {
			reverse_iterator	tmp(*this);
			++_ptr;
			return (tmp);
		}

		reverse_iterator&	operator+=(difference_type n) {
			_ptr -= n;
			return (*this);
		}

		reverse_iterator	operator+(difference_type n) const {
			return (reverse_iterator(_ptr - n));
		}

		reverse_iterator&	operator-=(difference_type n) {
			_ptr += n;
			return (*this);
		}

		reverse_iterator	operator-(difference_type n) const {
			return (reverse_iterator(_ptr + n));
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

}

#endif