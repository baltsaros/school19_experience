/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:51 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:53:52 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <time.h>
// #include <stdlib.h>
#include <cstdlib>
#include "include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy", 72, 45), _target("unknown") {
	std::cout << CYNB "RobotomyRequestForm was filled!" NC << " Target is ";
	std::cout << this->_target << "." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
	: AForm("Robotomy", 72, 45), _target(target) {
	std::cout << CYNB "RobotomyRequestForm was filled!" NC << " Target is ";
	std::cout << this->_target << "." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {
	std::cout << CYNB "Copy RobotomyRequestForm" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm(void) {
	// std::cout << REDB "RobotomyRequestForm with a target " NC;
	// std::cout << this->_target << REDB " was torn apart!" NC;
	// std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	std::cout << CYN "Assigning RobotomyRequestForm" NC << std::endl;
	if (this != &rhs)
		*((std::string*)(&this->_target)) = rhs._target;
	return (*this);
}

//	OTHERS
std::string	RobotomyRequestForm::getTarget(void) const {
	return (this->_target);
}

void	RobotomyRequestForm::formAction(void) const {
	int	chance;

	std::cout << "Bzzzzzzzzzzzzzzzzzzzz..." << std::endl;
	srand(time(0));
	chance = rand() % 2 + 1;
	if (chance % 2)
	{
		std::cout << "Attention, please! " GRNB << this->getTarget();
		std::cout << NC " was succesfully robotomized!" << std::endl;
	}
	else
		std::cout << "DAMN! The operation failed! Run!" << std::endl;
	return ;
}
