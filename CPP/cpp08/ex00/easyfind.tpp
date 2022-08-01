#include <array>
#include <vector>
#include <list>
#include <string>
#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &container, int n) {
	typename T::iterator	it;
	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw(nothingFound());
	return (it);
}

const char*	nothingFound::what(void) const throw() {
	return (REDL "No occurence has been found!" NC);
}
