#include <iostream>
#include <string>

int	main(void){
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR;
	std::string	&stringREF = str;

	stringPTR = &str;

	std::cout << "Printing memory address:\n";
	std::cout << "str: " << &str << std::endl;
	std::cout << "ptr: " << stringPTR << std::endl;
	std::cout << "ref: " << &stringREF << std::endl;
	std::cout << std::endl;

	std::cout << "Printing values:\n";
	std::cout << "str: " << str << std::endl;
	std::cout << "ptr: " << *stringPTR << std::endl;
	std::cout << "ref: " << stringREF << std::endl;
	return (0);
}