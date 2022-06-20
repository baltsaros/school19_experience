#include "Harl.hpp"

Harl::Harl(void){
	std::cout << "Harl is here!" << std::endl;
	this->_functions[0].name = "DEBUG";
	this->_functions[0].fun = &Harl::_debug;
	this->_functions[1].name = "INFO";
	this->_functions[1].fun = &Harl::_info;
	this->_functions[2].name = "WARNING";
	this->_functions[2].fun = &Harl::_warning;
	this->_functions[3].name = "ERROR";
	this->_functions[3].fun = &Harl::_error;
	return ;
}

Harl::~Harl(void){
	std::cout << "Harl is sad. Harl is leaving..." << std::endl;
	return ;
}

void	Harl::_debug(void){
	std::cout << "Harl really likes coding! ";
	std::cout << "This activity takes a lot of his time." << std::endl;
	return ;
}

void	Harl::_info(void){
	std::cout << "But one thing really grinds his gears: ";
	std::cout << "quantity does not always tranform into quality!" << std::endl;
	return ;
}

void	Harl::_warning(void){
	std::cout << "After many sleepless nights and busy days ";
	std::cout << "Harl believes he deserves to be a guru of C and C++!" << std::endl;
	return ;
}

void	Harl::_error(void){
	std::cout << "Alas, the reality is the opposite :( ";
	std::cout << "Therefore, Harl wants to change his programming language!" << std::endl;
	return ;
}

void	Harl::complain(std::string level){
	size_t		i = 0;
	while (i < 4 && this->_functions[i].name != level)
			++i;
	if (i < 4)
		(this->*_functions[i].fun)();
	return ;
}
