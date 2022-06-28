#include "Brain.hpp"

//	CONSTRUCTORS
Brain::Brain(void) {
	std::cout << WHTB "Brain!" NC << std::endl;
	for (int i = 0; i < 100; i++) {
		
	}
	return ;
}

Brain::Brain(Brain const &src) {
	std::cout << WHTB "Copy Brain" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Brain::~Brain(void) {
	std::cout << WHTB "Brain" NC << REDB " dried out..." NC;
	std::cout << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Brain&	Brain::operator=(Brain const &rhs) {
	std::cout << PRPL "Assigning Brain" NC << std::endl;
	// if (this != &rhs)
	return (*this);
}
