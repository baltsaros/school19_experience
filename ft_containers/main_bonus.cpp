/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 07:57:47 by abuzdin           #+#    #+#             */
/*   Updated: 2023/01/23 07:57:48 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include "containers/set.hpp"

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

int	main(void) {
	{
		std::cout << GRNB "TESTING SET\n" NC;
		TYPE::set<int>						s1;
		TYPE::set<int>::iterator			it1;
		TYPE::set<int>::reverse_iterator	rit1;

		s1.insert(0);
		s1.insert(1);
		s1.insert(2);
		s1.insert(3);
		s1.insert(4);
		s1.insert(5);

		// ITERATORS
		{
			std::cout << YLWB "\n+++++++++ ITERATORS +++++++++\n" NC;
			std::cout << YLW "\n+++ begin() +++\n" NC;
			std::cout << "it1 = s1(begin())\n";
			it1 = s1.begin();
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
			std::cout << "it1 = s1(end())\n";
			it1 = s1.end();
			std::cout << "it1--\n";
			it1--;
			printIter(it1);

			std::cout << YLW "\n+++ rbegin() +++\n" NC;
			std::cout << "rit1 = s1(rbegin()\n";
			rit1 = s1.rbegin();
			printIter(rit1);

			std::cout << YLW "\n+++ rend() +++\n" NC;
			std::cout << "rit1 = s1(rend()\n";
			rit1 = s1.rend();
			std::cout << "rit1--\n";
			rit1--;
			printIter(rit1);
		}

		// CAPACITY
		{
			std::cout << YLWB "\n+++++++++ CAPACITY +++++++++\n" NC;
			std::cout << YLW "\n+++ empty() +++\n" NC;
			std::cout << "s1.empty()\n";
			std::cout << s1.empty() << "\n";

			std::cout << "\nCreating empty s3\n";
			TYPE::set<int>	s3;

			std::cout << "s3.empty()\n";
			std::cout << s3.empty() << "\n";


			std::cout << YLW "\n+++ size() +++\n" NC;
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			std::cout << "s3.size()\n";
			std::cout << s3.size() << "\n";

			std::cout << "\nerase(3): deleting one element\n";
			std::cout << s1.erase(3) << std::endl;
			std::cout << "s1.empty()\n";
			std::cout << s1.empty() << "\n";
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";

			std::cout << "\nerase(10): deleting non-existing element\n";
			std::cout << s1.erase(10) << std::endl;
			std::cout << "s1.empty()\n";
			std::cout << s1.empty() << "\n";
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";

			std::cout << YLW "\n+++ max_size() +++\n" NC;
			std::cout << "s1.max_size()\n";
			std::cout << s1.max_size() << "\n";
		}

		// MODIFIERS
		{
			TYPE::set<int>	s3;

			std::cout << YLWB "\n+++++++++ MODIFIERS +++++++++\n" NC;
			std::cout << "\n+++ clear() +++\n";
			std::cout << "s1.empty()\n";
			std::cout << s1.empty() << "\n";
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			s1.clear();
			std::cout << "after clear():\n";
			std::cout << "s1.empty()\n";
			std::cout << s1.empty() << "\n";
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";

			std::cout << YLW "\n+++ insert(value) +++\n" NC;
			s1.insert(0);
			s1.insert(1);
			s1.insert(2);
			s1.insert(3);
			s1.insert(4);
			s1.insert(5);
			for (it1 = s1.begin(); it1 != s1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ insert(it, value) +++\n" NC;
			it1 = s3.begin();
			std::cout << "\nEmpty sets, it = m.begin()\n";
			std::cout << "insert(it, 2)\n";
			it1 = s3.insert(it1, 2);
			std::cout << "it1: ";
			printIter(it1);

			it1 = s1.begin();
			std::cout << "\nFilled sets, it = m.begin()\n";
			std::cout << "insert(it, 3)\n";
			it1 = s1.insert(it1, 3);
			std::cout << "it1: ";
			printIter(it1);

			std::cout << "\ninsert(it, 8)\n";
			it1 = s1.insert(it1, 8);
			std::cout << "it1: ";
			printIter(it1);

			std::cout << YLW "\n+++ insert(iterator first, iterator last) +++\n" NC;
			s3.clear();
			std::cout << "s3.empty(): " << s3.empty() << std::endl;
			std::cout << "s1.empty(): " << s1.empty() << std::endl;
			std::cout << "s3(s1.begin(), s1.end())\n";
			s3.insert(s1.begin(), s1.end());
			std::cout << "s3.empty(): " << s3.empty() << std::endl;
			for (it1 = s3.begin(); it1 != s3.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ erase(iterator pos) +++\n" NC;
			it1 = s1.begin();
			++it1;
			++it1;
			std::cout << "it1\n";
			printIter(it1);
			std::cout << "s1.erase(it1)\n";
			s1.erase(it1);
			for (it1 = s1.begin(); it1 != s1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ erase() +++\n" NC;
			std::cout << "s1.erase(1): " << s1.erase(1) << "\n";
			for (it1 = s1.begin(); it1 != s1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ erase(iterator first, iterator last) +++\n" NC;
			std::cout << "it1 = s1.end()\nit1--\n";
			it1 = s1.end();
			it1--;
			printIter(it1);
			std::cout << "s1.erase(s1.begin(), it1)\n";
			s1.erase(s1.begin(), it1);
			for (it1 = s1.begin(); it1 != s1.end(); it1++)
				printIter(it1);

			std::cout << YLW "\n+++ swap(set) +++\n" NC;
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			std::cout << "s3.size()\n";
			std::cout << s3.size() << "\n";
			std::cout << "\ns1 elements:\n";
			for (it1 = s1.begin(); it1 != s1.end(); it1++)
				printIter(it1);
			std::cout << "\ns3 elements:\n";
			for (it1 = s3.begin(); it1 != s3.end(); it1++)
				printIter(it1);

			std::cout << "\ns1.swap(s3)\n";
			s1.swap(s3);
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			std::cout << "s3.size()\n";
			std::cout << s3.size() << "\n";
			std::cout << "\ns1 elements:\n";
			for (it1 = s1.begin(); it1 != s1.end(); it1++)
				printIter(it1);
			std::cout << "\ns3 elements:\n";
			for (it1 = s3.begin(); it1 != s3.end(); it1++)
				printIter(it1);
		}

		// LOOKUPS
		{
			std::cout << YLWB "\n+++++++++ LOOKUPS +++++++++\n" NC;
			std::cout << YLW "\n+++ count() +++\n" NC;
			std::cout << "\ns1 elements:\n";
			printSet(s1, it1, "");
			std::cout << "\ns1.count(1) - " << s1.count(1) << std::endl;
			std::cout << "s1.count(4) - " << s1.count(4) << std::endl;
			std::cout << "s1.count(10) - " << s1.count(10) << std::endl;

			std::cout << YLW "\n+++ find() +++\n" NC;
			std::cout << "s1.find(1) - ";
			printIter(s1.find(1));
			std::cout << "s1.find(3) - ";
			printIter(s1.find(3));

			std::cout << YLW "\n+++ lower_bound() +++\n" NC;
			std::cout << "s1.lower_bound(0) - ";
			printIter(s1.lower_bound(0));
			std::cout << "s1.lower_bound(2) - ";
			printIter(s1.lower_bound(2));

			std::cout << YLW "\n+++ upper_bound() +++\n" NC;
			std::cout << "s1.upper_bound(0) - ";
			printIter(s1.upper_bound(0));
			std::cout << "s1.upper_bound(2) - ";
			printIter(s1.upper_bound(2));
		
			std::cout << YLW "\n+++ equal_range() +++\n" NC;
			std::cout << "s1.equal_range(0)\n";
			std::cout << "lower: ";
			printIter(s1.equal_range(0).first);
			std::cout << "upper: ";
			printIter(s1.equal_range(0).second);
			std::cout << "s1.equal_range(4)\n";
			std::cout << "lower: ";
			printIter(s1.equal_range(4).first);
			std::cout << "upper: ";
			printIter(s1.equal_range(4).second);
		}

		// OBSERVERS
		{
			TYPE::set<int>::iterator	it3;

			it1 = s1.begin();
			it3 = s1.begin();
			it3++;
			std::cout << YLWB "\n+++++++++ OBSERVERS +++++++++\n" NC;
			std::cout << YLW "\n+++ key_comp() +++\n" NC;
			std::cout << "it1 - ";
			printIter(it1);
			std::cout << "it3 - ";
			printIter(it3);
			std::cout << "s1.key_comp()(*it1, *it3) - ";
			std::cout << s1.key_comp()(*it1, *it3);
			std::cout << std::endl;

			std::cout << "s1.key_comp()(*it3, *it1) - ";
			std::cout << s1.key_comp()(*it3, *it1);
			std::cout << std::endl;

			std::cout << YLW "\n+++ value_comp() +++\n" NC;
			std::cout << "s1.value_comp()(*it3, *it1) - ";
			std::cout << s1.value_comp()(*it3, *it1);
			std::cout << std::endl;
			std::cout << "s1.value_comp()(*it1, *it3) - ";
			std::cout << s1.value_comp()(*it1, *it3);
			std::cout << std::endl;
		}

		// COMPARISONS
		{
			TYPE::set<int>				s3;
			TYPE::set<int>::iterator		it3;

			std::cout << YLWB "\n+++++++++ COMPARISONS +++++++++\n" NC;
			std::cout << YLW "\n+++ operator== +++\n" NC;
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			std::cout << "s3.size()\n";
			std::cout << s3.size() << "\n";
			std::cout << "s1 == s3 ? " << (s1 == s3) << "\n";
			std::cout << "s1 != s3 ? " << (s1 != s3) << "\n";
			std::cout << "s1 > s3 ? " << (s1 > s3) << "\n";
			std::cout << "s1 >= s3 ? " << (s1 >= s3) << "\n";
			std::cout << "s1 < s3 ? " << (s1 < s3) << "\n";
			std::cout << "s1 <= s3 ? " << (s1 <= s3) << "\n";
			printSet(s1, s1.begin(), "");

			std::cout << "\ns3 = s1\n"; 
			s3 = s1;
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			std::cout << "s3.size()\n";
			std::cout << s3.size() << "\n";
			std::cout << "s1 == s3 ? " << (s1 == s3) << "\n";
			std::cout << "s1 != s3 ? " << (s1 != s3) << "\n";
			std::cout << "s1 > s3 ? " << (s1 > s3) << "\n";
			std::cout << "s1 >= s3 ? " << (s1 >= s3) << "\n";
			std::cout << "s1 < s3 ? " << (s1 < s3) << "\n";
			std::cout << "s1 <= s3 ? " << (s1 <= s3) << "\n";

			std::cout << YLW "\n+++ swap(lhs, rhs) +++\n" NC;
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			std::cout << "s3.size()\n";
			std::cout << s3.size() << "\n";
			std::cout << "after swap:\n";
			swap(s1, s3);
			std::cout << "s1.size()\n";
			std::cout << s1.size() << "\n";
			std::cout << "s3.size()\n";
			std::cout << s3.size() << "\n";
		}
	}
}