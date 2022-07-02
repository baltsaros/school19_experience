#include "Bureaucrat.hpp"

int	main(void) {
	std::cout << "Case: normal" << std::endl;
	try {
		Bureaucrat	bur("Bob", 45);
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "Case: too low" << std::endl;
	try {
		Bureaucrat	bur("Jim", 150);
		bur.decrement();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "Case: too high" << std::endl;
	try {
		Bureaucrat	bur("Karen", 1);
		bur.increment();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "Case: negative" << std::endl;
	try {
		Bureaucrat	bur("Tom", -1);
		bur.increment();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << "Case: over 150" << std::endl;
	try {
		Bureaucrat	bur("Alice", 999);
		bur.increment();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
