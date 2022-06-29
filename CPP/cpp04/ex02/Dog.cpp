#include "Dog.hpp"

//	CONSTRUCTORS
Dog::Dog(void) : AAnimal("Dog") {
	std::cout << YLWB "Dog is sniffing around." NC << std::endl;
	this->_type = "Dog";
	this->_brains = new Brain();
	return ;
}

Dog::Dog(Dog const &src) {
	std::cout << YLWB "Copy Dog" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Dog::~Dog(void) {
	std::cout << YLWB "Dog" NC << REDB" ran away." NC << std::endl;
	delete this->_brains;
	return ;
}

//	ASSIGN OPERATOR
Dog&	Dog::operator=(Dog const &rhs) {
	std::cout << YLW "Assigning Dog" NC<< std::endl;
	if (this != &rhs){
		delete this->_brains;
		this->_brains = new Brain();
		*this->_brains = *(rhs._brains);
		this->_type = rhs._type;
	}
	return (*this);
}

//	OTHERS
void	Dog::makeSound(void) const {
	std::cout << YLW "Dog" NC << " barks." << std::endl;
	return ;
}

void	Dog::getIdea(int i) {
	this->_brains->getIdea(i);
	return ;
}
