#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name){
	Zombie	*gouls;

	gouls = new Zombie[N];
	for (int i = 0; i < N; i++){
		gouls[i].setName(name);
	}
	return (gouls);
}
