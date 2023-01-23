/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:57:44 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:57:45 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include <exception>
# include <cstring>
# include <iostream>
# include "../utilities/enable_if.hpp"
# include "../utilities/is_integral.hpp"
# include "../utilities/lexi_compare.hpp"
# include "../utilities/pair.hpp"
# include "../utilities/rbtree_set.hpp"

namespace ft {
	template <class Key,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<Key> >
	class set {
		public:
		// TYPEDEFS
		typedef Key											key_type;
		typedef Key											value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
		typedef	RBTree<Key, Compare, Allocator>				tree;
		typedef typename tree::const_iterator				iterator;
		typedef typename tree::const_iterator				const_iterator;
		typedef typename tree::const_reverse_iterator		reverse_iterator;
		typedef typename tree::const_reverse_iterator		const_reverse_iterator;

		class	value_compare {
			protected:
				key_compare	_compare;

			public:
				value_compare(key_compare comp) : _compare(comp) {}
				bool	operator()(const value_type x, const value_type& y) const {
					return (_compare(x, y));
				}
		};

		private:
			allocator_type	_alloc;
			tree			_tree;
			key_compare		_compare;
			size_type		_size;

		public:
			// CONSTRUCTORS
			set() {};

			explicit set(const Compare& comp, const Allocator& alloc = Allocator()) :
				_alloc(alloc), _tree(comp, alloc), _compare(comp), _size(0) {}

			template <class InputIt>
			set(InputIt first, InputIt last, const Compare& comp = Compare(),
				const Allocator& alloc = Allocator(),
				typename enable_if<!is_integral<InputIt>::value>::type* = NULL) :
				 _alloc(alloc), _tree(comp, alloc), _compare(comp), _size(0) {
				insert(first, last);
			}

			set(const set& other) {
				*this = other;
			}

			// DESCTRUCTOR
			~set() {}

			// ASSIGN OPERATOR
			set&	operator=(const set& src) {
				_alloc = src._alloc;
				_compare = src._compare;
				_size = src._size;
				_tree = src._tree;
				return (*this);
			}

			// GET ALLOCATOR
			allocator_type	get_allocator() const {
				return (_alloc);
			}

			// ITERATORS
			iterator	begin() {
				return (_tree.begin());
			}

			const_iterator	begin() const {
				return (_tree.begin());
			}

			iterator	end() {
				return (_tree.end());
			}

			const_iterator	end() const {
				return (_tree.end());
			}

			reverse_iterator	rbegin() {
				return (_tree.rbegin());
			}

			const_reverse_iterator	rbegin() const {
				return (_tree.rbegin());
			}

			reverse_iterator	rend() {
				return (_tree.rend());
			}

			const_reverse_iterator	rend() const {
				return (_tree.rend());
			}

			// CAPACITY
			bool	empty() const {
				return (_tree.empty());
			}

			size_type	size() const {
				return (_tree.size());
			}

			size_type	max_size() const {
				return (_tree.max_size());
			}

			// MODIFIERS
			void	clear() {
				_tree.clear();
			}

			pair<iterator, bool>	insert(const value_type& value) {
				return (_tree.insert(value));
			}

			iterator	insert(iterator pos, const value_type& value) {
				return (_tree.insert(pos, value));
			}

			template <class InputIt>
			void	insert(InputIt first, InputIt last,
				typename enable_if<!is_integral<InputIt>::value>::type* = NULL) {
				_tree.insert(first, last);
			}

			void	erase(iterator pos) {
				_tree.erase(pos);
			}

			void	erase(iterator first, iterator last) {
				_tree.erase(first, last);
			}

			size_type	erase(const Key& key) {
				return (_tree.erase(key));
			}

			void	swap(set& other) {
				_tree.swap(other._tree);
			}

			// LOOKUPS
			size_type	count(const Key& key) const {
				return (_tree.count(key));
			}

			iterator	find(const Key& key) {
				return (_tree.find(key));
			}

			const_iterator	find(const Key& key) const {
				return (_tree.find(key));
			}

			pair<iterator, iterator>	equal_range(const Key& key) {
				return (_tree.equal_range(key));
			}

			pair<const_iterator, const_iterator>	equal_range(const Key& key) const {
				return (_tree.equal_range(key));
			}

			iterator	lower_bound(const Key& key) {
				return (_tree.lower_bound(key));
			}

			const_iterator	lower_bound(const Key& key) const {
				return (_tree.lower_bound(key));
			}

			iterator	upper_bound(const Key& key) {
				return (_tree.upper_bound(key));
			}

			const_iterator	upper_bound(const Key& key) const {
				return (_tree.upper_bound(key));
			}

			// OBSERVERS
			key_compare	key_comp() const {
				return (_tree.key_comp());
			}

			value_compare	value_comp() const {
				return (value_compare(_tree.key_comp()));
			}

			// UTILS
			void	printSet() {
				_tree.printNode();
			}

			// FRIENDS
			template <class KeyF, class CompareF, class AllocF>
			friend bool	operator==(const set<KeyF, CompareF, AllocF>& lhs,
							const set<KeyF, CompareF, AllocF>& rhs);

			template <class KeyF, class CompareF, class AllocF>
			friend bool	operator<(const set<KeyF, CompareF, AllocF>& lhs,
							const set<KeyF, CompareF, AllocF>& rhs);

			// EXCEPTIONS
			class OutOfRange: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set.at() is out of range");
				}
			};

			class OutOfBounds: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set[] index is out of bounds");
				}
			};

			class EmptyContainer: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set is empty");
				}
			};

			class LengthError: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::set begin is ahead of end");
				}
			};
	};

	template <class Key, class Compare, class Alloc>
	bool	operator==(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return (lhs._tree == rhs._tree);
	}

	template <class Key, class Compare, class Alloc>
	bool	operator!=(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool	operator<(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return (lhs._tree < rhs._tree);
	}

	template <class Key, class Compare, class Alloc>
	bool	operator>(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return (!(lhs == rhs) && !(lhs < rhs));
	}

	template <class Key, class Compare, class Alloc>
	bool	operator<=(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return !(lhs > rhs);
	}

	template <class Key, class Compare, class Alloc>
	bool	operator>=(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template <class Key, class Compare, class Alloc>
	void	swap(const set<Key, Compare, Alloc>& lhs,
						const set<Key, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}
};

#endif