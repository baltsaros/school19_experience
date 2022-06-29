#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal*	meta[6];

	for (int i = 0; i < 6; i++) {
		if (i % 2 == 0)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}
	std::cout << std::endl;
	std::cout << meta[2]->getType() << std::endl;
	meta[2]->makeSound();
	std::cout << meta[3]->getType() << std::endl;
	meta[3]->makeSound();
	std::cout << std::endl;

	const Animal*	a;
	a = meta[0];
	std::cout << a->getType() << std::endl;
	a->makeSound();
	std::cout << std::endl;

	Dog*	d1 = new Dog();
	Dog*	d2 = new Dog();
	delete d1;
	d1 = d2;

	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
		delete meta[i];
	delete d2;
	return (0);
}