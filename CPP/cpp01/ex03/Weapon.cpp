#include "Weapon.hpp"

Weapon::Weapon(std::string weapon){
	this->_type = weapon;
	return ;
}

std::string const	&Weapon::getType(void) const{
	return (this->_type);
}

void			Weapon::setType(std::string weapon){
	this->_type = weapon;
	return ;
}