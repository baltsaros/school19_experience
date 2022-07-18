#include <time.h>
#include <stdlib.h>
#include "include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("Robotomy", 72, 45), _target("unknown") {
	int	chance;

	std::cout << "Bzzzzzzzzzzzzzzzzzzzz..." << std::endl;
	srand(time(NULL));
	chance = rand() % 2 + 1;
	if (chance % 2)
	{
		std::cout << "Attention, please! " GRNB << this->getTarget();
		std::cout << NC "was succesfully robotomized!" << std::endl;
	}
	else
		std::cout << "DAMN! The operation failed! Run!" << std::endl;
	// std::cout << CYNB "RobotomyRequestForm was filled!" NC << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target)
	: AForm("Robotomy", 72, 45), _target(target) {
	int	chance;

	std::cout << "Bzzzzzzzzzzzzzzzzzzzz..." << std::endl;
	srand(time(NULL));
	chance = rand() % 2 + 1;
	if (chance % 2)
	{
		std::cout << "Attention, please! " GRNB << this->getTarget();
		std::cout << NC "was succesfully robotomized!" << std::endl;
	}
	else
		std::cout << "DAMN! The operation failed! Run!" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {
	std::cout << CYNB "Copy RobotomyRequestForm" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
RobotomyRequestForm::~RobotomyRequestForm(void) {
	// std::cout << REDB "RobotomyRequestForm " NC << this->_name;
	// std::cout << REDB " was torn apart!" NC;
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
