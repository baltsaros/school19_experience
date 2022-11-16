#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <exception>
# include <cstring>
# include "iterator.hpp"
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
		typedef Key							key_type;
		typedef T							mapped_type;
		typedef pair<const Key, T>			value_type;
		typedef std::size_t					size_type;
		typedef std::ptrdiff_t				difference_type;
		typedef Compare						key_compare;
		typedef Allocator					allocator_type;
		typedef value_type&					reference;
		typedef const value_type&			const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		// typedef iterator;
		// typedef const_iterator;
		// typedef reverse_iterator;
		// typedef const_reverse_iterator;

	};
}

#endif