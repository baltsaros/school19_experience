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


	// ret = m1.insert(ft::make_pair(3, "three"));
	// std::cout << "ret.first(int): " << ret.first << "\n";
	// std::cout << "ret.second(bool): " << ret.second << "\n";
	// ret = m1.insert(ft::make_pair(3, "one"));
	// std::cout << "ret.first(int): " << ret.first << "\n";
	// std::cout << "ret.second(bool): " << ret.second << "\n";
	ret = m1.insert(ft::make_pair(0, "zero"));
	ret = m1.insert(ft::make_pair(1, "one"));
	ret = m1.insert(ft::make_pair(2, "two"));
	ret = m1.insert(ft::make_pair(3, "three"));
	ret = m1.insert(ft::make_pair(4, "four"));
	ret = m1.insert(ft::make_pair(5, "five"));
	m1.printMap();

	// m2[0] = 5;
	// m2[1] = 1;
	// m2[2] = 7;
	// m2[3] = 6;
	// m2[4] = 16;
	// m2[5] = 26;
	m2[0] = "zero";
	m2[1] = "one";
	m2[2] = "two";
	m2[3] = "three";
	m2[4] = "four";
	m2[4] = "five";
	std::cout << "\nft iterator\n";
	std::cout << "it1 = m1(begin()\n";
	it1 = m1.begin();
	std::cout << it1->first << ": " << it1->second << "\n";
	std::cout << "++it1\n";
	++it1;
	std::cout << it1->first << ": " << it1->second << "\n";
	std::cout << "\nstd iterator\n";
	std::cout << "it2 = m2(begin()\n";
	it2 = m2.begin();
	std::cout << it2->first << ": " << it2->second << "\n";
	std::cout << "++it2\n";
	++it2;
	std::cout << it2->first << ": " << it2->second << "\n";
	// ++it2;
	// std::cout << it2->first << ": " << it2->second << "\n";
	return (0);
}