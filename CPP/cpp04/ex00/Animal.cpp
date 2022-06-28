#include "Animal.hpp"

//	CONSTRUCTORS
Animal::Animal(void) : _type("Unknown beast") {
	std::cout << GRNB "Animal is here!" NC << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << GRNB "Animal " NC << this->_type << GRNB " is here!" NC << std::endl;
	return ;
}

Animal::Animal(Animal const &src) {
	std::cout << GRNB "Copy Animal" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Animal::~Animal(void) {
	std::cout << GRNB "Animal " NC << this->_type << REDB " is hiding..." NC;
	std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Animal&	Animal::operator=(Animal const &rhs) {
	std::cout << GRN "Assigning Animal" NC << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound(void) const {
	std::cout << GRN "Animal" NC << " makes some weird noises." << std::endl;
	return ;
}

std::string	Animal::getType(void) const{
	return (this->_type);
}