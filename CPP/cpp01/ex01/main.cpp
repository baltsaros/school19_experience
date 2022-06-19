#include "Zombie.hpp"

int	main(void){
	std::cout << std::endl;
	std::cout << "zombieHorde func:\n";
	Zombie	*z2;
	z2 = zombieHorde(5, "Steve");
	for (int i= 0; i < 5; i++){
		std::cout << "[" << i << "]";
		z2[i].announce();
	}
	delete [] z2;
	return (0);
}
