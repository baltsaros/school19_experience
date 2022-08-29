/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:35:53 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:35:54 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

//	CONSTRUCTORS
WrongAnimal::WrongAnimal(void) : _type("Unknown beast") {
	std::cout << GRNB "WrongAnimal is here..." NC << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << GRNB "WrongAnimal " NC << this->_type << GRNB " is here!" NC << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	std::cout << GRNB "Copy WrongAnimal" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
WrongAnimal::~WrongAnimal(void) {
	std::cout << GRNB "WrongAnimal " NC << this->_type << REDB " is hiding..." NC;
	std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &rhs) {
	std::cout << GRN "Assigning WrongAnimal" NC << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << GRN "WrongAnimal" NC << " makes some wrong noises." << std::endl;
	return ;
}

std::string	WrongAnimal::getType(void) const{
	return (this->_type);
}
