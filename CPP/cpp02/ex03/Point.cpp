/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:33:53 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:33:54 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//	CONSTRUCTORS
Point::Point(void) : _x(Fixed(0)), _y(Fixed(0)) {
	// std::cout << BGRN "I got a point!" NC << std::endl;
	return ;
}

Point::Point(const float f1, const float f2) : _x(Fixed(f1)), _y(Fixed(f2)) {
	// std::cout << BGRN "I got a point!" NC << std::endl;
	return ;
}

Point::Point(Point const &src) : _x(src._x), _y(src._y) {
	// std::cout << GRN "Copy Point" NC << std::endl;
	// *this = src;
	return ;
}

//	DESTRUCTOR
Point::~Point(void) {
	// std::cout << BRED "I lost the point!" NC << std::endl;
	return ;
}

//	MATH AND ASSIGN OPERATIONS
Point &	Point::operator=(Point const &rhs) {
	// std::cout << "Assigning Point" << std::endl;
	// if (this != &rhs) {
	// 	this->_x = rhs.getX();
	// 	this->_y = rhs.getY();
	// }
	(void)rhs;
	return (*this);
}

//	OTHER FUNCTIONS
Fixed const	Point::getX(void) const {
	return (this->_x);
}

Fixed const	Point::getY(void) const {
	return (this->_y);
}

// void	Point::setX(int const raw) {
// 	// std::cout << "Setting raw bits" << std::endl;
// 	this->_x = raw;
// 	return ;
// }

// void	Point::setY(int const raw) {
// 	// std::cout << "Setting raw bits" << std::endl;
// 	this->_y = raw;
// 	return ;
// }