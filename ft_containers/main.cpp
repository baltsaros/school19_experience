#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "map.hpp"

#define NC "\e[0m"
#define GRNB "\e[1;32m"
#define GRN "\e[0;32m"
#define RD "\e[0;31m"
#define RDB "\e[1;31m"
#define REDL "\e[41m"
#define CYN "\e[0;36m"
#define CYNB "\e[1;36m"
#define YLW "\e[0;33m"
#define YLWB "\e[1;33m"
#define PRPL "\e[0;35m"
#define PRPLB "\e[1;35m"
#define WHT "\e[0;37m"
#define WHTB "\e[1;37m"
#define WHTL "\e[37m"
#define BLUE "\e[0;34m"
#define BLUEB "\e[1;34m"
#define BLUEL "\e[34m"

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
	{
		std::cout << GRNB "TESTING MAP\n" NC;
		TYPE::map<int, std::string>						m1;
		TYPE::map<int, std::string>::iterator			it1;
		TYPE::map<int, std::string>::reverse_iterator	rit1;


		m1.insert(TYPE::make_pair(0, "zero"));
		m1.insert(TYPE::make_pair(1, "one"));
		m1.insert(TYPE::make_pair(2, "two"));
		m1.insert(TYPE::make_pair(3, "three"));
		m1.insert(TYPE::make_pair(4, "four"));
		m1.insert(TYPE::make_pair(5, "five"));


		// ELEMENT ACCES
		{
			std::cout << YLWB "\n+++++++++ ELEMENT ACCES +++++++++\n" NC;
			std::cout << YLW "\n+++ at() +++\n" NC;
			std::cout << "m1.at(0)\n";
			std::cout << m1.at(0) << "\n";
			std::cout << "m1.at(1)\n";
			std::cout << m1.at(1) << "\n";
			// std::cout << "m1.at(10) - (out of range)\n";
			// std::cout << m1.at(10) << "\n";

			std::cout << YLW "\n+++ operator[] +++\n" NC;

			std::cout << "m1[0]\n";
			printValue(m1[0]);
			std::cout << "m1[6] - (out of range)\n";
			printValue(m1[6]);
		}

		// TYPE ITERATORS
		{
			std::cout << YLWB "\n+++++++++ ITERATORS +++++++++\n" NC;
			std::cout << YLW "\n+++ begin() +++\n" NC;
			std::cout << "it1 = m1(begin())\n";
			it1 = m1.begin();
			printIter(it1);

			std::cout << YLW "\n+++ preincrement +++\n" NC;
			std::cout << "++it1\n";
			printIter(++it1);
			printIter(it1);

			std::cout << YLW "\n+++ predecrement +++\n" NC;
			std::cout << "--it1\n";
			printIter(--it1);
			printIter(it1);

			std::cout << YLW "\n+++ postincrement +++\n" NC;
			std::cout << "it1++\n";
			printIter(it1++);
			std::cout << "it1\n";
			printIter(it1);

			std::cout << YLW "\n+++ postdecrement +++\n" NC;
			std::cout << "it1--\n";
			printIter(it1--);
			std::cout << "it1\n";
			printIter(it1);

			std::cout << YLW "\n+++ end() +++\n" NC;
			std::cout << "it1 = m1(end())\n";
			it1 = m1.end();
			std::cout << "it1--\n";
			it1--;
			printIter(it1);

			std::cout << YLW "\n+++ rbegin() +++\n" NC;
			std::cout << "rit1 = m1(rbegin()\n";
			rit1 = m1.rbegin();
			printIter(rit1);

			std::cout << YLW "\n+++ rend() +++\n" NC;
			std::cout << "rit1 = m1(rend()\n";
			rit1 = m1.rend();
			std::cout << "rit1++\n";
			rit1++;
			printIter(rit1);
		}

		// CAPACITY
		{
			std::cout << YLWB "\n+++++++++ CAPACITY +++++++++\n" NC;
			std::cout << YLW "\n+++ empty() +++\n" NC;
			std::cout << "m1.empty()\n";
			std::cout << m1.empty() << "\n";

			std::cout << "\nCreating empty m3\n";
			TYPE::map<int, std::string>						m3;

			std::cout << "m3.empty()\n";
			std::cout << m3.empty() << "\n";


			std::cout << YLW "\n+++ size() +++\n" NC;
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			std::cout << "m3.size()\n";
			std::cout << m3.size() << "\n";

			std::cout << "\nerase(3): deleting one element\n";
			std::cout << m1.erase(3) << std::endl;
			std::cout << "m1.empty()\n";
			std::cout << m1.empty() << "\n";
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";

			std::cout << "\nerase(10): deleting non-existing element\n";
			std::cout << m1.erase(10) << std::endl;
			std::cout << "m1.empty()\n";
			std::cout << m1.empty() << "\n";
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";

			std::cout << YLW "\n+++ max_size() +++\n" NC;
			std::cout << "m1.max_size()\n";
			std::cout << m1.max_size() << "\n";
		}

		// MODIFIERS
		{
			TYPE::map<int, std::string>						m3;

			std::cout << YLWB "\n+++++++++ MODIFIERS +++++++++\n" NC;
			std::cout << "\n+++ clear() +++\n";
			std::cout << "m1.empty()\n";
			std::cout << m1.empty() << "\n";
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			m1.clear();
			std::cout << "after clear():\n";
			std::cout << "m1.empty()\n";
			std::cout << m1.empty() << "\n";
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";

			std::cout << YLW "\n+++ insert(pair) +++\n" NC;
			m1.insert(TYPE::make_pair(0, "zero"));
			m1.insert(TYPE::make_pair(1, "one"));
			m1.insert(TYPE::make_pair(2, "two"));
			m1.insert(TYPE::make_pair(3, "three"));
			m1.insert(TYPE::make_pair(4, "four"));
			m1.insert(TYPE::make_pair(5, "five"));
			for (it1 = m1.begin(); it1 != m1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ insert(it, pair) +++\n" NC;
			it1 = m3.begin();
			std::cout << "\nEmpty maps, it = m.begin()\n";
			std::cout << "insert(it, make_pair(2, \"two\")\n";
			it1 = m3.insert(it1, TYPE::make_pair(2, "two"));
			std::cout << "it1\n";
			printIter(it1);
			std::cout << "m3.at(2)\n";
			printValue(m3.at(2));

			it1 = m1.begin();
			std::cout << "\nFilled maps, it = m.begin()\n";
			std::cout << "insert(it, make_pair(2, \"aaa\")\n";
			it1 = m1.insert(it1, TYPE::make_pair(2, "aaa"));
			std::cout << "it1\n";
			printIter(it1);
			printValue(m1.at(0));
			printValue(m1.at(1));
			std::cout << "m1.at(2)\n";
			printValue(m1.at(2));
			printValue(m1.at(3));

			std::cout << "\ninsert(it, make_pair(10, \"aaa\")\n";
			it1 = m1.insert(it1, TYPE::make_pair(10, "aaa"));
			std::cout << "it1\n";
			printIter(it1);
			std::cout << "m1.at(10)\n";
			printValue(m1.at(10));

			std::cout << YLW "\n+++ insert(iterator first, iterator last) +++\n" NC;
			m3.clear();
			std::cout << "m3.empty(): " << m3.empty() << std::endl;
			std::cout << "m1.empty(): " << m1.empty() << std::endl;
			std::cout << "m3(m1.begin(), m1.end())\n";
			m3.insert(m1.begin(), m1.end());
			std::cout << "m3.empty(): " << m3.empty() << std::endl;
			for (it1 = m3.begin(); it1 != m3.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ erase(iterator pos) +++\n" NC;
			it1 = m1.begin();
			++it1;
			++it1;
			std::cout << "it1\n";
			printIter(it1);
			std::cout << "m1.erase(it1)\n";
			m1.erase(it1);
			for (it1 = m1.begin(); it1 != m1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ erase() +++\n" NC;
			std::cout << "m1.erase(1): " << m1.erase(1) << "\n";
			for (it1 = m1.begin(); it1 != m1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ erase(iterator first, iterator last) +++\n" NC;
			std::cout << "it1 = m1.end()\nit1--\n";
			it1 = m1.end();
			it1--;
			printIter(it1);
			std::cout << "m1.erase(m1.begin(), it1)\n";
			m1.erase(m1.begin(), it1);
			for (it1 = m1.begin(); it1 != m1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ swap(map) +++\n" NC;
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			std::cout << "m3.size()\n";
			std::cout << m3.size() << "\n";
			std::cout << "\nm1 elements:\n";
			for (it1 = m1.begin(); it1 != m1.end(); it1++)
				printIter(it1);
			std::cout << "\nm3 elements:\n";
			for (it1 = m3.begin(); it1 != m3.end(); it1++)
				printIter(it1);

			std::cout << "\nm1.swap(m3)\n";
			m1.swap(m3);
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			std::cout << "m3.size()\n";
			std::cout << m3.size() << "\n";
			std::cout << "\nm1 elements:\n";
			for (it1 = m1.begin(); it1 != m1.end(); it1++)
				printIter(it1);
			std::cout << "\nm3 elements:\n";
			for (it1 = m3.begin(); it1 != m3.end(); it1++)
				printIter(it1);
		}

		// LOOKUPS
		{
			std::cout << YLWB "\n+++++++++ LOOKUPS +++++++++\n" NC;
			std::cout << YLW "\n+++ count() +++\n" NC;
			std::cout << "\nm1 elements:\n";
			printMap(m1, it1, "");
			std::cout << "\nm1.count(1) - " << m1.count(1) << std::endl;
			std::cout << "m1.count(4) - " << m1.count(4) << std::endl;
			std::cout << "m1.count(10) - " << m1.count(10) << std::endl;

			std::cout << YLW "\n+++ find() +++\n" NC;
			std::cout << "m1.find(1) - ";
			printIter(m1.find(1));
			std::cout << "m1.find(3) - ";
			printIter(m1.find(3));

			std::cout << YLW "\n+++ lower_bound() +++\n" NC;
			std::cout << "m1.lower_bound(0) - ";
			printIter(m1.lower_bound(0));
			std::cout << "m1.lower_bound(2) - ";
			printIter(m1.lower_bound(2));

			std::cout << YLW "\n+++ upper_bound() +++\n" NC;
			std::cout << "m1.upper_bound(0) - ";
			printIter(m1.upper_bound(0));
			std::cout << "m1.upper_bound(2) - ";
			printIter(m1.upper_bound(2));
		
			std::cout << YLW "\n+++ equal_range() +++\n" NC;
			std::cout << "m1.equal_range(0)\n";
			std::cout << "lower: ";
			printIter(m1.equal_range(0).first);
			std::cout << "upper: ";
			printIter(m1.equal_range(0).second);
			std::cout << "m1.equal_range(4)\n";
			std::cout << "lower: ";
			printIter(m1.equal_range(4).first);
			std::cout << "upper: ";
			printIter(m1.equal_range(4).second);
		}

		// OBSERVERS
		{
			TYPE::map<int, std::string>::iterator	it3;

			it1 = m1.begin();
			it3 = m1.begin();
			it3++;
			std::cout << YLWB "\n+++++++++ OBSERVERS +++++++++\n" NC;
			std::cout << YLW "\n+++ key_comp() +++\n" NC;
			std::cout << "it1 - ";
			printIter(it1);
			std::cout << "it3 - ";
			printIter(it3);
			std::cout << "m1.key_comp()(it1->first, it3->first) - ";
			std::cout << m1.key_comp()(it1->first, it3->first);
			std::cout << std::endl;

			std::cout << "m1.key_comp()(it3->first, it1->first) - ";
			std::cout << m1.key_comp()(it3->first, it1->first);
			std::cout << std::endl;

			std::cout << YLW "\n+++ value_comp() +++\n" NC;
			std::cout << "m1.value_comp()(*it3, *it1) - ";
			std::cout << m1.value_comp()(*it3, *it1);
			std::cout << std::endl;
			std::cout << "m1.value_comp()(*it1, *it3) - ";
			std::cout << m1.value_comp()(*it1, *it3);
			std::cout << std::endl;
		}

		// COMPARISONS
		{
			TYPE::map<int, std::string>				m3;
			TYPE::map<int, std::string>::iterator		it3;

			std::cout << YLWB "\n+++++++++ COMPARISONS +++++++++\n" NC;
			std::cout << YLW "\n+++ operator== +++\n" NC;
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			std::cout << "m3.size()\n";
			std::cout << m3.size() << "\n";
			std::cout << "m1 == m3 ? " << (m1 == m3) << "\n";
			std::cout << "m1 != m3 ? " << (m1 != m3) << "\n";
			std::cout << "m1 > m3 ? " << (m1 > m3) << "\n";
			std::cout << "m1 >= m3 ? " << (m1 >= m3) << "\n";
			std::cout << "m1 < m3 ? " << (m1 < m3) << "\n";
			std::cout << " m1 <= m3 ? " << (m1 <= m3) << "\n";
			printMap(m1, m1.begin(), "");

			std::cout << "\nm3 = m1\n"; 
			m3 = m1;
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			std::cout << "m3.size()\n";
			std::cout << m3.size() << "\n";
			std::cout << "m1 == m3 ? " << (m1 == m3) << "\n";
			std::cout << "m1 != m3 ? " << (m1 != m3) << "\n";
			std::cout << "m1 > m3 ? " << (m1 > m3) << "\n";
			std::cout << "m1 >= m3 ? " << (m1 >= m3) << "\n";
			std::cout << "m1 < m3 ? " << (m1 < m3) << "\n";
			std::cout << "m1 <= m3 ? " << (m1 <= m3) << "\n";

			std::cout << YLW "\n+++ swap(lhs, rhs) +++\n" NC;
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			std::cout << "m3.size()\n";
			std::cout << m3.size() << "\n";
			std::cout << "after swap:\n";
			swap(m1, m3);
			std::cout << "m1.size()\n";
			std::cout << m1.size() << "\n";
			std::cout << "m3.size()\n";
			std::cout << m3.size() << "\n";
		}
	}
	return (0);
}