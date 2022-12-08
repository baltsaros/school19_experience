#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"
// #include "rbtree.hpp"

int	main(void) {
	ft::map<int, std::string>	m1;
	ft::map<int, std::string>::iterator	it1;
	ft::pair<int, bool>			ret;
	// std::map<int, int>	m2;
	// std::map<int, int>::iterator	it2;
	std::map<int, std::string>	m2;
	std::map<int, std::string>::iterator	it2;


	ret = m1.insert(ft::make_pair(3, "three"));
	// std::cout << "ret.first(int): " << ret.first << "\n";
	// std::cout << "ret.second(bool): " << ret.second << "\n";
	// ret = m1.insert(ft::make_pair(3, "one"));
	// std::cout << "ret.first(int): " << ret.first << "\n";
	// std::cout << "ret.second(bool): " << ret.second << "\n";
	ret = m1.insert(ft::make_pair(0, "one"));
	ret = m1.insert(ft::make_pair(1, "five"));
	ret = m1.insert(ft::make_pair(2, "one"));
	ret = m1.insert(ft::make_pair(3, "one"));
	ret = m1.insert(ft::make_pair(4, "one"));
	ret = m1.insert(ft::make_pair(5, "five"));
	m1.printMap();

	// m2[0] = 5;
	// m2[1] = 1;
	// m2[2] = 7;
	// m2[3] = 6;
	// m2[4] = 16;
	// m2[5] = 26;
	m2[0] = "one";
	m2[1] = "two";
	std::cout << "std iterator \n";
	it2 = m2.begin();
	std::cout << it2->first << ": " << it2->second << "\n";
	++it2;
	std::cout << it2->first << ": " << it2->second << "\n";
	// ++it2;
	// std::cout << it2->first << ": " << it2->second << "\n";
	std::cout << "ft iterator: \n";
	it1 = m1.begin();
	std::cout << it1->first << ": " << it1->second << "\n";
	++it1;
	std::cout << it1->first << ": " << it1->second << "\n";
	return (0);
}