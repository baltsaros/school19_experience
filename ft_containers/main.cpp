/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:57:53 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:57:54 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iterator>
#include <map>
#include "containers/map.hpp"
#include <vector>
#include "containers/vector.hpp"
#include <stack>
#include "containers/stack.hpp"

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
void	printIterPair(InputIt it) {
	std::cout << it->first << ": " << it->second << std::endl;
}

template <class InputIt>
void	printIter(InputIt it) {
	std::cout << *it << std::endl;
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
		printIterPair(it);
	}
}

template <class set, class InputIt>
void	printSet(set s, InputIt it, std::string type) {
	for (it = s.begin(); it != s.end(); it++) {
		std::cout << type << ": ";
		printIter(it);
	}
}


void	test_map(void) {
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
		printIterPair(it1);

		std::cout << YLW "\n+++ preincrement +++\n" NC;
		std::cout << "++it1\n";
		printIterPair(++it1);
		printIterPair(it1);

		std::cout << YLW "\n+++ predecrement +++\n" NC;
		std::cout << "--it1\n";
		printIterPair(--it1);
		printIterPair(it1);

		std::cout << YLW "\n+++ postincrement +++\n" NC;
		std::cout << "it1++\n";
		printIterPair(it1++);
		std::cout << "it1\n";
		printIterPair(it1);

		std::cout << YLW "\n+++ postdecrement +++\n" NC;
		std::cout << "it1--\n";
		printIterPair(it1--);
		std::cout << "it1\n";
		printIterPair(it1);

		std::cout << YLW "\n+++ end() +++\n" NC;
		std::cout << "it1 = m1(end())\n";
		it1 = m1.end();
		std::cout << "it1--\n";
		it1--;
		printIterPair(it1);

		std::cout << YLW "\n+++ rbegin() +++\n" NC;
		std::cout << "rit1 = m1(rbegin())\n";
		rit1 = m1.rbegin();
		printIterPair(rit1);

		std::cout << YLW "\n+++ rend() +++\n" NC;
		std::cout << "rit1 = m1(rend())\n";
		rit1 = m1.rend();
		std::cout << "rit1--\n";
		rit1--;
		printIterPair(rit1);
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
			printIterPair(it1);

		std::cout << YLW "\n+++ insert(it, pair) +++\n" NC;
		it1 = m3.begin();
		std::cout << "\nEmpty maps, it = m.begin()\n";
		std::cout << "insert(it, make_pair(2, \"two\")\n";
		it1 = m3.insert(it1, TYPE::make_pair(2, "two"));
		std::cout << "it1\n";
		printIterPair(it1);
		std::cout << "m3.at(2)\n";
		printValue(m3.at(2));

		it1 = m1.begin();
		std::cout << "\nFilled maps, it = m.begin()\n";
		std::cout << "insert(it, make_pair(2, \"aaa\")\n";
		it1 = m1.insert(it1, TYPE::make_pair(2, "aaa"));
		std::cout << "it1\n";
		printIterPair(it1);
		printValue(m1.at(0));
		printValue(m1.at(1));
		std::cout << "m1.at(2)\n";
		printValue(m1.at(2));
		printValue(m1.at(3));

		std::cout << "\ninsert(it, make_pair(10, \"aaa\")\n";
		it1 = m1.insert(it1, TYPE::make_pair(10, "aaa"));
		std::cout << "it1\n";
		printIterPair(it1);
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
			printIterPair(it1);

		std::cout << YLW "\n+++ erase(iterator pos) +++\n" NC;
		it1 = m1.begin();
		++it1;
		++it1;
		std::cout << "it1\n";
		printIterPair(it1);
		std::cout << "m1.erase(it1)\n";
		m1.erase(it1);
		for (it1 = m1.begin(); it1 != m1.end(); it1++)
			printIterPair(it1);

		std::cout << YLW "\n+++ erase() +++\n" NC;
		std::cout << "m1.erase(1): " << m1.erase(1) << "\n";
		for (it1 = m1.begin(); it1 != m1.end(); it1++)
			printIterPair(it1);

		std::cout << YLW "\n+++ erase(iterator first, iterator last) +++\n" NC;
		std::cout << "it1 = m1.end()\nit1--\n";
		it1 = m1.end();
		it1--;
		printIterPair(it1);
		std::cout << "m1.erase(m1.begin(), it1)\n";
		m1.erase(m1.begin(), it1);
		for (it1 = m1.begin(); it1 != m1.end(); it1++)
			printIterPair(it1);

		std::cout << YLW "\n+++ swap(map) +++\n" NC;
		std::cout << "m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "\nm1 elements:\n";
		for (it1 = m1.begin(); it1 != m1.end(); it1++)
			printIterPair(it1);
		std::cout << "\nm3 elements:\n";
		for (it1 = m3.begin(); it1 != m3.end(); it1++)
			printIterPair(it1);

		std::cout << "\nm1.swap(m3)\n";
		m1.swap(m3);
		std::cout << "m1.size()\n";
		std::cout << m1.size() << "\n";
		std::cout << "m3.size()\n";
		std::cout << m3.size() << "\n";
		std::cout << "\nm1 elements:\n";
		for (it1 = m1.begin(); it1 != m1.end(); it1++)
			printIterPair(it1);
		std::cout << "\nm3 elements:\n";
		for (it1 = m3.begin(); it1 != m3.end(); it1++)
			printIterPair(it1);
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
		printIterPair(m1.find(1));
		std::cout << "m1.find(3) - ";
		printIterPair(m1.find(3));

		std::cout << YLW "\n+++ lower_bound() +++\n" NC;
		std::cout << "m1.lower_bound(0) - ";
		printIterPair(m1.lower_bound(0));
		std::cout << "m1.lower_bound(2) - ";
		printIterPair(m1.lower_bound(2));

		std::cout << YLW "\n+++ upper_bound() +++\n" NC;
		std::cout << "m1.upper_bound(0) - ";
		printIterPair(m1.upper_bound(0));
		std::cout << "m1.upper_bound(2) - ";
		printIterPair(m1.upper_bound(2));
	
		std::cout << YLW "\n+++ equal_range() +++\n" NC;
		std::cout << "m1.equal_range(0)\n";
		std::cout << "lower: ";
		printIterPair(m1.equal_range(0).first);
		std::cout << "upper: ";
		printIterPair(m1.equal_range(0).second);
		std::cout << "m1.equal_range(4)\n";
		std::cout << "lower: ";
		printIterPair(m1.equal_range(4).first);
		std::cout << "upper: ";
		printIterPair(m1.equal_range(4).second);
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
		printIterPair(it1);
		std::cout << "it3 - ";
		printIterPair(it3);
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

void	test_vector(void) {
	std::cout << GRNB "TESTING VECTOR\n" NC;
	{
		TYPE::vector<int>		v2(4, 100);
		TYPE::vector<int>		v4(v2.begin(), v2.end());
		int					*p;
	
		std::cout << YLW "\n+++ get allocator +++\n" NC;
		p = v2.get_allocator().allocate(3);
		for (size_t i = 0; i < 3; ++i) {
			v2.get_allocator().construct(&p[i], i);
			std::cout << "p[" << i << "]:" << p[i] << std::endl;
			v2.get_allocator().destroy(&p[i]);
		}
		v2.get_allocator().deallocate(p, 3);
		std::cout << std::endl;

		std::cout << YLW "\n+++ assign +++\n" NC;
		std::cout << "assign test" << std::endl;
		std::cout << "v2.assign(2,5)" << std::endl;
		v2.assign(2, 5);
		for (TYPE::vector<int>::iterator it2 = v2.begin(); it2 != v2.end(); it2++) {
			std::cout << *it2 << " ";
		}
		std::cout << std::endl;

	}

	// TYPE_vector: access operators
	{
		std::cout << YLWB "\n+++++++++ ELEMENT ACCESS +++++++++\n" NC;
		std::cout << YLW "\n+++ at() +++\n" NC;
		TYPE::vector<int>	v2(4, 100);
		TYPE::vector<int>	v4;

		std::cout << "v2.at(0): " << v2.at(0) << std::endl;
		std::cout << "v2.at(3): " << v2.at(3) << std::endl;
		std::cout << "v2.at(2) = 3: " << (v2.at(2) = 3) << std::endl;
		std::cout << "v2.at(2): " << v2.at(2) << std::endl;

		std::cout << YLW "\n+++ operator[] +++\n" NC;
		std::cout << "v2[0]: " << v2[0] << std::endl;
		std::cout << "v2[2]: " << v2[2] << std::endl;

		std::cout << YLW "\n+++ front() +++\n" NC;
		std::cout << "v2.front(): " << v2.front() << std::endl;

		std::cout << YLW "\n+++ back() +++\n" NC;
		std::cout << "v2.at(3) = 6: " << (v2.at(3) = 6) << std::endl;
		std::cout << "v2.at(3): " << v2.at(3) << std::endl;
		std::cout << "v2.back(): " << v2.back() << std::endl;
	}

	// TYPE_vector: capacity
	{
		TYPE::vector<int>	v2(4, 100);
		TYPE::vector<int>	v4;

		std::cout << YLWB "\n+++++++++ CAPACITY +++++++++\n" NC;
		std::cout << YLW "\n+++ empty() +++\n" NC;
		std::cout << "v2 empty? " << v2.empty() << std::endl;
		std::cout << "v4 empty? " << v4.empty() << std::endl;

		std::cout << YLW "\n+++ size() +++\n" NC;
		std::cout << "v2.size(): " << v2.size() << std::endl;
		std::cout << "v4.size(): " << v4.size() << std::endl;

		std::cout << YLW "\n+++ max_size() +++\n" NC;
		std::cout << "v2.max_size(): " << v2.max_size() << std::endl;
		std::cout << "v4.max_size(): " << v4.max_size() << std::endl;

		std::cout << YLW "\n+++ reserve() +++\n" NC;
		std::cout << "v2.reserve(150): " << std::endl;
		v2.reserve(150);
		std::cout << "v2.capacity(): " << v2.capacity() << std::endl;
		std::cout << "v2[0]: " << v2[0] << std::endl;
		std::cout << "v2[2]: " << v2[2] << std::endl;

		std::cout << "reserve(10) empty containers: " << std::endl;
		v4.reserve(10);
		std::cout << "v4.capacity(): " << v4.capacity() << std::endl;
	}

	// TYPE_vector: modifiers
	{
		TYPE::vector<int>			v2(4, 100);
		TYPE::vector<int>::iterator	it2;
		TYPE::vector<int>			v4;

		std::cout << YLWB "\n+++++++++ MODIFIERS +++++++++\n" NC;
		std::cout << YLW "\n+++ insert(pos, value) +++\n" NC;
		std::cout << "array before insert: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v1.insert(4, 50)" << std::endl;
		it2 = v2.begin() + 4;
		it2 = v2.insert(it2, 50);
		std::cout << "return: " << *it2 << std::endl;
		std::cout << "v1.insert(5, 55)" << std::endl;
		it2 = v2.begin() + 5;
		it2 = v2.insert(it2, 55);
		std::cout << "return: " << *it2 << std::endl;
		std::cout << "array after insert: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ insert(pos, count, value) +++" NC << std::endl;
		std::cout << "array before insert: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.insert(2, 2, 22)" << std::endl;
		it2 = v2.begin() + 2;
		v2.insert(it2, 2, 22);
		std::cout << "v2.insert(5, 3, 33)" << std::endl;
		it2 = v2.begin() + 5;
		v2.insert(it2, 3, 33);
		std::cout << "array after insert: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ insert(pos, It1, It2) +++" NC << std::endl;
		std::cout << "array before insert: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.insert(2, begin, end)" << std::endl;
		TYPE::vector<int>	v5(v2);
		it2 = v2.begin() + 2;
		v2.insert(it2, v2.begin(), v2.end());
		std::cout << "v2.insert(5, 3, 33)" << std::endl;
		it2 = v2.begin() + 5;
		v2.insert(it2, 3, 33);
		std::cout << "array after insert: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		TYPE::vector<int>	v7;

		for (int i = 0; i < 4; ++i) {
			v7.push_back(i);
		}
		std::cout << YLW "+++ erase(pos) +++" NC << std::endl;
		std::cout << "v7.insert(2, 55)" << std::endl;
		it2 = v7.begin() + 2;
		it2 = v7.insert(it2, 55);
		std::cout << "v7.erase(it2)" << std::endl;
		it2 = v7.erase(v7.begin());
		std::cout << "return: " << *it2 << std::endl;
		std::cout << "array after erase: ";
		for (TYPE::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ erase(first, last) +++" NC << std::endl;
		std::cout << "array before erase: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.erase(v2.begin() + 1, v2.end() - 2)" << std::endl;	
		it2 = v2.erase(v2.begin() + 1, v2.end() - 2);
		std::cout << "return: " << *it2 << std::endl;
		std::cout << "array after erase: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ resize(count, value) +++" NC << std::endl;
		std::cout << "array before resize: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.resize(2, 3)" << std::endl;
		v2.resize(2, 3);
		std::cout << "array after resize: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.resize(8, 3)" << std::endl;
		v2.resize(8, 3);
		std::cout << "array after resize: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;


		std::cout << YLW "+++ swap(vector) +++" NC << std::endl;
		std::cout << "v2 before swap: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v7 before swap: ";
		for (TYPE::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << "v7.size: " << v7.size() << std::endl;
		std::cout << "v7.capacity: " << v7.capacity() << std::endl;
		v2.swap(v7);
		std::cout << "v2 after swap: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v7 after swap: ";
		for (TYPE::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << "v7.size: " << v7.size() << std::endl;
		std::cout << "v7.capacity: " << v7.capacity() << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ comparison +++" NC << std::endl;
		v2.push_back(7);
		std::cout << "v2: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v7: ";
		for (TYPE::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << "v7.size: " << v7.size() << std::endl;
		std::cout << "v7.capacity: " << v7.capacity() << std::endl;
		std::cout << std::endl;
		std::cout << "v2 == v2? " << (v2 == v2) << std::endl;
		std::cout << "v2 != v2? " << (v2 != v2) << std::endl;
		std::cout << "v2 == v7? " << (v2 == v7) << std::endl;
		std::cout << "v2 != v7? " << (v2 != v7) << std::endl;
		std::cout << "v2 <  v2? " << (v2 < v2) << std::endl;
		std::cout << "v2 <= v2? " << (v2 <= v2) << std::endl;
		std::cout << "v2 <  v7? " << (v2 < v7) << std::endl;
		std::cout << "v2 <= v7? " << (v2 <= v7) << std::endl;
		std::cout << "v2 >  v2? " << (v2 > v2) << std::endl;
		std::cout << "v2 >= v2? " << (v2 >= v2) << std::endl;
		std::cout << "v2 >  v7? " << (v2 > v7) << std::endl;
		std::cout << "v2 >= v7? " << (v2 >= v7) << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ swap(v1, v2) +++" NC << std::endl;
		std::cout << "v2 before swap: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v7 before swap: ";
		for (TYPE::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << "v7.size: " << v7.size() << std::endl;
		std::cout << "v7.capacity: " << v7.capacity() << std::endl;
		swap(v2, v7);
		std::cout << "v2 after swap: ";
		for (TYPE::vector<int>::iterator it = v2.begin(); it != v2.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v7 after swap: ";
		for (TYPE::vector<int>::iterator it = v7.begin(); it != v7.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << "v7.size: " << v7.size() << std::endl;
		std::cout << "v7.capacity: " << v7.capacity() << std::endl;
		std::cout << std::endl;
	

		std::cout << YLW "+++ clear() +++" NC << std::endl;
		std::cout << "v2.clear()" << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << "clearing" << std::endl;
		v2.clear();
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << std::endl;
		
		std::cout << YLW "+++ push_back(value) +++" NC << std::endl;
		std::cout << "v2.back(): " << v2.back() << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << "pushing 3 to the end..." << std::endl;
		v2.push_back(3);
		std::cout << "v2.back(): " << v2.back() << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ pop_back() +++" NC << std::endl;
		std::cout << "popping..." << std::endl;
		v2.pop_back();
		std::cout << "v2.back(): " << v2.back() << std::endl;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << std::endl;
	}

	//iterators
	{
		TYPE::vector<int>		v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		TYPE::vector<int>::iterator	it2;
		TYPE::vector<int>::iterator	it4;
		TYPE::vector<int>::iterator	it6;


		std::cout << YLWB "\n+++++++++ ITERATORS +++++++++\n" NC;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;

		std::cout << YLW "\n+++ begin() +++\n" NC;
		std::cout << "v2.begin(): ";
		std::cout << *(v2.begin()) << std::endl;
		std::cout << "it2 = v2.begin() " << std::endl;
		it2 = v2.begin();
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << std::endl;
		
		std::cout << YLW "+++ pre-in/decrementation +++" NC<< std::endl;
		it4 = v2.end();
		std::cout << "it2 = v2.end() " << std::endl;
		--it4;
		std::cout << "--it4: " << *it4 << std::endl;
		--it4;
		std::cout << "--it4: " << *it4 << std::endl;
		std::cout << "it4--: " << *(it4--) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << "it4--: " << *(it4--) << std::endl;
		++it4;
		std::cout << "++it4: " << *it4 << std::endl;
		++it4;
		std::cout << "++it4: " << *it4 << std::endl;
		std::cout << "it4++: " << *(it4++) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ arithmetic operations +++" NC<< std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		it4 -= 2;
		std::cout << "it4 -= 2: " << *it4 << std::endl;
		it4 -= 1;
		std::cout << "it4 -= 1: " << *it4 << std::endl;
		it4 += 2;
		std::cout << "it4 += 2: " << *it4 << std::endl;
		std::cout << "it4 - 2: " << *it4 << " - " << 2 << " = ";
		std::cout << *(it4 - 2) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << "it4 + 1: " << *it4 << " + " << 1 << " = ";
		std::cout << *(it4 + 1) << std::endl;
		std::cout << std::endl;

		std::cout << YLW "operator[]" NC << std::endl;
		it4 = v2.begin();
		std::cout << "it4[0]: " << it4[0] << std::endl;
		std::cout << "it4[1]: " << it4[1] << std::endl;
		std::cout << "it4[2]: " << it4[2] << std::endl;
		std::cout << "it4[3]: " << it4[3] << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ comparisons +++" NC << std::endl;
		it4 = it4 + 2;
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << *it2 << " < " << *it4 << " ? ";
		std::cout << (it2 < it4) << std::endl;
		std::cout << *it2 << " > " << *it4 << " ? ";
		std::cout << (it2 > it4) << std::endl;
		std::cout << *it2 << " <= " << *it4 << " ? ";
		std::cout << (it2 <= it4) << std::endl;
		std::cout << *it2 << " >= " << *it4 << " ? ";
		std::cout << (it2 >= it4) << std::endl;
		std::cout << *it2 << " == " << *it4 << " ? ";
		std::cout << (it2 == it4) << std::endl;
		std::cout << *it2 << " != " << *it4 << " ? ";
		std::cout << (it2 != it4) << std::endl;
		std::cout << std::endl;
	}
	
	// reverse_iterators
	{
		TYPE::vector<int>		v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		TYPE::vector<int>::reverse_iterator	it2;
		TYPE::vector<int>::reverse_iterator	it4;
		TYPE::vector<int>::reverse_iterator	it6;


		std::cout << YLWB "\n+++++++++ REVERSE ITERATORS +++++++++\n" NC;
		std::cout << "v2.size: " << v2.size() << std::endl;
		std::cout << "v2.capacity: " << v2.capacity() << std::endl;
		std::cout << std::endl;

		std::cout << "v2.begin(): ";
		std::cout << *(v2.begin()) << std::endl;
		std::cout << "it2 = v2.rbegin()" << std::endl;
		it2 = v2.rbegin();
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << std::endl;

		std::cout << "v2.end(): ";
		std::cout << *(v2.end()) << std::endl;
		std::cout << std::endl;
		
		std::cout << YLW "+++ pre-in/decrementation +++" NC<< std::endl;
		std::cout << "it4 = v2.rend()" << std::endl;
		it4 = v2.rend();
		std::cout << "it4: " << *it4 << std::endl;
		--it4;
		std::cout << "--it4: " << *it4 << std::endl;
		--it4;
		std::cout << "--it4: " << *it4 << std::endl;
		std::cout << "it4--: " << *(it4--) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << "it4--: " << *(it4--) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		++it4;
		std::cout << "++it4: " << *it4 << std::endl;
		++it4;
		std::cout << "++it4: " << *it4 << std::endl;
		std::cout << "it4++: " << *(it4++) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << "it4++: " << *(it4++) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ arithmetic operations +++" NC<< std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		it4 -= 2;
		std::cout << "it4 -= 2: " << *it4 << std::endl;
		it4 -= 1;
		std::cout << "it4 -= 1: " << *it4 << std::endl;
		it4 += 2;
		std::cout << "it4 += 2: " << *it4 << std::endl;
		std::cout << "it4 - 2: " << *it4 << " - " << 2 << " = ";
		std::cout << *(it4 - 2) << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << "it4 + 1: " << *it4 << " + " << 1 << " = ";
		std::cout << *(it4 + 1) << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ operator[] +++" NC << std::endl;
		it4 = v2.rbegin();
		std::cout << "it4[0]: " << it4[0] << std::endl;
		std::cout << "it4[1]: " << it4[1] << std::endl;
		std::cout << "it4[2]: " << it4[2] << std::endl;
		std::cout << "it4[3]: " << it4[3] << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << std::endl;

		std::cout << YLW "+++ comparisons +++" NC << std::endl;
		it4 = it4 + 2;
		std::cout << "it2: " << *it2 << std::endl;
		std::cout << "it4: " << *it4 << std::endl;
		std::cout << *it2 << " < " << *it4 << " ? ";
		std::cout << (it2 < it4) << std::endl;
		std::cout << *it2 << " > " << *it4 << " ? ";
		std::cout << (it2 > it4) << std::endl;
		std::cout << *it2 << " <= " << *it4 << " ? ";
		std::cout << (it2 <= it4) << std::endl;
		std::cout << *it2 << " >= " << *it4 << " ? ";
		std::cout << (it2 >= it4) << std::endl;
		std::cout << *it2 << " == " << *it4 << " ? ";
		std::cout << (it2 == it4) << std::endl;
		std::cout << *it2 << " != " << *it4 << " ? ";
		std::cout << (it2 != it4) << std::endl;
		std::cout << std::endl;
	}
}

void	test_stack(void) {
	std::cout << GRNB "TESTING STACK\n" NC;
	TYPE::stack<int>	s2;

	std::cout << YLWB "+++ push and top +++" NC << std::endl;
	for (size_t i = 0; i < 7; ++i) {
		s2.push(i);
		std::cout << "push: " << i << std::endl;
		std::cout << "top: " << s2.top() << std::endl;
	}
	std::cout << std::endl;


	std::cout << YLWB "+++ empty() +++" NC << std::endl;
	std::cout << "s2 empty()? " << s2.empty() << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "+++ size() +++" NC << std::endl;
	std::cout << "s2 size()? " << s2.size() << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "+++ pop() +++" NC << std::endl;
	std::cout << "s2 top(): " << s2.top() << std::endl;
	s2.pop();
	std::cout << "s2 top() after pop(): " << s2.top() << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "+++ copy constructor +++" NC << std::endl;
	TYPE::stack<int>						s4(s2);

	std::cout << "s4(s2)" << std::endl;
	std::cout << "s4 top(): " << s4.top() << std::endl;
	std::cout << "s4 size(): " << s4.size() << std::endl;
	std::cout << "s4 empty(): " << s4.empty() << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "+++ operator= +++" NC << std::endl;
	TYPE::stack<int>						s6;

	std::cout << "s6 = s4" << std::endl;
	s6 = s4;
	std::cout << "s6 top(): " << s6.top() << std::endl;
	std::cout << "s6 size(): " << s6.size() << std::endl;
	std::cout << "s6 empty(): " << s6.empty() << std::endl;
	std::cout << "s6.push(7)" << std::endl;
	s6.push(7);
	std::cout << "s6.top(): " << s6.top() << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "+++ comparisons +++" NC << std::endl;
	std::cout << "s2 == s4 ? " << (s2 == s4) << std::endl;
	std::cout << "s2 != s4 ? " << (s2 != s4) << std::endl;
	std::cout << "s2 == s6 ? " << (s2 == s6) << std::endl;
	std::cout << "s2 >= s4 ? " << (s2 >= s4) << std::endl;
	std::cout << "s2 >  s4 ? " << (s2 > s4) << std::endl;
	std::cout << "s2 <= s4 ? " << (s2 <= s4) << std::endl;
	std::cout << "s2 <  s4 ? " << (s2 < s4) << std::endl;
	std::cout << "s2 <  s6 ? " << (s2 < s6) << std::endl;
	std::cout << "s6 >  s2 ? " << (s6 > s2) << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "+++ std vector with ft stack +++" NC << std::endl;
	TYPE::stack<int, std::vector<int> >	s10;
	for (size_t i = 0; i < 7; ++i) {
		s10.push(i);
		std::cout << "push: " << i << std::endl;
		std::cout << "top:  " << s10.top() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "s10 size(): " << s10.size() << std::endl;
	std::cout << "s10 empty(): " << s10.empty() << std::endl;
	s10.pop();
	std::cout << "s10 top() after pop(): " << s10.top() << std::endl;
	std::cout << std::endl;
}

int	main(int argc, char *argv[]) {
	std::string	arg;

	if (argv[1])
		arg = argv[1];
	else
		arg = argv[0];
	if (arg == "vector")
		test_vector();
	else if (arg == "map")
		test_map();
	else if (arg == "stack")
		test_stack();
	else {
		test_map();
		test_vector();
		test_stack();
	}
	return (0);
}