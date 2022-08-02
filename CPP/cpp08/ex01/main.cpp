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
	return (0);
}
