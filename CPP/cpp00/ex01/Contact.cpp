/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:11:11 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/12 10:20:44 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static std::string	check_field(std::string str)
{
	while (str.length() == 0){
		std::cout << REDL "The field cannot be empty! Type something!" NC << std::endl;
		std::getline(std::cin, str);
	}
	return (str);
}

void	Contact::add(){
	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, this->_first_name);
	this->_first_name = check_field(this->_first_name);
	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, this->_last_name);
	this->_last_name = check_field(this->_last_name);
	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, this->_nickname);
	this->_nickname = check_field(this->_nickname);
	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, this->_number);
	this->_number = check_field(this->_number);
	std::cout << "Enter new contact's darkest secret:" << std::endl;
	std::getline(std::cin, this->_secret);
	this->_secret = check_field(this->_secret);
}

void	Contact::printContact(){
		std::cout << this->_first_name << std::endl;
		std::cout << this->_last_name << std::endl;
		std::cout << this->_nickname << std::endl;
		std::cout << this->_number << std::endl;
		std::cout << this->_secret << std::endl;
		std::cout << "Type a command (ADD, SEARCH or EXIT):" << std::endl;
}

std::string	Contact::getFname(void){
	return (_first_name);
}

std::string	Contact::getLname(void){
	return (_last_name);
}

std::string	Contact::getNname(void){
	return (_nickname);
}

