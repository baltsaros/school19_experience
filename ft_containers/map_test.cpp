#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"
// #include "rbtree.hpp"

template <class Pair>
void	printPair(Pair it) {
	std::cout << it->first << ": " << it->second << std::endl;
}

template <class T>
void	printValue(T value) {
	std::cout << value << std::endl;
}

int	main(void) {
	ft::map<int, std::string>						m1;
	ft::map<int, std::string>::iterator				it1;
	ft::map<int, std::string>::reverse_iterator		rit1;
	ft::pair<int, bool>								ret;
	std::map<int, std::string>						m2;
	std::map<int, std::string>::iterator			it2;
	std::map<int, std::string>::reverse_iterator	rit2;

	ret = m1.insert(ft::make_pair(0, "zero"));
	ret = m1.insert(ft::make_pair(1, "one"));
	ret = m1.insert(ft::make_pair(2, "two"));
	ret = m1.insert(ft::make_pair(3, "three"));
	ret = m1.insert(ft::make_pair(4, "four"));
	ret = m1.insert(ft::make_pair(5, "five"));

	m2[0] = "zero";
	m2[1] = "one";
	m2[2] = "two";
	m2[3] = "three";
	m2[4] = "four";
	m2[5] = "five";

	// ELEMENT ACCES
	// {
		// std::cout << "\n+++++++++ ELEMENT ACCES +++++++++\n";
		// std::cout << "\n+++ at() +++\n";
		// std::cout << "FT: m1.at(0)\n";
		// std::cout << m1.at(0) << "\n";
		// std::cout << "STD: m2.at(0)\n";
		// std::cout << m2.at(0) << "\n";
		// std::cout << "FT: m1.at(1)\n";
		// std::cout << m1.at(1) << "\n";
		// std::cout << "STD: m2.at(1)\n";
		// std::cout << m2.at(1) << "\n";
		// std::cout << "FT: m1.at(10) - (out of range)\n";
		// std::cout << m1.at(10) << "\n";
		// std::cout << "STD: m2.at(10) - (out of range)\n";
		// std::cout << m2.at(10) << "\n";

	// 	std::cout << "\n+++ operator[] +++\n";

	// 	std::cout << "FT: m1[0]\n";
	// 	printValue(m1[0]);
	// 	std::cout << "STD: m2[0]\n";
	// 	printValue(m2[0]);
	// 	std::cout << "FT: m1[6] - (out of range)\n";
	// 	printValue(m1[6]);
	// 	std::cout << "STD: m2[6] - (out of range)\n";
	// 	printValue(m2[6]);
	// }

	// FT ITERATORS
	// {
	// 	std::cout << "\n+++++++++ ITERATORS +++++++++\n";
		// std::cout << "\n+++ begin() +++\n";
	// 	std::cout << "FT: it1 = m1(begin())\n";
	// 	it1 = m1.begin();
	// 	printPair(it1);
	// 	std::cout << "STD: it2 = m2(begin())\n";
	// 	it2 = m2.begin();
	// 	printPair(it2);

	// 	std::cout << "\n+++ preincrement +++\n";
	// 	std::cout << "FT: ++it1\n";
	// 	printPair(++it1);
	// 	printPair(it1);
	// 	std::cout << "STD: ++it2\n";
	// 	printPair(++it2);
	// 	printPair(it2);

	// 	std::cout << "\n+++ predecrement +++\n";
	// 	std::cout << "FT: --it1\n";
	// 	printPair(--it1);
	// 	printPair(it1);
	// 	std::cout << "STD: --it2\n";
	// 	printPair(--it2);
	// 	printPair(it2);

	// 	std::cout << "\n+++ postincrement +++\n";
	// 	std::cout << "FT: it1++\n";
	// 	printPair(it1++);
	// 	std::cout << "FT: it1\n";
	// 	printPair(it1);
	// 	std::cout << "STD: it2++\n";
	// 	printPair(it2++);
	// 	std::cout << "STD: it2\n";
	// 	printPair(it2);

	// 	std::cout << "\n+++ postdecrement +++\n";
	// 	std::cout << "FT: it1--\n";
	// 	printPair(it1--);
	// 	std::cout << "FT: it1\n";
	// 	printPair(it1);
	// 	std::cout << "STD: it2--\n";
	// 	printPair(it2--);
	// 	std::cout << "STD: it2\n";
	// 	printPair(it2);

	// 	std::cout << "\n+++ end() +++\n";
	// 	std::cout << "FT: it1 = m1(end())\n";
	// 	it1 = m1.end();
	// 	std::cout << "it1--\n";
	// 	it1--;
	// 	printPair(it1);
	// 	it2 = m2.end();
	// 	std::cout << "STD: it2 = m2(end())\n";
	// 	std::cout << "it2--\n";
	// 	it2--;
	// 	printPair(it2);

	// 	std::cout << "\n+++ rbegin() +++\n";
	// 	std::cout << "FT: rit1 = m1(rbegin()\n";
	// 	rit1 = m1.rbegin();
	// 	printPair(rit1);
	// 	std::cout << "STD: rit2 = m2(rbegin()\n";
	// 	rit2 = m2.rbegin();
	// 	printPair(rit1);

	// 	std::cout << "\n+++ rend() +++\n";
	// 	std::cout << "FT: rit1 = m1(rend()\n";
	// 	rit1 = m1.rend();
	// 	std::cout << "rit1++\n";
	// 	rit1++;
	// 	printPair(rit1);
	// 	std::cout << "STD: rit2 = m2(rend()\n";
	// 	rit2 = m2.rend();
	// 	std::cout << "rit2++\n";
	// 	rit2++;
	// 	printPair(rit2);
	// }

	// CAPACITY
	{
		std::cout << "\n+++++++++ CAPACITY +++++++++\n";
		std::cout << "\n+++ empty() +++\n";
		std::cout << "FT: m1.empty()\n";
		std::cout << m1.empty() << "\n";
		std::cout << "STD: m2.empty()\n";
		std::cout << m2.empty() << "\n";

		std::cout << "\nCreating empty m3(ft) and m4 (std)\n";
		ft::map<int, std::string>						m3;
		std::map<int, std::string>						m4;

		std::cout << "FT: m3.empty()\n";
		std::cout << m3.empty() << "\n";
		std::cout << "STD: m4.empty()\n";
		std::cout << m4.empty() << "\n";


		std::cout << "\n+++ size() +++\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";
		std::cout << "FT: m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "STD: m4.size()\n";
		std::cout << m4.size() << "\n";

		std::cout << "\nerase(3): deleting one element\n";
		std::cout << m1.erase(3) << std::endl;
		std::cout << m2.erase(3) << std::endl;
		std::cout << "FT: m1.empty()\n";
		std::cout << m1.empty() << "\n";
		std::cout << "STD: m2.empty()\n";
		std::cout << m2.empty() << "\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";

		std::cout << "\nerase(10): deleting non-existing element\n";
		std::cout << m1.erase(10) << std::endl;
		std::cout << m2.erase(10) << std::endl;
		std::cout << "FT: m1.empty()\n";
		std::cout << m1.empty() << "\n";
		std::cout << "STD: m2.empty()\n";
		std::cout << m2.empty() << "\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";

		std::cout << "\nclear(): deleting all elements\n";
		m1.clear();
		m2.clear();
		std::cout << "FT: m1.empty()\n";
		std::cout << m1.empty() << "\n";
		std::cout << "STD: m2.empty()\n";
		std::cout << m2.empty() << "\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";

		std::cout << "\n+++ max_size() +++\n";
		std::cout << "FT: m1.max_size()\n";
		std::cout << m1.max_size() << "\n";
		std::cout << "STD: m2.max_size()\n";
		std::cout << m2.max_size() << "\n";
	}
	return (0);
}