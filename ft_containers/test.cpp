#include <iostream>
#include <iterator>
#include <vector>
#include "vector.hpp"

template <class InputIt>
void	printIter(InputIt it) {
	std::cout << *it;
}

template <class Vector, class InputIt>
void	printVector(Vector v, InputIt it, std::string type) {
	std::cout << type << std::endl;
	size_t	i = 0;
	for (it = v.begin(); it != v.end(); it++) {
		printIter(it);
		std::cout << " ";
	}
	std::cout << std::endl;
}

int	main(void) {
	ft::vector<int>				v1;
	ft::vector<int>::iterator	it1;
	std::vector<int>			v2;
	std::vector<int>::iterator	it2;

	for (size_t i = 0; i != 6; ++i) {
		v1.push_back(i);
		v2.push_back(i);
	}
	std::cout << "initial vectors\n";
	printVector(v1, it1, "FT");
	printVector(v2, it2, "STD");
	it1 = v1.begin() + 2;
	std::cout << "it1: ";
	printIter(it1);
	std::cout << std::endl;
	it2 = v2.begin() + 2;
	std::cout << "it2: ";
	printIter(it2);
	std::cout << std::endl;

	std::cout << "insert(it, begin, end\n";
	v1.insert(it1, v1.begin(), v1.end());
	printVector(v1, it1, "FT");
	v2.insert(it2, v2.begin(), v2.end());
	printVector(v2, it2, "STD");
	return (0);
}