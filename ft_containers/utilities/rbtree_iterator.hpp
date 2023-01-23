/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:58:27 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:58:28 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREE_ITERATOR_HPP
# define RBTREE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"

namespace ft {
	template <class Pair>
	struct Node;

	template <class Pair>
	class rbt_iterator {
	public:
		typedef Pair							value_type;
		typedef Pair*							pointer;
		typedef Pair&							reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;
		typedef	Node<Pair>						node;

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

		rbt_iterator(rbt_iterator const &src) {
			*this = src;
			return ;
		}

		rbt_iterator&	operator=(rbt_iterator const &rhs) {
			_ptr = rhs._ptr;
			return (*this);
		}


		reference	operator*() const {
			return (_ptr->value);
		}

		pointer	operator->() const {
			return &(_ptr->value);
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
		typedef const Pair					value_type;
		typedef const Pair*					pointer;
		typedef const Pair&					reference;
		typedef rbt_iterator<Pair>			iterator;
		typedef bidirectional_iterator_tag	iterator_category;
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
}

#endif