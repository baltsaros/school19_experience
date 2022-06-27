#include "Class.hpp"

//	CONSTRUCTORS
Class::Class(void) {
	// std::cout << BGRN "Class" NC << std::endl;
	this->= 0;
	return ;
}

Class::Class(Fixed const &src) : (src.) {
	// std::cout << GRN "Copy Class" NC << std::endl;
	return ;
}

//	DESTRUCTOR
Class::~Class(void) {
	// std::cout << BRED "UnClass" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Class&	Class::operator=(Class const &rhs) {
	
	// std::cout << "Assigning Class" << std::endl;
	// if (this != &rhs)
	// 	this->= rhs.;
	return (*this);
}