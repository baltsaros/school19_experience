#include "DiamondTrap.hpp"

//	CONSTRUCTORS
DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), ScavTrap(), FragTrap() {
	this->_name = "default";
	std::cout << CYNB "DiamondTrap " NC << _name;
	std::cout << CYNB " shines!" NC << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
	this->_name = name;
	std::cout << CYNB "DiamondTrap " NC << name;
	std::cout << CYNB " shines!" NC << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) {
	*this = src;
	std::cout << CYNB "Copying DiamondTrap " NC << src._name << std::endl;
	return ;
}

//	DESTRUCTOR
DiamondTrap::~DiamondTrap(void) {
	std::cout << CYNB "DiamondTrap " NC << this->_name;
	std::cout << REDB " was stolen!" NC << std::endl;
	std::cout << "It had " << this->_hp << " hp ";
	std::cout << "and " << this->_ep << " energy left" << std::endl;
	return ;
}

//	ASSIGN OPERATOR
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const &rhs) {
	std::cout << "Assigning" << CYN " DiamondTrap " NC << rhs._name;
	std::cout << " to " << CYN "DiamondTrap " NC << this->_name;
	std::cout << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void) {
	std::cout << CYN "DiamondTrap" NC << " name is " << this->_name << std::endl;
	std::cout << GRN "ClapTrap" NC << " name is " << getName() << std::endl;
	return ;
}
