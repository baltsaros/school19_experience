#include "Harl.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define REDB "\e[41m"

int	main(int argc, char *argv[]){
	Harl	customer;

	if (argc != 2){
		std::cerr << REDB "Error: ";
		std::cerr << "Invalid amount of arguments!" NC << std::endl;
		return (-1);
	}

	std::cout << "TESTING!" << std::endl;
	std::cout << std::endl;

	std::cout << "Your input: " << argv[1] << std::endl;
	customer.complain(argv[1]);
	std::cout << std::endl;
	
	std::cout << "Standard levels." << std::endl;
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
	
	std::cout << "Invalid level" << std::endl;
	customer.complain("toto");
	std::cout << std::endl;

	std::cout << std::endl;
	return (0);
}