#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"
#include "rbtree.hpp"

int	main(void) {
	ft::map<int, std::string>	m1;
	ft::pair<int, bool>			ret;

	ret = m1.insert(ft::make_pair(3, "one"));
	std::cout << "ret.first(int): " << ret.first << "\n";
	std::cout << "ret.second(bool): " << ret.second << "\n";
	ret = m1.insert(ft::make_pair(3, "one"));
	std::cout << "ret.first(int): " << ret.first << "\n";
	std::cout << "ret.second(bool): " << ret.second << "\n";
	m1.printMap();
	return (0);
}