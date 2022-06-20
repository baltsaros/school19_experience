#include "Harl.hpp"

int	main(void){
	Harl	customer;

	std::cout << "TESTING!" << std::endl;

	std::cout << "Level: debug" << std::endl;
	customer.complain("DEBUG");
	std::cout << std::endl;
	
	std::cout << "Level: info" << std::endl;
	customer.complain("INFO");
	std::cout << std::endl;
	
	std::cout << "Level: warning" << std::endl;
	customer.complain("WARNING");
	std::cout << std::endl;
	
	std::cout << "Level: error" << std::endl;
	customer.complain("ERROR");
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}