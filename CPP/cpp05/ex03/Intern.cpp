/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:40 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:53:42 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Intern.hpp"

//	CONSTRUCTORS
Intern::Intern(void) {
	std::cout << GRNB "Intern was hired!" NC << std::endl;
	static t_forms	forms[3] = {
		{"presidential pardon", &Intern::_pardon},
		{"robotomy request", &Intern::_robotomy},
		{"shrubbery creation", &Intern::_shrubbery}
	};
	this->_forms = forms;
	return ;
}

Intern::Intern(Intern const &src) {
	std::cout << GRNB "Cloning Intern" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Intern::~Intern(void) {
	std::cout << REDB "Intern't" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Intern&	Intern::operator=(Intern const &rhs) {
	std::cout << GRN "Assigning Intern" NC << std::endl;
	if (this != &rhs)
		this->_forms = rhs._forms;
	return (*this);
}

//	OTHERS
AForm*	Intern::_pardon(std::string target) {
	AForm	*pardon;

	pardon = new PresidentialPardonForm(target);
	return (pardon);
}

AForm*	Intern::_robotomy(std::string target) {
	AForm	*robotomy;

	robotomy = new RobotomyRequestForm(target);
	return (robotomy);
}

AForm*	Intern::_shrubbery(std::string target) {
	AForm	*shrubbery;

	shrubbery = new ShrubberyCreationForm(target);
	return (shrubbery);
}

AForm*	Intern::makeForm(std::string form, std::string target) {
	if (target.empty())
		throw(NotValidTarget());
	if (form.empty())
		throw(NotValidForm());
	std::string	lowered = strToLower(form);
	AForm		*ret;

	for (int i = 0; i < 4; ++i) {
		if (this->_forms[i].name == lowered)
		{
			ret = (this->*_forms[i].fun)(target);
			std::cout << "Intern creates the " CYNB << lowered;
			std::cout  << NC " form." << std::endl;
			return (ret);
		}
	}
	throw(NotValidForm());
}

const char*	Intern::NotValidTarget::what(void) const throw() {
	return (REDL "Target is not valid!" NC);
}

const char*	Intern::NotValidForm::what(void) const throw() {
	return (REDL "Form is not valid!" NC);
}

std::string	strToLower(std::string const form) {
	std::string	lowered;

	lowered = form;
	for (size_t i = 0; i < lowered.length(); ++i) {
		lowered[i] = std::tolower(lowered[i]);
	}
	return (lowered);
}