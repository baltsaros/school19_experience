#include <iostream>
#include "Span.cpp"
#include <stdlib.h>
#include <time.h>
// #include "Span.hpp"

int	main(void) {
	std::cout << YLWB "Test from the subject\n" NC;
	Span<int>	sp = Span<int>(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << std::endl;


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


	std::cout << YLWB "+++ Testing max span with negative numbers +++\n" NC;
	try {
		std::cout << "Shortest span: " << sp2.longestSpan();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;


	std::cout << YLWB "+++ Testing insetion with range iterators +++\n" NC;
	Span<float>			sp3(5);
	std::vector<float>	vct = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f};

	std::cout << "The container before: " << sp3;
	try {
		std::cout << "Copying elements..." << std::endl;
		sp3.addNumber(vct.begin(), vct.end());
		std::cout << "The container after: " << sp3;
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "The container after: " << sp3;
	std::cout << std::endl;


	std::cout << YLWB "+++ Testing big array +++\n" NC;
	Span<int>			sp4(15000);
	std::vector<int>	vct1;

	srand(time(0));
	for (size_t i = 0; i < 20000; i++) {
		vct1.push_back(rand() % 256);
	}
	std::cout << "The container capacity is " << sp4.getCapacity() << std::endl;
	std::cout << "The container size is " << sp4.getSize() << std::endl;
	std::cout << "Its first element is ";
	try {
		std::cout << sp4[0] << std::endl;
		std::cout << "Its last element is ";
		std::cout << sp4[14999] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "The vector size is " << vct1.size() << std::endl;
	try {
		std::cout << "Copying elements..." << std::endl;
		sp4.addNumber(vct1.begin(), vct1.end());
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "The container size is " << sp4.getSize() << std::endl;
	std::cout << "Its first element is ";
	try {
		std::cout << sp4[0] << std::endl;
		std::cout << "Its last element is ";
		std::cout << sp4[14999] << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << sp4.longestSpan();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "Shortest span: " << sp4.shortestSpan();
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
