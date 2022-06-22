#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << BGRN "Fixed" NC << std::endl;
	this->_num = 0;
	return ;
}

Fixed::Fixed(const int i) {
	std::cout << BGRN "Fixed" NC << std::endl;
	this->_num = i / this->_nBits;
	return ;
}

Fixed::Fixed(const float f) {
	std::cout << BGRN "Fixed" NC << std::endl;
	this->_num = f / this->_nBits;
	return ;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << GRN "Copy Fixed" NC << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed(void) {
	std::cout << BRED "UnFixed" NC << std::endl;
	return ;
}

Fixed&	Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assigning Fixed" << std::endl;
	if (this != &rhs)
		this->_num = rhs.getRawBits();
	return (*this);
}

void	Fixed::operator<<(Fixed const rhs) {
	std::cout << rhs.getRawBits() << "f" << std::endl;
	return ;
}

int		Fixed::getRawBits(void) const {
	std::cout << "Getting raw bits" << std::endl;
	return (this->_num);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "Setting raw bits" << std::endl;
	this->_num = raw;
	return ;
}

float	Fixed::toFloat(void) const {

}

int		Fixed::toInt(void) const {

}
