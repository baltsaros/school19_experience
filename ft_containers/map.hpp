#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <exception>
# include <cstring>
# include <iostream>
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexi_compare.hpp"
# include "pair.hpp"
# include "rbtree.hpp"

namespace ft {
	template <class Key,
				class T,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<pair<const Key, T> > >
	class map {
		public:
		// TYPEDEFS
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef pair<const Key, T>							value_type;
		typedef Node<Key, value_type>						node;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef value_type&									reference;
		typedef const value_type&							const_reference;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
		typedef	RBTree<Key, value_type, Compare, Allocator>	tree;
		typedef typename tree::iterator						iterator;
		typedef typename tree::const_iterator				const_iterator;
		typedef typename tree::reverse_iterator				reverse_iterator;
		typedef typename tree::const_reverse_iterator		const_reverse_iterator;

		private:
			allocator_type	_alloc;
			tree			_tree;
			key_compare		_compare;
			size_type		_size;

		public:
			// CONSTRUCTORS
			map() {};

			explicit map(const Compare& comp, const Allocator& alloc = Allocator()) :
				_alloc(alloc), _tree(comp, alloc), _compare(comp), _size(0) {}

			// template <class InputIt>
			// map(InputIt first, InputIt last, const Compare& comp = Compare(),
			// 	const Allocator& alloc = Allocator()) {}

			map(const map& other) {
					*this = other;
			}

			// DESCTRUCTOR
			~map() {}

			// ASSIGN OPERATOR
			map&	operator=(const map& src) {
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

			// ELEMENT ACCESS
			T&	at(const Key& key) {
				node	*tmp = nullptr;

				tmp = _tree.search(key);
				if (!tmp || (!tmp->left && !tmp->right))
					throw OutOfRange();
				return (tmp->value->second);
			}

			// const T&	at(const Key& key) const {

			// }

			// T&	operator[](const Key& key) {

			// }

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

			// MODIFIERS
			pair<Key, bool>	insert(const value_type& value) {
				return (_tree.insert(value));
			}

			// EXCEPTIONS
			class OutOfRange: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::map.at() is out of range");
				}
			};

			class OutOfBounds: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::map[] index is out of bounds");
				}
			};

			class EmptyContainer: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::map is empty");
				}
			};

			class LengthError: public std::exception {
				const char*	what(void) const throw() {
					return ("ft::map begin is ahead of end");
				}
			};

			// UTILS
			void	printMap() {
				_tree.printNode();
			}

	};
}

#endif