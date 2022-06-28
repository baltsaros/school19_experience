#include "Cat.hpp"

//	CONSTRUCTORS
Cat::Cat(void) : Animal("Cat") {
	std::cout << PRPLB "Cat jumps out of a box!" NC << std::endl;
	this->_type = "Cat";
	this->_brains = new Brain();
	return ;
}

Cat::Cat(Cat const &src) {
	std::cout << PRPLB "Copy Cat" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Cat::~Cat(void) {
	std::cout << PRPLB "Cat" NC << REDB " returned to its box..." NC;
	std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Cat&	Cat::operator=(Cat const &rhs) {
	std::cout << PRPL "Assigning Cat" NC << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << PRPL "Cat" NC << " meows: communism is utopia, bro...";
	std::cout << std::endl;
	return ;
}
