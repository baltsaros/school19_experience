#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->_name = name;
	std::cout << this->_name << " is looking for a fight" << std::endl;
	return ;
}

HumanB::~HumanB(void){
	std::cout << this->_name << " calms down\n";
	return ;
}

void	HumanB::attack(void)
{
	if (!_weapon.getType()){
		std::cout << this->_name << " attacks with his bare hands\n";
	}
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weapon){
	this->_weapon = weapon;
	return ;
}
