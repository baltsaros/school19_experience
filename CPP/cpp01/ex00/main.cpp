#include "Zombie.hpp"

int	main(void){
	std::cout << "standard call:\n";
	Zombie	z1("Al");
	z1.announce();

	std::cout << std::endl;
	std::cout << "newZombie func:\n";
	Zombie	*z2;
	z2 = newZombie("Bo");
	z2->announce();

	std::cout << std::endl;
	std::cout << "randomChump func:\n";
	randomChump("Ci");

	delete z2;
	return (0);
}
