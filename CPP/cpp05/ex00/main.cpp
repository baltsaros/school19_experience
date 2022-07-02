#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	bur("bob", 45);
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what();
	}
	try {
		Bureaucrat	bur("jim", 150);
		bur.decrement();
	}
	catch (std::exception& e){
		std::cerr << "Error: " << e.what();
	}
	return (0);
}
