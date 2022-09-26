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

namespace ft {
	template <class Key,
				class T,
				class Compare = std::less<Key>,
				class Allocator = std::allocator<pair<const Key, T> > >
	class map {

	};
}

#endif