#include <iostream>
#include <map>
#include <string>
#include <iterator>
// #include "map.hpp"
#include "rbtree.hpp"

int	main(void) {
	ft::RBTree<int>	tr;
	ft::RBTree<int>	tr2;

	// tr.insert(10);
	// std::cout << "it1\n";
	// tr.printNode();
	// tr.insert(1);
	// std::cout << "it2\n";
	// tr.printNode();
	// tr.insert(3);
	// tr.insert(13);
	// tr.insert(11);
	// tr.insert(15);
	// tr.insert(14);
	// std::cout << "it3\n";
	tr.insert(3);
	tr.insert(1);
	tr.insert(5);
	// std::cout << "\nit1\n";
	// tr.printNode();
	tr.insert(7);
	tr.insert(6);
	// std::cout << "\nit2\n";
	tr.printNode();
	return (0);
}