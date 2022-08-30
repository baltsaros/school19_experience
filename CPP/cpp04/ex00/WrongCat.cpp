/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:34:45 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:46:17 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

//	CONSTRUCTORS
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << PRPLB "WrongCat is sniffing around!" NC << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const &src) {
	std::cout << PRPLB "Copy WrongCat" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
WrongCat::~WrongCat(void) {
	std::cout << PRPLB "WrongCat" NC << REDB " ran away..." NC;
	std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
WrongCat&	WrongCat::operator=(WrongCat const &rhs) {
	std::cout << PRPL "Assigning WrongCat" NC << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << PRPL "WrongCat" NC << " barks...";
	std::cout << std::endl;
	return ;
}
