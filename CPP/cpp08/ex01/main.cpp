#include <iostream>
#include "Span.cpp"
// #include "Span.hpp"

int	main(void) {
	std::cout << YLWB "Int vector of size 5\n" NC;
	std::cout << std::endl;
	Span<int>	sp1(5);
	
	std::cout << YLWB "+++ Testing empty cntr exception +++\n" NC;
	try {
		sp1.longestSpan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << YLWB "+++ Testing empty cntr exception +++\n" NC;
	try {
		sp1.shortestSpan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Adding one element: ";
	sp1.addNumber(5);
	std::cout << sp1;
	std::cout << YLWB "+++ Testing one element exception +++\n" NC;
	try {
		sp1.longestSpan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << YLWB "+++ Testing one element exception +++\n" NC;
	try {
		sp1.shortestSpan();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Filling the container: ";
	sp1.addNumber(1);
	sp1.addNumber(2);
	sp1.addNumber(3);
	sp1.addNumber(44);
	std::cout << sp1;
	std::cout << YLWB "+++ Testing overflow exception +++\n" NC;
	try {
		sp1.addNumber(6);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << YLWB "+++ Testing max span +++\n" NC;
	try {
		std::cout << "Longest span: " << sp1.longestSpan();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << YLWB "+++ Testing min span +++\n" NC;
	try {
		std::cout << "Shortest span: " << sp1.shortestSpan();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	Span<int>	sp2(5);
	sp2.addNumber(-100);
	sp2.addNumber(-3);
	sp2.addNumber(-13);
	sp2.addNumber(-43);
	sp2.addNumber(10);
	std::cout << sp2;
	std::cout << YLWB "+++ Testing min span with negative numbers +++\n" NC;
	try {
		std::cout << "Shortest span: " << sp2.shortestSpan();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << YLWB "+++ Testing maxn span with negative numbers +++\n" NC;
	try {
		std::cout << "Shortest span: " << sp2.longestSpan();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
