#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"
// #include "rbtree.hpp"

template <class InputIt>
void	printIter(InputIt it) {
	std::cout << it->first << ": " << it->second << std::endl;
}

template <class Pair>
void	printPair(Pair comp) {
	std::cout << comp.first << ": " << comp.second << std::endl;
}

template <class T>
void	printValue(T value) {
	std::cout << value << std::endl;
}


template <class Map, class InputIt>
void	printMap(Map map, InputIt it, std::string type) {
	for (it = map.begin(); it != map.end(); it++) {
		std::cout << type << ": ";
		printIter(it);
	}
}

int	main(void) {
	ft::map<int, std::string>						m1;
	ft::map<int, std::string>::iterator				it1;
	ft::map<int, std::string>::reverse_iterator		rit1;
	std::map<int, std::string>						m2;
	std::map<int, std::string>::iterator			it2;
	std::map<int, std::string>::reverse_iterator	rit2;

	m1.insert(ft::make_pair(0, "zero"));
	m1.insert(ft::make_pair(1, "one"));
	m1.insert(ft::make_pair(2, "two"));
	m1.insert(ft::make_pair(3, "three"));
	m1.insert(ft::make_pair(4, "four"));
	m1.insert(ft::make_pair(5, "five"));

	m2.insert(std::make_pair(0, "zero"));
	m2.insert(std::make_pair(1, "one"));
	m2.insert(std::make_pair(2, "two"));
	m2.insert(std::make_pair(3, "three"));
	m2.insert(std::make_pair(4, "four"));
	m2.insert(std::make_pair(5, "five"));

	// ELEMENT ACCES
	{
		std::cout << "\n+++++++++ ELEMENT ACCES +++++++++\n";
		std::cout << "\n+++ at() +++\n";
		std::cout << "FT: m1.at(0)\n";
		std::cout << m1.at(0) << "\n";
		std::cout << "STD: m2.at(0)\n";
		std::cout << m2.at(0) << "\n";
		std::cout << "FT: m1.at(1)\n";
		std::cout << m1.at(1) << "\n";
		std::cout << "STD: m2.at(1)\n";
		std::cout << m2.at(1) << "\n";
		// std::cout << "FT: m1.at(10) - (out of range)\n";
		// std::cout << m1.at(10) << "\n";
		// std::cout << "STD: m2.at(10) - (out of range)\n";
		// std::cout << m2.at(10) << "\n";

		std::cout << "\n+++ operator[] +++\n";

		std::cout << "FT: m1[0]\n";
		printValue(m1[0]);
		std::cout << "STD: m2[0]\n";
		printValue(m2[0]);
		std::cout << "FT: m1[6] - (out of range)\n";
		printValue(m1[6]);
		std::cout << "STD: m2[6] - (out of range)\n";
		printValue(m2[6]);
	}

	// FT ITERATORS
	{
		std::cout << "\n+++++++++ ITERATORS +++++++++\n";
		std::cout << "\n+++ begin() +++\n";
		std::cout << "FT: it1 = m1(begin())\n";
		it1 = m1.begin();
		printIter(it1);
		std::cout << "STD: it2 = m2(begin())\n";
		it2 = m2.begin();
		printIter(it2);

		std::cout << "\n+++ preincrement +++\n";
		std::cout << "FT: ++it1\n";
		printIter(++it1);
		printIter(it1);
		std::cout << "STD: ++it2\n";
		printIter(++it2);
		printIter(it2);

		std::cout << "\n+++ predecrement +++\n";
		std::cout << "FT: --it1\n";
		printIter(--it1);
		printIter(it1);
		std::cout << "STD: --it2\n";
		printIter(--it2);
		printIter(it2);

		std::cout << "\n+++ postincrement +++\n";
		std::cout << "FT: it1++\n";
		printIter(it1++);
		std::cout << "FT: it1\n";
		printIter(it1);
		std::cout << "STD: it2++\n";
		printIter(it2++);
		std::cout << "STD: it2\n";
		printIter(it2);

		std::cout << "\n+++ postdecrement +++\n";
		std::cout << "FT: it1--\n";
		printIter(it1--);
		std::cout << "FT: it1\n";
		printIter(it1);
		std::cout << "STD: it2--\n";
		printIter(it2--);
		std::cout << "STD: it2\n";
		printIter(it2);

		std::cout << "\n+++ end() +++\n";
		std::cout << "FT: it1 = m1(end())\n";
		it1 = m1.end();
		std::cout << "it1--\n";
		it1--;
		printIter(it1);
		it2 = m2.end();
		std::cout << "STD: it2 = m2(end())\n";
		std::cout << "it2--\n";
		it2--;
		printIter(it2);

		std::cout << "\n+++ rbegin() +++\n";
		std::cout << "FT: rit1 = m1(rbegin()\n";
		rit1 = m1.rbegin();
		printIter(rit1);
		std::cout << "STD: rit2 = m2(rbegin()\n";
		rit2 = m2.rbegin();
		printIter(rit1);

		std::cout << "\n+++ rend() +++\n";
		std::cout << "FT: rit1 = m1(rend()\n";
		rit1 = m1.rend();
		printIter(rit1);
		// std::cout << "rit1++\n";
		// rit1++;
		// printIter(rit1);
		std::cout << "STD: rit2 = m2(rend()\n";
		rit2 = m2.rend();
		printIter(rit2);
		// std::cout << "rit2++\n";
		// rit2++;
		// printIter(rit2);
	}

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

		std::cout << "\n+++ max_size() +++\n";
		std::cout << "FT: m1.max_size()\n";
		std::cout << m1.max_size() << "\n";
		std::cout << "STD: m2.max_size()\n";
		std::cout << m2.max_size() << "\n";
	}

	// MODIFIERS
	{
		ft::map<int, std::string>						m3;
		std::map<int, std::string>						m4;

		std::cout << "\n+++++++++ MODIFIERS +++++++++\n";
		std::cout << "\n+++ clear() +++\n";
		std::cout << "FT: m1.empty()\n";
		std::cout << m1.empty() << "\n";
		std::cout << "STD: m2.empty()\n";
		std::cout << m2.empty() << "\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";
		m1.clear();
		m2.clear();
		std::cout << "after clear():\n";
		std::cout << "FT: m1.empty()\n";
		std::cout << m1.empty() << "\n";
		std::cout << "STD: m2.empty()\n";
		std::cout << m2.empty() << "\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";

		std::cout << "\n+++ insert(pair) +++\n";
		m1.insert(ft::make_pair(0, "zero"));
		m1.insert(ft::make_pair(1, "one"));
		m1.insert(ft::make_pair(2, "two"));
		m1.insert(ft::make_pair(3, "three"));
		m1.insert(ft::make_pair(4, "four"));
		m1.insert(ft::make_pair(5, "five"));
		for (it1 = m1.begin(); it1 != m1.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}

		m2.insert(std::make_pair(0, "zero"));
		m2.insert(std::make_pair(1, "one"));
		m2.insert(std::make_pair(2, "two"));
		m2.insert(std::make_pair(3, "three"));
		m2.insert(std::make_pair(4, "four"));
		m2.insert(std::make_pair(5, "five"));
		for (it2 = m2.begin(); it2 != m2.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}

		std::cout << "\n+++ insert(it, pair) +++\n";
		it1 = m3.begin();
		it2 = m4.begin();
		// it1 = m3.end();
		// it2 = m4.end();
		std::cout << "\nEmpty maps, it = m.begin()\n";
		std::cout << "insert(it, make_pair(2, \"two\")\n";
		it1 = m3.insert(it1, ft::make_pair(2, "two"));
		it2 = m4.insert(it2, std::make_pair(2, "two"));
		std::cout << "FT: it1\n";
		printIter(it1);
		std::cout << "STD: it2\n";
		printIter(it2);
		std::cout << "FT: m3.at(2)\n";
		printValue(m3.at(2));
		std::cout << "STD: m4.at(2)\n";
		printValue(m4.at(2));

		it1 = m1.begin();
		it2 = m2.begin();
		// it1 = m3.end();
		// it2 = m4.end();
		std::cout << "\nFilled maps, it = m.begin()\n";
		std::cout << "insert(it, make_pair(2, \"aaa\")\n";
		it1 = m1.insert(it1, ft::make_pair(2, "aaa"));
		it2 = m2.insert(it2, std::make_pair(2, "aaa"));
		std::cout << "FT: it1\n";
		printIter(it1);
		std::cout << "STD: it2\n";
		printIter(it2);
		printValue(m1.at(0));
		printValue(m1.at(1));
		std::cout << "FT: m1.at(2)\n";
		printValue(m1.at(2));
		printValue(m1.at(3));
		printValue(m2.at(0));
		printValue(m2.at(1));
		std::cout << "STD: m2.at(2)\n";
		printValue(m2.at(2));
		printValue(m2.at(3));

		std::cout << "\ninsert(it, make_pair(10, \"aaa\")\n";
		it1 = m1.insert(it1, ft::make_pair(10, "aaa"));
		it2 = m2.insert(it2, std::make_pair(10, "aaa"));
		std::cout << "FT: it1\n";
		printIter(it1);
		std::cout << "STD: it2\n";
		printIter(it2);
		std::cout << "FT: m1.at(10)\n";
		printValue(m1.at(10));
		std::cout << "STD: m2.at(10)\n";
		printValue(m2.at(10));

		std::cout << "\n+++ insert(iterator first, iterator last) +++\n";
		m3.clear();
		m4.clear();
		std::cout << "m3.empty(): " << m3.empty() << std::endl;
		std::cout << "m1.empty(): " << m1.empty() << std::endl;
		std::cout << "FT: m3(m1.begin(), m1.end())\n";
		m3.insert(m1.begin(), m1.end());
		std::cout << "m3.empty(): " << m3.empty() << std::endl;
		for (it1 = m3.begin(); it1 != m3.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}
		std::cout << "\nm4.empty(): " << m4.empty() << std::endl;
		std::cout << "m2.empty(): " << m2.empty() << std::endl;
		std::cout << "STD: m4(m2.begin(), m2.end())\n";
		m4.insert(m2.begin(), m2.end());
		std::cout << "m4.empty(): " << m4.empty() << std::endl;
		for (it2 = m4.begin(); it2 != m4.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}

		std::cout << "\n+++ erase(iterator pos) +++\n";
		// it1 = m1.end();
		// it1--;
		it1 = m1.begin();
		++it1;
		++it1;
		std::cout << "FT: it1\n";
		printIter(it1);
		std::cout << "FT: m1.erase(it1)\n";
		m1.erase(it1);
		for (it1 = m1.begin(); it1 != m1.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}

		// it2 = m2.end();
		// it2--;
		it2 = m2.begin();
		++it2;
		++it2;
		std::cout << "\nSTD: it2\n";
		printIter(it2);
		std::cout << "STD: m2.erase(it2)\n";
		m2.erase(it2);
		for (it2 = m2.begin(); it2 != m2.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}

		std::cout << "\n+++ erase() +++\n";
		std::cout << "FT: m1.erase(1): " << m1.erase(1) << "\n";
		for (it1 = m1.begin(); it1 != m1.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}
		std::cout << "\nSTD: m2.erase(1): " << m2.erase(1) << "\n";
		for (it2 = m2.begin(); it2 != m2.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}

		std::cout << "\n+++ erase(iterator first, iterator last) +++\n";
		std::cout << "FT: it1 = m1.end()\nit1--\n";
		it1 = m1.end();
		it1--;
		std::cout << "FT: ";
		printIter(it1);
		std::cout << "FT: m1.erase(m1.begin(), it1)\n";
		m1.erase(m1.begin(), it1);
		for (it1 = m1.begin(); it1 != m1.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}
		std::cout << "\nSTD: it2 = m2.end()\nit2--\n";
		it2 = m2.end();
		it2--;
		std::cout << "STD: ";
		printIter(it2);
		std::cout << "STD: m2.erase(m2.begin(), it2)\n";
		m2.erase(m2.begin(), it2);
		for (it2 = m2.begin(); it2 != m2.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}

		std::cout << "\n+++ swap(map) +++\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "FT: m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "\nm1 elements:\n";
		for (it1 = m1.begin(); it1 != m1.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}
		std::cout << "\nm3 elements:\n";
		for (it1 = m3.begin(); it1 != m3.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}

		std::cout << "\nFT: m1.swap(m3)\n";
		m1.swap(m3);
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "FT: m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "\nm1 elements:\n";
		for (it1 = m1.begin(); it1 != m1.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}
		std::cout << "\nm3 elements:\n";
		for (it1 = m3.begin(); it1 != m3.end(); it1++) {
			std::cout << "FT: ";
			printIter(it1);
		}

		std::cout << "\nSTD: m2.size()\n";
		std::cout << m2.size() << "\n";
		std::cout << "STD: m4.size()\n";
		std::cout << m4.size() << "\n";
		std::cout << "\nm2 elements:\n";
		for (it2 = m2.begin(); it2 != m2.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}
		std::cout << "\nm4 elements:\n";
		for (it2 = m4.begin(); it2 != m4.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}
		std::cout << "STD: m2.swap(m4)\n";
		m2.swap(m4);
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";
		std::cout << "STD: m4.size()\n";
		std::cout << m4.size() << "\n";
		std::cout << "\nm2 elements:\n";
		for (it2 = m2.begin(); it2 != m2.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}
		std::cout << "\nm4 elements:\n";
		for (it2 = m4.begin(); it2 != m4.end(); it2++) {
			std::cout << "STD: ";
			printIter(it2);
		}
	}

	// LOOKUPS
	{
		std::cout << "\n+++++++++ LOOKUPS +++++++++\n";
		std::cout << "\n+++ count() +++\n";
		std::cout << "\nm1 elements:\n";
		printMap(m1, it1, "FT");
		std::cout << "\nm2 elements:\n";
		printMap(m2, it2, "STD");
		std::cout << "\nFT: m1.count(1) - " << m1.count(1) << std::endl;
		std::cout << "STD: m2.count(1) - " << m2.count(1) << std::endl;
		std::cout << "FT: m1.count(4) - " << m1.count(4) << std::endl;
		std::cout << "STD: m2.count(4) - " << m2.count(4) << std::endl;
		std::cout << "FT: m1.count(10) - " << m1.count(10) << std::endl;
		std::cout << "STD: m2.count(10) - " << m2.count(10) << std::endl;

		std::cout << "\n+++ find() +++\n";
		std::cout << "FT: m1.find(1) - ";
		printIter(m1.find(1));
		std::cout << "STD: m2.find(1) - ";
		printIter(m2.find(1));
		std::cout << "FT: m1.find(3) - ";
		printIter(m1.find(3));
		std::cout << "STD: m2.find(3) - ";
		printIter(m2.find(3));
		// std::cout << "FT: m1.find(11) - ";
		// printIter(m1.find(11));
		// std::cout << "STD: m2.find(11) - ";
		// printIter(m2.find(11));

		std::cout << "\n+++ lower_bound() +++\n";
		std::cout << "FT: m1.lower_bound(0) - ";
		printIter(m1.lower_bound(0));
		std::cout << "STD: m2.lower_bound(0) - ";
		printIter(m2.lower_bound(0));
		std::cout << "FT: m1.lower_bound(2) - ";
		printIter(m1.lower_bound(2));
		std::cout << "STD: m2.lower_bound(2) - ";
		printIter(m2.lower_bound(2));
		// std::cout << "FT: m1.lower_bound(7) - ";
		// printIter(m1.lower_bound(7));
		// std::cout << "STD: m2.lower_bound(7) - ";
		// printIter(m2.lower_bound(7));

		std::cout << "\n+++ upper_bound() +++\n";
		std::cout << "FT: m1.upper_bound(0) - ";
		printIter(m1.upper_bound(0));
		std::cout << "STD: m2.upper_bound(0) - ";
		printIter(m2.upper_bound(0));
		std::cout << "FT: m1.upper_bound(2) - ";
		printIter(m1.upper_bound(2));
		std::cout << "STD: m2.upper_bound(2) - ";
		printIter(m2.upper_bound(2));
	
		std::cout << "\n+++ equal_range() +++\n";
		std::cout << "FT: m1.equal_range(0)\n";
		std::cout << "lower: ";
		printIter(m1.equal_range(0).first);
		std::cout << "upper: ";
		printIter(m1.equal_range(0).second);
		std::cout << "STD: m2.equal_range(0)\n";
		std::cout << "lower: ";
		printIter(m2.equal_range(0).first);
		std::cout << "upper: ";
		printIter(m2.equal_range(0).second);
		std::cout << "FT: m1.equal_range(4)\n";
		std::cout << "lower: ";
		printIter(m1.equal_range(4).first);
		std::cout << "upper: ";
		printIter(m1.equal_range(4).second);
		std::cout << "STD: m2.equal_range(4)\n";
		std::cout << "lower: ";
		printIter(m2.equal_range(4).first);
		std::cout << "upper: ";
		printIter(m2.equal_range(4).second);
	}

	// OBSERVERS
	{
		ft::map<int, std::string>::iterator		it3;
		std::map<int, std::string>::iterator	it4;

		it1 = m1.begin();
		it3 = m1.begin();
		it3++;
		std::cout << "\n+++++++++ OBSERVERS +++++++++\n";
		std::cout << "\n+++ key_comp() +++\n";
		std::cout << "FT: it1 - ";
		printIter(it1);
		std::cout << "FT: it3 - ";
		printIter(it3);
		std::cout << "FT: m1.key_comp()(it1->first, it3->first) - ";
		std::cout << m1.key_comp()(it1->first, it3->first);
		std::cout << std::endl;

		it2 = m2.begin();
		it4 = m2.begin();
		it4++;
		std::cout << "STD: it2 - ";
		printIter(it2);
		std::cout << "STD: it4 - ";
		printIter(it4);
		std::cout << "STD: m2.key_comp()(it2->first, it4->first) - ";
		std::cout << m2.key_comp()(it2->first, it4->first);
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "FT: m1.key_comp()(it3->first, it1->first) - ";
		std::cout << m1.key_comp()(it3->first, it1->first);
		std::cout << std::endl;
		std::cout << "STD: m2.key_comp()(it4->first, it2->first) - ";
		std::cout << m2.key_comp()(it4->first, it2->first);
		std::cout << std::endl;

		std::cout << "\n+++ value_comp() +++\n";
		std::cout << "FT: m1.value_comp()(*it3, *it1) - ";
		std::cout << m1.value_comp()(*it3, *it1);
		std::cout << std::endl;
		std::cout << "STD: m2.value_comp()(*it4, *it2) - ";
		std::cout << m2.value_comp()(*it4, *it2);
		std::cout << std::endl;
		std::cout << "FT: m1.value_comp()(*it1, *it3) - ";
		std::cout << m1.value_comp()(*it1, *it3);
		std::cout << std::endl;
		std::cout << "STD: m2.value_comp()(*it2, *it4) - ";
		std::cout << m2.value_comp()(*it2, *it4);
		std::cout << std::endl;
	}

	// COMPARISONS
	{
		ft::map<int, std::string>				m3;
		ft::map<int, std::string>::iterator		it3;
		std::map<int, std::string>				m4;
		std::map<int, std::string>::iterator	it4;

		std::cout << "\n+++++++++ COMPARISONS +++++++++\n";
		std::cout << "\n+++ operator== +++\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "FT: m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";
		std::cout << "STD: m4.size()\n";
		std::cout << m4.size() << "\n";
		std::cout << "FT: m1 == m3 ? " << (m1 == m3) << "\n";
		std::cout << "STD: m2 == m4 ? " << (m2 == m4) << "\n";
		std::cout << "FT: m1 != m3 ? " << (m1 != m3) << "\n";
		std::cout << "STD: m2 != m4 ? " << (m2 != m4) << "\n";
		std::cout << "FT: m1 > m3 ? " << (m1 > m3) << "\n";
		std::cout << "STD: m2 > m4 ? " << (m2 > m4) << "\n";
		std::cout << "FT: m1 >= m3 ? " << (m1 >= m3) << "\n";
		std::cout << "STD: m2 >= m4 ? " << (m2 >= m4) << "\n";
		std::cout << "FT: m1 < m3 ? " << (m1 < m3) << "\n";
		std::cout << "STD: m2 < m4 ? " << (m2 < m4) << "\n";
		std::cout << "FT: m1 <= m3 ? " << (m1 <= m3) << "\n";
		std::cout << "STD: m2 <= m4 ? " << (m2 <= m4) << "\n";
		printMap(m1, m1.begin(), "FT");
		printMap(m2, m2.begin(), "STD");

		// std::cout << "\nm3 = m1\n"; 
		// m3 = m1;
		// std::cout << "m4 = m2\n"; 
		// m4 = m2;
		// std::cout << "FT: m1.size()\n";
		// std::cout << m1.size() << "\n";
		// std::cout << "FT: m3.size()\n";
		// std::cout << m3.size() << "\n";
		// std::cout << "STD: m2.size()\n";
		// std::cout << m2.size() << "\n";
		// std::cout << "STD: m4.size()\n";
		// std::cout << m4.size() << "\n";
		// std::cout << "FT: m1 == m3 ? " << (m1 == m3) << "\n";
		// std::cout << "STD: m2 == m4 ? " << (m2 == m4) << "\n";
		// std::cout << "FT: m1 != m3 ? " << (m1 != m3) << "\n";
		// std::cout << "STD: m2 != m4 ? " << (m2 != m4) << "\n";
		// std::cout << "FT: m1 > m3 ? " << (m1 > m3) << "\n";
		// std::cout << "STD: m2 > m4 ? " << (m2 > m4) << "\n";
		// std::cout << "FT: m1 >= m3 ? " << (m1 >= m3) << "\n";
		// std::cout << "STD: m2 >= m4 ? " << (m2 >= m4) << "\n";
		// std::cout << "FT: m1 < m3 ? " << (m1 < m3) << "\n";
		// std::cout << "STD: m2 < m4 ? " << (m2 < m4) << "\n";
		// std::cout << "FT: m1 <= m3 ? " << (m1 <= m3) << "\n";
		// std::cout << "STD: m2 <= m4 ? " << (m2 <= m4) << "\n";

		std::cout << "\n+++ swap(lhs, rhs) +++\n";
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "FT: m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";
		std::cout << "STD: m4.size()\n";
		std::cout << m4.size() << "\n";
		std::cout << "after swap:\n";
		swap(m1, m3);
		swap(m2, m4);
		std::cout << "FT: m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "FT: m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "STD: m2.size()\n";
		std::cout << m2.size() << "\n";
		std::cout << "STD: m4.size()\n";
		std::cout << m4.size() << "\n";
	}
	return (0);
}