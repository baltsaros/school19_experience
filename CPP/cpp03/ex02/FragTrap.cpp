#include "FragTrap.hpp"

//	CONSTRUCTORS
FragTrap::FragTrap(void) : 
	_hp(100), _ep(50), _ad(30) {
	this->_name = "default";
	std::cout << BLUEB "FragTrap " NC << _name;
	std::cout << BLUEB " jumps out of a barrel" NC << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : 
	ClapTrap(name), _name(name), _hp(100), _ep(50), _ad(20) {
	std::cout << BLUEB "FragTrap " NC << name;
	std::cout << BLUEB " said nothing" NC << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &src) : 
	_name(src._name), _hp(src._hp), _ep(src._ep), _ad(src._ad) {
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

void	FragTrap::attack(const std::string& target) {
	if (this->_hp <= 0) {
		std::cout << BLUE "FragTrap " NC << this->_name;
		std::cout << " cannot attack, since it is dead!" << std::endl;
		return ;
	}
	std::cout << BLUE "FragTrap " NC << this->_name << " leaps forward and strikes hard ";
	std::cout << target << " causing " << this->_ad;
	std::cout << " point(s) of damage!" << std::endl;
	this->_ep--;
	return ;
}

void	FragTrap::attack(ClapTrap& target) {
	std::cout << BLUE "FragTrap " NC << this->_name << " leaps forward and strikes hard ";
	std::cout << target.getName() << " causing " << this->_ad;
	std::cout << " point(s) of damage!" << std::endl;
	target.takeDamage(this->_ad);
	this->_ep--;
	return ;
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