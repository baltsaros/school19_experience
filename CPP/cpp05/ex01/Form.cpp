/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:54:10 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:54:11 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//	CONSTRUCTORS
Form::Form(void) :
	_name("lofi"), _gradeSign(25), _gradeExec(50), _signature(false){
	std::cout << CYNB "Form was created!" NC << std::endl;
	return ;
}

Form::Form(std::string name, int sign, int exec) :
	_name(name), _gradeSign(sign), _gradeExec(exec), _signature(false) {
	if (sign > 150)
		throw(GradeTooLowToSign());
	else if (sign < 1)
		throw(GradeTooHighToSign());
	if (exec > 150)
		throw(GradeTooLowToExec());
	else if (exec < 1)
		throw(GradeTooHighToExec());
	// std::cout << CYNB "Form " NC << this->_name;
	// std::cout << CYNB " was created!" NC << std::endl;
	return ;
}

Form::Form(Form const &src) :
	_name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec), _signature(src._signature) {
	std::cout << CYNB "Copy Form" NC << std::endl;
	// *this = src;
	return ;
}

//	DESTRUCTOR
Form::~Form(void) {
	// std::cout << REDB "Form " NC << this->_name;
	// std::cout << REDB " was torn apart!" NC;
	// std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Form&	Form::operator=(Form const &rhs) {
	std::cout << CYN "Assigning Form" NC << std::endl;
	if (this != &rhs) {
		*((std::string*)(&this->_name)) = rhs._name;
		*((int*)(&this->_gradeSign)) = rhs._gradeSign;
		*((int*)(&this->_gradeExec)) = rhs._gradeExec;
		this->_signature = rhs._signature;
	}
	return (*this);
}

//	OTHERS
std::string	Form::getName(void) const {
	return (this->_name);
}

int	Form::getGradeSign(void) const {
	return (this->_gradeSign);
}

int	Form::getGradeExec(void) const {
	return (this->_gradeExec);
}

bool	Form::getSignature(void) const {
	return (this->_signature);
}

bool	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() <= this->_gradeSign)
	{
		this->_signature = true;
		return (this->_signature);
	}
	throw(GradeTooLowToSign());
	return (this->_signature);
}

const char*	Form::GradeTooHighToSign::what(void) const throw() {
	return (REDL "Grade is too high to sign the form!" NC);
}

const char*	Form::GradeTooLowToSign::what(void) const throw() {
	return (REDL "Grade is too low to sign the form!" NC);
}

const char*	Form::GradeTooHighToExec::what(void) const throw() {
	return (REDL "Grade is too high to execute the form!" NC);
}

const char*	Form::GradeTooLowToExec::what(void) const throw() {
	return (REDL "Grade is too low to execute the form!" NC);
}

std::ostream &	operator<<(std::ostream & o, Form const & form) {
	o << CYNB "Form " << form.getName() << NC ": min grade to sign is ";
	o << form.getGradeSign() << ", min grade to execute is ";
	o << form.getGradeExec() << ". ";
	if (form.getSignature())
		o << "Current form's status is signed." << std::endl;
	else
		o << "Current form's status is not signed." << std::endl;
	return (o);
}
