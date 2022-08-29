/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:44 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:36:45 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/MateriaSource.hpp"

//	CONSTRUCTORS
MateriaSource::MateriaSource(void) : IMateriaSource() {
	std::cout << PRPLB "MateriaSource materialized" NC << std::endl;
	for (int i = 0; i < 4; i++)
		this->_stored[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src) : IMateriaSource() {
	std::cout << PRPL "Copy MateriaSource" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
MateriaSource::~MateriaSource(void) {
	std::cout << PRPLB "MateriaSource" NC << REDB " was exhausted" NC << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_stored[i])
			delete this->_stored[i];
	}
	return ;
}

//	ASSIGN OPERATOR
MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << PRPL "Assigning MateriaSource" NC << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->_stored[i])
				delete this->_stored[i];
		}
		for (int i = 0; i < 4; i++)
			this->_stored[i] = this->_stored[i]->clone();
	}
	return (*this);
}

//	OTHERS
void	MateriaSource::learnMateria(AMateria* par) {
	for (int i = 0; i < 4; i++) {
		if (this->_stored[i] == NULL) {
			this->_stored[i] = par;
			return ;
		}
	}
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	if (type != "ice" && type != "cure")
		return (0);
	for (int i = 0; i < 4; i++) {
		if (this->_stored[i]->getType() == type)
			return (this->_stored[i]->clone());
	}
	return (0);
}
