#include "include/Cure.hpp"

//	CONSTRUCTORS
Cure::Cure(void) : AMateria("cure") {
	std::cout << GRNB "Nature awakened!" NC << std::endl;
	this->_type = "cure";
	return ;
}

Cure::Cure(Cure const &src) {
	std::cout << GRN "Copy Cure" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Cure::~Cure(void) {
	std::cout << GRNB "Nature" NC;
	std::cout << REDB " fainted." NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Cure&	Cure::operator=(Cure const &rhs) {
	std::cout << GRN "Assigning Cure" NC << std::endl;
	if (this != &rhs)
		this->_type= rhs._type;
	return (*this);
}

// OTHERS

AMateria*	Cure::clone(void) const {
	AMateria*	tmp = new Cure();
	return (tmp);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName();
	std::cout << "'s wounds *" << std::endl;
	return ;
}
