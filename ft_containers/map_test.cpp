#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"
// #include "rbtree.hpp"

int	main(void) {
	// FT ITERATORS
	std::cout << "\n+++++++++ ITERATORS +++++++++\n";
	ft::map<int, std::string>						m1;
	ft::map<int, std::string>::iterator				it1;
	ft::map<int, std::string>::reverse_iterator		rit1;
	ft::pair<int, bool>								ret;
	std::map<int, std::string>						m2;
	std::map<int, std::string>::iterator			it2;
	std::map<int, std::string>::reverse_iterator	rit2;



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

	m2[0] = "zero";
	m2[1] = "one";
	m2[2] = "two";
	m2[3] = "three";
	m2[4] = "four";
	m2[5] = "five";

	std::cout << "\nFT: it1 = m1(begin())\n";
	it1 = m1.begin();
	std::cout << it1->first << ": " << it1->second << "\n";
	it2 = m2.begin();
	std::cout << "STD: it2 = m2(begin())\n";
	std::cout << it2->first << ": " << it2->second << "\n";
	++it1;
	std::cout << "FT: ++it1\n";
	std::cout << it1->first << ": " << it1->second << "\n";
	std::cout << "++it2\n";
	++it2;
	std::cout << it2->first << ": " << it2->second << "\n";

	std::cout << "\nFT: it1 = m1(end())\n";
	it1 = m1.end();
	it1--;
	std::cout << it1->first << ": " << it1->second << "\n";
	it2 = m2.end();
	it2--;
	std::cout << "STD: it2 = m2(end())\n";
	std::cout << it2->first << ": " << it2->second << "\n";

	// std::cout << "\nFT: rit1 = m1(rbegin()\n";
	// rit1 = m1.rbegin();
	// std::cout << rit1->first << ": " << rit1->second << "\n";
	rit2 = m2.rbegin();
	std::cout << "STD: rit2 = m2(rbegin()\n";
	std::cout << rit2->first << ": " << rit2->second << "\n";

	// std::cout << "\nFT: rit1 = m1(rend()\n";
	// rit1 = m1.rend();
	// std::cout << rit1->first << ": " << rit1->second << "\n";
	rit2 = m2.rend();
	std::cout << "STD: rit2 = m2(rend()\n";
	std::cout << rit2->first << ": " << rit2->second << "\n";

	return (0);
}