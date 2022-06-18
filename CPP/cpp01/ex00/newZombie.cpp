#include "Zombie.hpp"

Zombie*	newZombie(std::string name){
	Zombie *goul;

	goul = new Zombie;
	goul->setName(name);
	return (goul);
}
