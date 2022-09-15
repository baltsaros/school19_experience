#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"
# include <type_traits>

namespace ft {
	template <class Iterator>
	class reverse_iterator: public iterator
		<typename iterator_traits<Iterator>::iterator_category,
		typename iterator_traits<Iterator>::value_type,
		typename iterator_traits<Iterator>::difference_type,
		typename iterator_traits<Iterator>::pointer,
		typename iterator_traits<Iterator>::reference> {

	protected:
		Iterator	_ptr;

	public:
		typedef Iterator											iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::reference		reference;
		typedef typename iterator_traits<Iterator>::pointer			pointer;
	};

	template <class Iter>
	class vt_iterator: public iterator
		<typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference> {

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

		vt_iterator() {
			this->_ptr = NULL;
			return ;
		}

		vt_iterator(const Iter &ptr) {
			this->_ptr = ptr;
			return ;
		}

		~vt_iterator() {};

		vt_iterator(vt_iterator const &src) {
			*this = src;
			return ;
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

		const	Iter&	base() const {
			return (this->_ptr);
		}
	};

}

#endif