#include "Dog.hpp"

//	CONSTRUCTORS
Dog::Dog(void) : Animal("Dog") {
	std::cout << YLWB "Dog is sniffing around." NC << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(Dog const &src) {
	std::cout << YLWB "Copy Dog" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Dog::~Dog(void) {
	std::cout << YLWB "Dog" NC << REDB" ran away" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Dog&	Dog::operator=(Dog const &rhs) {
	
	std::cout << YLW "Assigning Dog" NC<< std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << YLW "Dog" NC << " barks." << std::endl;
	return ;
}