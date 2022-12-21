#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "rbtree.hpp"
// # include <type_traits>

namespace ft {
	template <class Pair>
	struct Node;

	template <class Pair>
	class rbt_iterator {
	public:
		typedef Pair						value_type;
		typedef Pair*						pointer;
		typedef Pair&						reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t				difference_type;
		typedef	Node<Pair>					node;

	private:
		node	*_ptr;

		bool	_check_nil(node *tree) {
			if (!tree->left && !tree->right)
				return (true);
			return (false);
		}
			node*	_treeMin(node *tmp) const {
				if (!tmp)
					return (NULL);
				while (tmp->left && tmp->left->left)
					tmp = tmp->left;
				return (tmp);
			}

			node*	_treeMax(node *tmp) const {
				if (!tmp)
					return (NULL);
				while (tmp->right && tmp->right->right)
					tmp = tmp->right;
				return (tmp);
			}

	public:
		rbt_iterator() {
			_ptr = NULL;
			return ;
		}

		explicit rbt_iterator(node *ptr) {
			_ptr = ptr;
			return ;
		}

		~rbt_iterator() {};

		operator	rbt_iterator<Pair const>() const {
			return (rbt_iterator<Pair const>(this->_ptr));
		}

		rbt_iterator(rbt_iterator const &src) {
			*this = src;
			return ;
		}

		rbt_iterator&	operator=(rbt_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}


		reference	operator*() const {
			return (static_cast<node*>(_ptr)->value);
		}

		pointer	operator->() const {
			return &(static_cast<node*>(_ptr)->value);
		}

		rbt_iterator&	operator++() {
			if (_check_nil(_ptr))
				_ptr = _ptr->parent;
			else if (_ptr->right && _ptr->right->left)
				_ptr = _treeMin(_ptr->right);
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
			rbt_iterator	tmp = *this;

			this->operator++();
			return (tmp);
		}

		rbt_iterator&	operator--() {
			if (_check_nil(_ptr)) {
				_ptr = _ptr->parent;
				_ptr = _treeMax(_ptr);
			}
			else if (_ptr->left && _ptr->left->right)
				_ptr = _treeMax(_ptr->left);
			else {
				node	*tmp = _ptr->parent;

				while (!_check_nil(tmp) && _ptr == tmp->left) {
					_ptr = tmp;
					tmp = tmp->parent;
				}
				_ptr = tmp;
			}
			return (*this);
		}

		rbt_iterator	operator--(int) {
			rbt_iterator	tmp = *this;

			this->operator--();
			return (tmp);
		}

		node*	base() const {
			return (_ptr);
		}

		bool	operator==(rbt_iterator const &rhs) const {
			return (_ptr == rhs._ptr);
		}

		bool	operator!=(rbt_iterator const &rhs) const {
			return (_ptr != rhs._ptr);
		}
	};

template <class Pair>
class rbt_const_iterator {
	public:
		typedef Pair						value_type;
		typedef const Pair*						pointer;
		typedef const Pair&						reference;
		typedef rbt_iterator<Pair>				iterator;
		typedef bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t				difference_type;
		typedef	const Node<Pair>			node;

	private:
		node	*_ptr;

		bool	_check_nil(node *tree) {
			if (!tree->left && !tree->right)
				return (true);
			return (false);
		}
			node*	_treeMin(node *tmp) const {
				if (!tmp)
					return (NULL);
				while (tmp->left && tmp->left->left)
					tmp = tmp->left;
				return (tmp);
			}

			node*	_treeMax(node *tmp) const {
				if (!tmp)
					return (NULL);
				while (tmp->right && tmp->right->right)
					tmp = tmp->right;
				return (tmp);
			}

	public:
		rbt_const_iterator() {
			_ptr = NULL;
			return ;
		}

		explicit rbt_const_iterator(node *ptr) {
			_ptr = ptr;
			return ;
		}

		~rbt_const_iterator() {};

		rbt_const_iterator(const iterator &src) {
			_ptr = src.base();
			return ;
		}

		iterator	it_const_cast() {
			return (iterator(const_cast<typename iterator::node*>(_ptr)));
		}

		rbt_const_iterator&	operator=(rbt_const_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}

		reference	operator*() const {
			return (_ptr->value);
		}

		pointer	operator->() const {
			return &(_ptr->value);
		}

		rbt_const_iterator&	operator++() {
			if (_check_nil(_ptr))
				_ptr = _ptr->parent;
			else if (_ptr->right && _ptr->right->left)
				_ptr = _treeMin(_ptr->right);
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

		rbt_const_iterator	operator++(int) {
			rbt_const_iterator	tmp = *this;

			this->operator++();
			return (tmp);
		}

		rbt_const_iterator&	operator--() {
			if (_check_nil(_ptr)) {
				_ptr = _ptr->parent;
				_ptr = _treeMax(_ptr);
			}
			else if (_ptr->left && _ptr->left->right)
				_ptr = _treeMax(_ptr->left);
			else {
				node	*tmp = _ptr->parent;

				while (!_check_nil(tmp) && _ptr == tmp->left) {
					_ptr = tmp;
					tmp = tmp->parent;
				}
				_ptr = tmp;
			}
			return (*this);
		}

		rbt_const_iterator	operator--(int) {
			rbt_const_iterator	tmp = *this;

			this->operator--();
			return (tmp);
		}

		node*	base() const {
			return (_ptr);
		}

		bool	operator==(rbt_const_iterator const &rhs) const {
			return (_ptr == rhs._ptr);
		}

		bool	operator!=(rbt_const_iterator const &rhs) const {
			return (_ptr != rhs._ptr);
		}
	};

	// template <class Iter>
	// class reverse_iterator {

	// private:
	// 	Iter	_t;

	// protected:
	// 	Iter	_ptr;
	// 	typedef iterator_traits<Iter>	itraits;

	// public:
	// 	typedef Iter								iterator_type;
	// 	typedef typename itraits::difference_type	difference_type;
	// 	typedef typename itraits::reference			reference;
	// 	typedef typename itraits::pointer			pointer;
	// 	typedef typename itraits::value_type		value_type;
	// 	typedef typename itraits::iterator_category	iterator_category;

	// 	reverse_iterator() : _ptr(NULL), _t(NULL) {
	// 	// reverse_iterator() {
	// 	// 	this->_ptr = NULL;
	// 	// 	this->_t = NULL;
	// 		return ;
	// 	}

	// 	explicit reverse_iterator(iterator_type x) {
	// 		this->_ptr = x;
	// 		this->_t = x;
	// 		return ;
	// 	}

	// 	template <class U>
	// 	reverse_iterator(const reverse_iterator<U> &other) {
	// 		this->_ptr = other.base();
	// 		this->_t = other.base();
	// 		return ;
	// 	}

	// 	template <class U>
	// 	reverse_iterator&	operator=(const reverse_iterator<U> &rhs) {
	// 		this->_ptr = rhs.base();
	// 		this->_t = this->_ptr;
	// 		return (*this);
	// 	}

	// 	iterator_type	base() const {
	// 		return (this->_ptr);
	// 	}

	// 	reference	operator*() const {
	// 		Iter	tmp;

	// 		tmp = _ptr;
	// 		--tmp;
	// 		return (*tmp);
	// 	}

	// 	Iter	operator->() const {
	// 		Iter	tmp;

	// 		tmp = _ptr;
	// 		--tmp;
	// 		return (tmp);
	// 	}

	// 	reference	operator[](difference_type n) const {
	// 		return *(*this + n);
	// 	}

	// 	reverse_iterator&	operator++() {
	// 		--(this->_ptr);
	// 		return (*this);
	// 	}

	// 	reverse_iterator	operator++(int) {
	// 		reverse_iterator	tmp(*this);
	// 		--(this->_ptr);
	// 		return (tmp);
	// 	}

	// 	reverse_iterator&	operator--() {
	// 		++(this->_ptr);
	// 		return (*this);
	// 	}

	// 	reverse_iterator	operator--(int) {
	// 		reverse_iterator	tmp(*this);
	// 		++(this->_ptr);
	// 		return (tmp);
	// 	}

	// 	reverse_iterator&	operator+=(difference_type n) {
	// 		this->_ptr -= n;
	// 		return (*this);
	// 	}

	// 	reverse_iterator	operator+(difference_type n) const {
	// 		return (reverse_iterator(this->_ptr - n));
	// 	}

	// 	reverse_iterator&	operator-=(difference_type n) {
	// 		this->_ptr += n;
	// 		return (*this);
	// 	}

	// 	reverse_iterator	operator-(difference_type n) const {
	// 		return (reverse_iterator(this->_ptr + n));
	// 	}
	// };

	// template <class Iter1, class Iter2>
	// bool	operator==(const reverse_iterator<Iter1> &lhs,
	// 					const reverse_iterator<Iter2> &rhs){
	// 	return (lhs.base() == rhs.base());
	// }

	// template <class Iter1, class Iter2>
	// bool	operator!=(const reverse_iterator<Iter1> &lhs,
	// 					const reverse_iterator<Iter2> &rhs){
	// 	return (lhs.base() != rhs.base());
	// }

	// template <class Iter1, class Iter2>
	// bool	operator<(const reverse_iterator<Iter1> &lhs,
	// 					const reverse_iterator<Iter2> &rhs){
	// 	return (lhs.base() > rhs.base());
	// }

	// template <class Iter1, class Iter2>
	// bool	operator<=(const reverse_iterator<Iter1> &lhs,
	// 					const reverse_iterator<Iter2> &rhs){
	// 	return (lhs.base() >= rhs.base());
	// }

	// template <class Iter1, class Iter2>
	// bool	operator>(const reverse_iterator<Iter1> &lhs,
	// 					const reverse_iterator<Iter2> &rhs){
	// 	return (lhs.base() < rhs.base());
	// }

	// template <class Iter1, class Iter2>
	// bool	operator>=(const reverse_iterator<Iter1> &lhs,
	// 					const reverse_iterator<Iter2> &rhs){
	// 	return (lhs.base() <= rhs.base());
	// }
}

#endif