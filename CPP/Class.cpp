#include "Class.hpp"

//	CONSTRUCTORS
Class::Class(void) {
	// std::cout << GRNB "Class" NC << std::endl;
	this->= 0;
	return ;
}

Class::Class(Class const &src) {
	// std::cout << GRNB "Copy Class" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Class::~Class(void) {
	// std::cout << REDB "UnClass" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Class&	Class::operator=(Class const &rhs) {
	// std::cout << GRN "Assigning Class" NC << std::endl;
	// if (this != &rhs)
	// 	this->= rhs.;
	return (*this);
}

//	OTHERS
