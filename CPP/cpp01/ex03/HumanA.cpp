#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon){
	// this->_name = name;
	// this->_weapon(weapon);
	std::cout << this->_name << " takes their " << this->_weapon.getType() << std::endl;
	return ;
}

HumanA::~HumanA(void){
	std::cout << this->_name << " calms down\n";
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}
