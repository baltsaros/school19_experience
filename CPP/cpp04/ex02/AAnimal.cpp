/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:15 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:36:16 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

//	CONSTRUCTORS
AAnimal::AAnimal(void) : _type("Unknown beast") {
	std::cout << GRNB "AAnimal is here!" NC << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << GRNB "AAnimal " NC << this->_type << GRNB " is here!" NC << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &src) {
	std::cout << GRNB "Copy AAnimal" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
AAnimal::~AAnimal(void) {
	std::cout << GRNB "AAnimal " NC << this->_type << REDB " is hiding..." NC;
	std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
AAnimal&	AAnimal::operator=(AAnimal const &rhs) {
	std::cout << GRN "Assigning AAnimal" NC << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

//	OTHERS
// void	AAnimal::makeSound(void) const {
// 	std::cout << GRN "AAnimal" NC << " makes some weird noises." << std::endl;
// 	return ;
// }

std::string	AAnimal::getType(void) const{
	return (this->_type);
}
