#include "Harl.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define REDB "\e[41m"

int	main(void){
	Harl	customer;

	std::cout << "TESTING!" << std::endl;
	std::cout << std::endl;


	std::cout << "Level: " << RED "debug" NC << std::endl;
	customer.complain("DEBUG");
	std::cout << std::endl;

	std::cout << "Level: " << RED "info" NC << std::endl;
	customer.complain("INFO");
	std::cout << std::endl;
	
	std::cout << "Level: " <<  RED "warning" NC << std::endl;
	customer.complain("WARNING");
	std::cout << std::endl;
	
	std::cout << "Level: " <<  RED "error" NC << std::endl;
	customer.complain("ERROR");
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}
