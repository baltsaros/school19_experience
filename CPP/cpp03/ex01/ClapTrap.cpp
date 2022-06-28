#include "ClapTrap.hpp"

//	CONSTRUCTORS
ClapTrap::ClapTrap(void) : _hp(10), _ep(10), _ad(0) {
	this->_name = "default";
	std::cout << GRNB "ClapTrap " NC << this->_name;
	std::cout << GRNB " said hello" NC << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0) {
	std::cout << GRNB "ClapTrap " NC << name;
	std::cout << GRNB " said hello" NC << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
	*this = src;
	std::cout << GRNB "Copying ClapTrap " NC << src._name << std::endl;
	return ;
}

//	DESTRUCTOR
ClapTrap::~ClapTrap(void) {
	std::cout << GRNB "ClapTrap " NC << this->_name;
	std::cout << REDB " said bye!" NC << std::endl;
	std::cout << "It had " << this->_hp << " hp ";
	std::cout << "and " << this->_ep << " energy left" << std::endl;
	return ;
}

//	ASSIGN OPERATOR
ClapTrap&	ClapTrap::operator=(ClapTrap const &rhs) {
	std::cout << "Assigning" << GRN " ClapTrap " NC << rhs._name;
	std::cout << " to " << GRN "ClapTrap " NC << this->_name;
	std::cout << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hp <= 0) {
		std::cout << GRN "ClapTrap " NC << this->_name;
		std::cout << " cannot attack, since it is dead!" << std::endl;
		return ;
	}
	std::cout << GRN "ClapTrap " NC << this->_name << " attacks ";
	std::cout << target << " causing " << this->_ad;
	std::cout << " point(s) of damage!" << std::endl;
	this->_ep--;
	return ;
}

void	ClapTrap::attack(ClapTrap& target) {
	std::cout << GRN "ClapTrap " NC << this->_name << " attacks ";
	std::cout << target.getName() << " causing " << this->_ad;
	std::cout << " point(s) of damage!" << std::endl;
	target.takeDamage(this->_ad);
	this->_ep--;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp <= 0) {
		std::cout << "Stop it!" << GRN " ClapTrap " NC;
		std::cout << this->_name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << GRN "ClapTrap " NC << this->_name << " got hit! ";
	std::cout << "It lost " << amount << " hit point(s)!" << std::endl;
	this->_hp -= amount;
	if (this->_hp <= 0){
		std::cout << GRN "ClapTrap " NC << this->_name << " collapsed...";
		std::cout << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hp <= 0) {
		std::cout << "What is dead healed cannot be!" << std::endl;
		return ;
	}
	if (this->_ep <= 0) {
		std::cout << GRN "ClapTrap " NC << this->_name;
		std::cout << " has no more energy!" << std::endl;
		return ;
	}
	std::cout << GRN "ClapTrap " NC << this->_name << " is repairing itself! ";
	std::cout << "It got " << amount << " hit point(s) back!" << std::endl;
	this->_ep--;
	this->_hp += amount;
	return ;
}

std::string	ClapTrap::getName(void) {
	return (this->_name);
}

void	ClapTrap::useEnergy(unsigned int amount) {
	this->_ep -= amount;
}

void	ClapTrap::approach(void) {
	if (this->_hp <= 0)
		return ;
	std::cout << GRN "ClapTrap " NC << this->_name << " tries to pass the gates...";
	std::cout << std::endl;
	return ;
}
