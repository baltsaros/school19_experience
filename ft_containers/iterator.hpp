#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"

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

	public:
		typedef Iter											iterator_type;
		typedef typename iterator_traits<Iter>::difference_type	difference_type;
		typedef typename iterator_traits<Iter>::reference		reference;
		typedef typename iterator_traits<Iter>::pointer			pointer;
		typedef typename iterator_traits<Iter>::value_type		value_type;

		vt_iterator() {
			this->_ptr = NULL;
			return ;
		}

		vt_iterator(const Iter &ptr) {
			this->_ptr = ptr;
			return ;
		}

		~vt_iterator() {};

		vt_iterator(const vt_iterator &src) {
			*this = src;
			return ;
		}

		vt_iterator&	operator=(vt_iterator<Iter> const &rhs) {
			this->_ptr = rhs._ptr;
			return *(this);
		}

		reference	operator*() const {
			return *(this->_ptr);
		}

		pointer	operator->() const {
			return (this->_ptr);
		}
	};

	template <class Iter>
	class const_iterator: public iterator
		<typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference> {

	protected:
		Iter	_ptr;

	public:
		typedef Iter											iterator_type;
		typedef typename iterator_traits<Iter>::difference_type	difference_type;
		typedef typename iterator_traits<Iter>::reference		reference;
		typedef typename iterator_traits<Iter>::pointer			pointer;
		typedef typename iterator_traits<Iter>::value_type		value_type;

		const_iterator() {
			this->_ptr = NULL;
			return ;
		}

		const_iterator(const Iter &ptr) {
			this->_ptr = ptr;
			return ;
		}

		~const_iterator() {};

		const_iterator&	operator=(const_iterator<Iter> const &rhs) {
			this->_ptr = rhs._ptr;
			return (*this);
		}

		reference	operator*() {
			return *(this->_ptr);
		}

		pointer	operator->() {
			return (this->_ptr);
		}
	};


}

#endif