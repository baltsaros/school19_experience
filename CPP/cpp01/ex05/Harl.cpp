#include "Harl.hpp"

Harl::Harl(void){
	std::cout << "Harl is here!" << std::endl;
	static t_funs	funcs[4] = {
		{"DEBUG", &Harl::_debug},
		{"INFO", &Harl::_info},
		{"WARNING", &Harl::_warning},
		{"ERROR", &Harl::_error}
	};
	this->_functions = funcs;
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
