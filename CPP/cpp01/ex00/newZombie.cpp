#include "Zombie.hpp"

Zombie*	newZombie(std::string name){
	Zombie *goul;

	goul = new Zombie(name);
	return (goul);
}
