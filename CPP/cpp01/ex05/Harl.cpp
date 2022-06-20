#include "Harl.hpp"

Harl::Harl(void){
	std::cout << "Harl is here!" << std::endl;
	return ;
}

Harl::~Harl(void){
	std::cout << "Harl is sad. Harl is leaving..." << std::endl;
	return ;
}

void	Harl::_debug(void){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
	return ;
}

void	Harl::_info(void){
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
	return ;
}

void	Harl::_warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
	return ;
}

void	Harl::_error(void){
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
	return ;
}

void	Harl::complain(std::string level){
	static Harl::_funs	functions[4] = {
		{"DEBUG", &Harl::_debug},
		{"INFO", &Harl::_info},
		{"WARNING", &Harl::_warning},
		{"ERROR", &Harl::_error}
	};
	size_t		i = 0;
	while (i < 4 && functions[i].name != level)
		++i;
	functions[i].fun();
	return ;
}