#include "ScavTrap.hpp"

//	CONSTRUCTORS
ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_name = "default";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << PRPLB "ScavTrap " NC << _name;
	std::cout << PRPLB " said nothing" NC << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << PRPLB "ScavTrap " NC << name;
	std::cout << PRPLB " said nothing" NC << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
	std::cout << PRPLB "Copying ScavTrap " NC << src._name << std::endl;
	*this = src;
	return ;
}

//	DESTRUCTOR
ScavTrap::~ScavTrap(void) {
	std::cout << PRPLB "ScavTrap " NC << this->_name;
	std::cout << REDB " returns to the gates..." NC << std::endl;
	std::cout << "It had " << this->_hp << " hp ";
	std::cout << "and " << this->_ep << " energy left" << std::endl;
	return ;
}

//	ASSIGN OPERATOR
ScavTrap&	ScavTrap::operator=(ScavTrap const &rhs) {
	std::cout << "Assigning" << PRPL " ScavTrap " NC << rhs._name;
	std::cout << " to " << PRPL "ScavTrap " NC << this->_name;
	std::cout << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

void	ScavTrap::guardGate(void) {
	std::cout << PRPL "ScavTrap " NC << this->_name;
	std::cout << " guards the gates! YOU SHALL NOT PASS!!!";
	std::cout << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target) {
	if (this->_hp <= 0) {
		std::cout << PRPL "ScavTrap " NC << this->_name;
		std::cout << " cannot attack, since it is dead!" << std::endl;
		return ;
	}
	std::cout << PRPL "ScavTrap " NC << this->_name << " leaps forward and strikes hard ";
	std::cout << target << " causing " << this->_ad;
	std::cout << " point(s) of damage!" << std::endl;
	this->_ep--;
	return ;
}

void	ScavTrap::attack(ClapTrap& target) {
	std::cout << PRPL "ScavTrap " NC << this->_name << " leaps forward and strikes hard ";
	std::cout << target.getName() << " causing " << this->_ad;
	std::cout << " point(s) of damage!" << std::endl;
	target.takeDamage(this->_ad);
	this->_ep--;
	return ;
}
