/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:44 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:53:45 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Bureaucrat.hpp"

//	CONSTRUCTORS
Bureaucrat::Bureaucrat(void) : _name("lofi"), _grade(150) {
	std::cout << YLWB "A standard bureaucrat was born!" NC << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	// std::cout << YLWB "Bureaucrat " NC << this->_name;
	// std::cout << YLWB " was born!" NC << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	std::cout << YLWB "Copy Bureaucrat" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Bureaucrat::~Bureaucrat(void) {
	// std::cout << REDB "Bureaucrat " NC << this->_name;
	// std::cout << REDB " was buried under the piles of paper!" NC;
	// std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << YLW "Assigning Bureaucrat" NC << std::endl;
	if (this != &rhs) {
		*((std::string*)(&this->_name)) = rhs._name;
		this->_grade = rhs._grade;
	}
	return (*this);
}

//	OTHERS
std::string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::increment(void) {
	if (this->_grade <= 1)
		throw(GradeTooHighException());
	else
		this->_grade--;
	return ;
}

void	Bureaucrat::decrement(void) {
	if (this->_grade >= 150)
		throw(GradeTooLowException());
	else
		this->_grade++;
	return ;
}

void	Bureaucrat::signForm(AForm &f) {
	if (this->_grade <= f.getGradeSign())
	{
		std::cout << YLWB "Bureaucrat " << this->_name << NC " signed the ";
		std::cout << CYNB "form " << f.getName() << NC "." << std::endl;
	}
	else
	{
		std::cout << YLWB "Bureaucrat " << this->_name << NC " coudn't ";
		std::cout << CYNB "sign form " << f.getName() << NC " because ";
		// std::cout << std::endl;
	}
	f.beSigned(*this);
	return ;
}

void	Bureaucrat::executeForm(AForm const &f) {
	if (f.execute(*this))
	{
		std::cout << YLWB "Bureaucrat " << this->_name << NC " executed the ";
		std::cout << CYNB "form " << f.getName() << NC "." << std::endl;
	}
	else
	{
		std::cout << YLWB "Bureaucrat " << this->_name << NC " coudn't ";
		std::cout << "execute the form " CYNB << f.getName() << NC "." << std::endl;
	}
	return;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw() {
	return (REDL "Grade is too high!" NC);
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw() {
	return (REDL "Grade is too low!" NC);
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & bob) {
	o << YLWB "Bureaucrat " << bob.getName() << NC " has a grade ";
	o << bob.getGrade() << "." << std::endl;
	return (o);
}