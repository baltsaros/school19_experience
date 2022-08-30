/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:46 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:53:47 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AForm.hpp"

//	CONSTRUCTORS
AForm::AForm(void) :
	_name("lofi"), _gradeSign(25), _gradeExec(50), _signature(false){
	std::cout << CYNB "AForm was created!" NC << std::endl;
	return ;
}

AForm::AForm(std::string name, int sign, int exec) :
	_name(name), _gradeSign(sign), _gradeExec(exec), _signature(false) {
	if (sign > 150)
		throw(GradeTooLowToSign());
	else if (sign < 1)
		throw(GradeTooHighToSign());
	if (exec > 150)
		throw(GradeTooLowToExec());
	else if (exec < 1)
		throw(GradeTooHighToExec());
	// std::cout << CYNB "AForm " NC << this->_name;
	// std::cout << CYNB " was created!" NC << std::endl;
	return ;
}

AForm::AForm(AForm const &src) :
	_name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec), _signature(src._signature) {
	std::cout << CYNB "Copy AForm" NC << std::endl;
	// *this = src;
	return ;
}

//	DESTRUCTOR
AForm::~AForm(void) {
	// std::cout << REDB "AForm " NC << this->_name;
	// std::cout << REDB " was torn apart!" NC;
	// std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
AForm&	AForm::operator=(AForm const &rhs) {
	std::cout << CYN "Assigning AForm" NC << std::endl;
	if (this != &rhs) {
		*((std::string*)(&this->_name)) = rhs._name;
		*((int*)(&this->_gradeSign)) = rhs._gradeSign;
		*((int*)(&this->_gradeExec)) = rhs._gradeExec;
		this->_signature = rhs._signature;
	}
	return (*this);
}

//	OTHERS
std::string	AForm::getName(void) const {
	return (this->_name);
}

int	AForm::getGradeSign(void) const {
	return (this->_gradeSign);
}

int	AForm::getGradeExec(void) const {
	return (this->_gradeExec);
}

bool	AForm::getSignature(void) const {
	return (this->_signature);
}

bool	AForm::beSigned(Bureaucrat const &b){
	if (b.getGrade() <= this->_gradeSign)
	{
		this->_signature = true;
		return (this->_signature);
	}
	throw(GradeTooLowToSign());
	return (this->_signature);
}

bool	AForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > this->_gradeExec)
		throw(GradeTooLowToExec());
	else if (!this->_signature)
		throw(FormNotSigned());
	else
	{
		this->formAction();
		return (true);
	}
	return (false);
}

const char*	AForm::GradeTooHighToSign::what(void) const throw() {
	return (REDL "Grade is too high to sign the form!" NC);
}

const char*	AForm::GradeTooLowToSign::what(void) const throw() {
	return (REDL "Grade is too low to sign the form!" NC);
}

const char*	AForm::GradeTooHighToExec::what(void) const throw() {
	return (REDL "Grade is too high to execute the form!" NC);
}

const char*	AForm::GradeTooLowToExec::what(void) const throw() {
	return (REDL "Grade is too low to execute the form!" NC);
}

const char*	AForm::FormNotSigned::what(void) const throw() {
	return (REDL "The form has not yet been signed!" NC);
}

std::ostream &	operator<<(std::ostream & o, AForm const & form) {
	o << CYNB "Form " << form.getName() << NC ": min grade to sign is ";
	o << form.getGradeSign() << ", min grade to execute is ";
	o << form.getGradeExec() << ". ";
	if (form.getSignature())
		o << "Current form's status is signed." << std::endl;
	else
		o << "Current form's status is not signed." << std::endl;
	return (o);
}
