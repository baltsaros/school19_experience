#include "include/AMateria.hpp"

//	CONSTRUCTORS
AMateria::AMateria(void) {
	std::cout << PRPLB "AMateria materialized" NC << std::endl;
	this->_type = "unknown";
	return ;
}

AMateria::AMateria(std::string const & type) {
	std::cout << PRPLB "AMateria materialized" NC << std::endl;
	this->_type = type;
	return ;
}

AMateria::AMateria(AMateria const &src) {
	std::cout << PRPL "Copy AMateria" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
AMateria::~AMateria(void) {
	std::cout << REDB "UnAMateria" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
AMateria&	AMateria::operator=(AMateria const &rhs) {
	std::cout << PRPL "Assigning AMateria" NC << std::endl;
	if (this != &rhs)
		this->_type= rhs._type;
	return (*this);
}

//	OTHERS
std::string const &	AMateria::getType(void) const {
	return (this->_type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* casts some strange magic at " << target.getName();
	std::cout << " *" << std::endl;
	return ;
}
