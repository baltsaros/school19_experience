#include "Fixed.hpp"

//	CONSTRUCTORS
Fixed::Fixed(void) {
	// std::cout << BGRN "Fixed" NC << std::endl;
	this->_fpn = 0;
	return ;
}

Fixed::Fixed(const int i) {
	// std::cout << BGRN "Fixed" NC << std::endl;
	this->_fpn = i << this->_nBits;
	return ;
}

Fixed::Fixed(const float f) {
	// std::cout << BGRN "Fixed" NC << std::endl;
	this->_fpn = (int)(std::roundf(f * (1 << this->_nBits)));
	return ;
}

Fixed::Fixed(Fixed const &src) : _fpn(src._fpn) {
	// std::cout << GRN "Copy Fixed" NC << std::endl;
	return ;
}

//	DESTRUCTOR
Fixed::~Fixed(void) {
	// std::cout << BRED "UnFixed" NC << std::endl;
	return ;
}

//	MATH AND ASSIGN OPERATIONS
Fixed&	Fixed::operator=(Fixed const &rhs) {
	// std::cout << "Assigning Fixed" << std::endl;
	if (this != &rhs)
		this->_fpn = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &rhs) const {
	Fixed	tmp;

	tmp.setRawBits((this->_fpn + rhs._fpn));
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed &rhs) const {
	Fixed	tmp;

	tmp.setRawBits((this->_fpn - rhs._fpn));
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed &rhs) const {
	Fixed	tmp;

	tmp.setRawBits(((int64_t)this->_fpn * rhs._fpn) >> this->_nBits);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed &rhs) const {
	Fixed	tmp;

	tmp.setRawBits(((int64_t)this->_fpn << this->_nBits) / rhs._fpn);
	return (tmp);
}

//	PREFIX DE/INCREMENT
Fixed &	Fixed::operator++(void) {
	// this->setRawBits(this->_fpn + (1 << this->_nBits));
	this->_fpn++;
	return (*this);
}

Fixed &	Fixed::operator--(void) {
	// this->_fpn = this->_fpn - (1 << this->_nBits);
	this->_fpn--;
	return (*this);
}

//	POSTFIX DE/INCREMENT
Fixed	Fixed::operator++(int) {
	Fixed	tmp;

	tmp = *this;
	// this->_fpn = this->_fpn + (1 << this->_nBits);
	this->_fpn++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp;

	tmp = *this;
	this->_fpn--;
	// this->_fpn = this->_fpn - (1 << this->_nBits);
	return (tmp);
}


//	COMPARISON OPERATORS
bool	Fixed::operator>(const Fixed &rhs) const {
	if (this > &rhs)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &rhs) const {
	if (this < &rhs)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &rhs) const {
	if (this >= &rhs)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &rhs) const {
	if (this <= &rhs)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &rhs) const {
	if (this == &rhs)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &rhs) const {
	if (this != &rhs)
		return (true);
	return (false);
}

//	MAX MIN
Fixed &	Fixed::min(Fixed &f1, Fixed &f2) {
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &	Fixed::max(Fixed &f1, Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed const &	Fixed::min(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed const &	Fixed::max(const Fixed &f1, const Fixed &f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

//	OTHER FUNCTIONS
int		Fixed::getRawBits(void) const {
	return (this->_fpn);
}

void	Fixed::setRawBits(int const raw) {
	// std::cout << "Setting raw bits" << std::endl;
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

//	PRINT FPN
std::ostream &	operator<<(std::ostream & o, Fixed const & i) {
	o << i.toFloat();
	return (o);
}
