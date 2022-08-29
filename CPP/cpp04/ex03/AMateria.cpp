/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:59 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:37:00 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/AMateria.hpp"

//	CONSTRUCTORS
AMateria::AMateria(void) {
	this->_type = "unknown";
	std::cout << PRPLB "AMateria " NC << this->_type << PRPLB " materialized" NC << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) {
	this->_type = type;
	std::cout << PRPLB "AMateria " NC << this->_type << PRPLB " materialized" NC << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src) {
	std::cout << PRPL "Copy AMateria" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
AMateria::~AMateria(void) {
	std::cout << PRPLB "AMateria " NC << this->_type;;
	std::cout << REDB " was dissolved" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
AMateria&	AMateria::operator=(AMateria const &rhs) {
	std::cout << PRPL "Assigning AMateria" NC << std::endl;
	if (this != &rhs)
		this->_type= rhs._type;
	return (*this);
}

//	OTHERS
std::string const &	AMateria::getType(void) const {
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* casts some strange magic at " << target.getName();
	std::cout << " *" << std::endl;
	return ;
}
