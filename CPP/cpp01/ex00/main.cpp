#include "Zombie.hpp"

int	main(void){
	Zombie	*ben;

	ben = newZombie("Ben");
	ben->announce();
	randomChump("Al");
	delete ben;
	return (0);
}
