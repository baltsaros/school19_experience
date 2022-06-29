#include "include/MateriaSource.hpp"

//	CONSTRUCTORS
MateriaSource::MateriaSource(void) : IMateriaSource() {
	std::cout << PRPLB "MateriaSource materialized" NC << std::endl;
	for (int i = 0; i < 4; i++)
		this->_stored[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &src) : IMateriaSource() {
	std::cout << PRPL "Copy MateriaSource" NC << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
MateriaSource::~MateriaSource(void) {
	std::cout << REDB "UnMateriaSource" NC << std::endl;
	return ;
}

//	ASSIGN OPERATOR
MateriaSource&	MateriaSource::operator=(MateriaSource const &rhs) {
	std::cout << PRPL "Assigning MateriaSource" NC << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < 4; i++) {
			if (this->_stored[i] != NULL)
				delete this->_stored[i];
		}
		for (int i = 0; i < 4; i++)
			this->_stored[i] = this->_stored[i]->clone();
	}
	return (*this);
}

//	OTHERS
void	MateriaSource::learnMateria(AMateria* par) {
	for (int i = 0; i < 4; i++) {
		if (this->_stored[i] == NULL) {
			this->_stored[i] = par->clone();
			return ;
		}
	}
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	if (type != "ice" && type != "cure")
		return (0);
	for (int i = 0; i < 4; i++) {
		if (this->_stored[i]->getType() == type)
			return (this->_stored[i]->clone());
	}
	return (0);
}
