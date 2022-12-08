#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "rbtree.hpp"
// # include <type_traits>

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
			return (tmp);
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

	template <class Iter, class Pair>
	class rbt_iterator: public iterator
		<typename iterator_traits<Pair>::iterator_category,
		typename iterator_traits<Pair>::value_type,
		typename iterator_traits<Pair>::difference_type,
		typename iterator_traits<Pair>::pointer,
		typename iterator_traits<Pair>::reference> {

	public:
		typedef Node<Iter, Pair>					node;
		typedef iterator_traits<Pair>				itraits;
		typedef Iter								iterator_type;
		typedef typename itraits::difference_type	difference_type;
		typedef typename itraits::reference			reference;
		typedef typename itraits::pointer			pointer;
		typedef typename itraits::value_type		value_type;
		typedef typename itraits::iterator_category	iterator_category;

	private:
		node	*_ptr;

		bool	_check_nil(node *tree) {
			if (!tree->left && !tree->right)
				return (true);
			return (false);
		}

	public:

		rbt_iterator() {
			_ptr = nullptr;
			return ;
		}

		rbt_iterator(const node &ptr) {
			_ptr = ptr;
			return ;
		}

		~rbt_iterator() {};

		rbt_iterator(rbt_iterator const &src) {
			*this = src;
			return ;
		}

		rbt_iterator&	operator=(rbt_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}

		reference	operator*() const {
			return *(_ptr->value);
		}

		pointer	operator->() const {
			return (_ptr->value);
		}

		rbt_iterator&	operator++() {
			if (_check_nil(_ptr))
				_ptr = _ptr->parent;
			else if (_ptr->right && _ptr->right->left)
				_ptr = _ptr->findMin(ptr->right);
			else {
				node	*tmp = _ptr->parent;

				while (!_check_nil(tmp) && _ptr == tmp->right) {
					_ptr = tmp;
					tmp = tmp->parent;
				}
				_ptr = tmp;
			}
			return (*this);
		}

		rbt_iterator	operator++(int) {
			return (rbt_iterator(this->_ptr++));
		}

		rbt_iterator&	operator--() {
			--(this->_ptr);
			return (*this);
		}

		rbt_iterator	operator--(int) {
			return (rbt_iterator(this->_ptr--));
		}

		reference	operator[](difference_type n) const {
			return (this->_ptr[n]);
		}

		rbt_iterator&	operator+=(difference_type n) {
			this->_ptr += n;
			return (*this);
		}

		rbt_iterator	operator+(difference_type n) const {
			return (rbt_iterator(this->_ptr + n));
		}

		rbt_iterator&	operator-=(difference_type n) {
			this->_ptr -= n;
			return (*this);
		}

		rbt_iterator	operator-(difference_type n) const {
			return (rbt_iterator(this->_ptr - n));
		}

		const node&	base() const {
			return (this->_ptr);
		}

		bool	operator==(rbt_iterator const &rhs) const {
			return (this->_ptr == rhs._ptr);
		}

		bool	operator!=(rbt_iterator const &rhs) const {
			return (this->_ptr != rhs._ptr);
		}
	};
}

#endif