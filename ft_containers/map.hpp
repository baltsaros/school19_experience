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
		// typedef reverse_iterator;
		// typedef const_reverse_iterator;

		private:
			allocator_type	_alloc;
			tree			_tree;
			key_compare		_compare;
			size_type		_size;

		public:
			map() {};

			explicit map(const Compare& comp, const Allocator& alloc = Allocator()) :
				_alloc(alloc), _tree(comp, alloc), _compare(comp), _size(0) {}

			// template <class InputIt>
			// map(InputIt first, InputIt last, const Compare& comp = Compare(),
			// 	const Allocator& alloc = Allocator()) {}

			map(const map& other) {
					*this = other;
			}

			~map() {}

			map&	operator=(const map& src) {
				_alloc = src._alloc;
				_compare = src._compare;
				_size = src._size;
				_tree = src._tree;
				return (*this);
			}

			pair<Key, bool>	insert(const value_type& value) {
				return (_tree.insert(value));
			}

			void	printMap() {
				_tree.printNode();
			}

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

			
	};
}

#endif