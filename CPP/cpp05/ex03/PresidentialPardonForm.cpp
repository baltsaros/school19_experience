/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:32 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:53:33 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PrPardon", 25, 5), _target("unknown") {
	std::cout << CYNB "PresidentialPardonForm was filled!" NC << " Target is ";
	std::cout << this->_target << "." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
	: AForm("PrPardon", 25, 5), _target(target) {
	std::cout << CYNB "PresidentialPardonForm was filled!" NC << " Target is ";
	std::cout << this->_target << "." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) {
	std::cout << CYNB "Copy PresidentialPardonForm" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
PresidentialPardonForm::~PresidentialPardonForm(void) {
	// std::cout << REDB "PresidentialPardonForm with a target " NC;
	// std::cout << this->_target << REDB " was torn apart!" NC;
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

void	PresidentialPardonForm::formAction(void) const {
	std::cout << "Our benevolent president Zaphod Beeblebrox decided to pardon " GRNB;
	std::cout << this->getTarget() << NC "!" << std::endl;
	return ;
}