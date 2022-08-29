/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:35:05 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:35:06 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

//	CONSTRUCTORS
Cat::Cat(void) : Animal("Cat") {
	std::cout << PRPLB "Cat jumps out of a box!" NC << std::endl;
	this->_type = "Cat";
	this->_brains = new Brain();
	return ;
}

Cat::Cat(Cat const &src) {
	std::cout << PRPLB "Copy Cat" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Cat::~Cat(void) {
	std::cout << PRPLB "Cat" NC << REDB " returned to its box..." NC;
	std::cout << std::endl;
	delete this->_brains;
	return ;
}

//	ASSIGN OPERATOR
Cat&	Cat::operator=(Cat const &rhs) {
	std::cout << PRPL "Assigning Cat" NC << std::endl;
	if (this != &rhs) {
		delete this->_brains;
		this->_brains = new Brain();
		*this->_brains = *(rhs._brains);
		this->_type = rhs._type;
	}
	return (*this);
}

//	OTHERS
void	Cat::makeSound(void) const {
	std::cout << PRPL "Cat" NC << " meows: communism is utopia, bro...";
	std::cout << std::endl;
	return ;
}

void	Cat::getIdea(int i) {
	this->_brains->getIdea(i);
	return ;
}
