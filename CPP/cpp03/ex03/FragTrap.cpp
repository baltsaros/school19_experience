#include "FragTrap.hpp"

//	CONSTRUCTORS
FragTrap::FragTrap(void) : ClapTrap() {
	this->_name = "default";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 30;
	std::cout << BLUEB "FragTrap " NC << _name;
	std::cout << BLUEB " jumps out of a barrel" NC << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 30;
	std::cout << BLUEB "FragTrap " NC << name;
	std::cout << BLUEB " jumps out of a barrel" NC << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) {
	*this = src;
	std::cout << BLUEB "Copying FragTrap " NC << src._name << std::endl;
	return ;
}

//	DESTRUCTOR
FragTrap::~FragTrap(void) {
	std::cout << BLUEB "FragTrap " NC << this->_name;
	std::cout << REDB " returns to its barrel..." NC << std::endl;
	std::cout << "It had " << this->_hp << " hp ";
	std::cout << "and " << this->_ep << " energy left" << std::endl;
	return ;
}

//	ASSIGN OPERATOR
FragTrap&	FragTrap::operator=(FragTrap const &rhs) {
	std::cout << "Assigning" << BLUE " FragTrap " NC << rhs._name;
	std::cout << " to " << BLUE "FragTrap " NC << this->_name;
	std::cout << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << BLUE "FragTrap " NC << this->_name;
	std::cout << " is waiting for someone to give high fives!";
	std::cout << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(ClapTrap& target) {
	std::cout << BLUE "FragTrap " NC << this->_name;
	std::cout << " wants to give " << GRN "Clap Trap " NC << target.getName();
	std::cout << " high fives!" << std::endl;
	return ;
}
