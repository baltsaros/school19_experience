#include "Zombie.hpp"

// Zombie::Zombie(std::string name){
// 	this->_name = name;
// 	return ;
// }

void	Zombie::setName(std::string name){
	this->_name = name;
	return ;
}

Zombie::~Zombie(void){
	std::cout << this->_name << ": is no more\n";
	return ;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}
