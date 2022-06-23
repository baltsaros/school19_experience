#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << BGRN "Fixed" NC << std::endl;
	this->_fpn = 0;
	return ;
}

Fixed::Fixed(const int i) {
	std::cout << BGRN "Fixed" NC << std::endl;
	this->_fpn = i << this->_nBits;
	return ;
}

Fixed::Fixed(const float f) {
	std::cout << BGRN "Fixed" NC << std::endl;
	this->_fpn = (int)(std::roundf(f * (1 << this->_nBits)));
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
		this->_fpn = rhs.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i) {
	o << i.toFloat();
	return (o);
}

int		Fixed::getRawBits(void) const {
	return (this->_fpn);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "Setting raw bits" << std::endl;
	this->_fpn = raw;
	return ;
}

float	Fixed::toFloat(void) const {
	float	tmp;
	tmp = ((float)(this->_fpn) / (1 << this->_nBits));
	return (tmp);
}

int		Fixed::toInt(void) const {
	int	tmp;
	tmp = this->_fpn >> this->_nBits;
	return (tmp);
}
