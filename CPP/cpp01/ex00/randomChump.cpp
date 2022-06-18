#include "Zombie.hpp"

void	randomChump(std::string name){
	Zombie	goul;

	goul.setName(name);
	goul.announce();
	return ;
}
