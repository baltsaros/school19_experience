#include "include/Ice.hpp"

//	CONSTRUCTORS
Ice::Ice(void) : AMateria("ice") {
	std::cout << BLUEB "Ice power!" NC << std::endl;
	this->_type = "ice";
	return ;
}

Ice::Ice(Ice const &src) {
	std::cout << BLUEB "Copy Ice" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
Ice::~Ice(void) {
	std::cout << BLUEB "Ice" NC << REDB " power melted..." NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
Ice&	Ice::operator=(Ice const &rhs) {
	std::cout << BLUE "Assigning Ice" NC << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

// OTHERS

AMateria*	Ice::clone(void) const {
	AMateria*	tmp = new Ice();
	return (tmp);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " *" << std::endl;
	return ;
}
