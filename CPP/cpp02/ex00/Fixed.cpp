/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:33:04 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:33:05 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << BGRN "Fixed" NC << std::endl;
	this->_fpn = 0;
	return ;
}

Fixed::Fixed(Fixed const &src) : _fpn(src._fpn) {
	std::cout << GRN "Copy Fixed" NC << std::endl;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << BRED "UnFixed" NC << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assigning Fixed" << std::endl;
	if (this != &rhs)
		this->_fpn = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	std::cout << "Getting raw bits" << std::endl;
	return (this->_fpn);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "Setting raw bits" << std::endl;
	this->_fpn = raw;
	return ;
}
