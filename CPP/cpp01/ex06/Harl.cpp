/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:43:23 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 09:43:24 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define NC "\e[0m"
#define GRN "\e[0;32m"

Harl::Harl(void){
	std::cout << GRN "Harl is here!" NC << std::endl;
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
	std::cout << GRN "Harl is sad. Harl is leaving..." NC << std::endl;
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
	switch(i){
		case 0:
			(this->*_functions[0].fun)();
		case 1:
			(this->*_functions[1].fun)();
		case 2:
			(this->*_functions[2].fun)();
		case 3:
			(this->*_functions[3].fun)();
	}
	if (i == 4)
		std::cout << "[Harl seems to be lost in thought]" << std::endl;
	return ;
}
