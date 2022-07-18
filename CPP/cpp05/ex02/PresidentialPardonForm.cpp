#include "include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PrPardon", 25, 5), _target("unknown") {
	std::cout << "Our benevolent president Zaphod Beeblebrox decided to pardon " GRNB;
	std::cout << this->getTarget() << NC "!" << std::endl;
	// std::cout << CYNB "PresidentialPardonForm was filled!" NC << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
	: AForm("PrPardon", 25, 5), _target(target) {
	std::cout << "Our benevolent president Zaphod Beeblebrox decided to pardon " GRNB;
	std::cout << this->getTarget() << NC "!" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) {
	std::cout << CYNB "Copy PresidentialPardonForm" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm(void) {
	// std::cout << REDB "PresidentialPardonForm " NC << this->_name;
	// std::cout << REDB " was torn apart!" NC;
	// std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	std::cout << CYN "Assigning PresidentialPardonForm" NC << std::endl;
	if (this != &rhs)
		*((std::string*)(&this->_target)) = rhs._target;
	return (*this);
}

//	OTHERS
std::string	PresidentialPardonForm::getTarget(void) const {
	return (this->_target);
}
