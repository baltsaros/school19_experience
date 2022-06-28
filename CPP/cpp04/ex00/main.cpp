#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
	const Animal* 	meta = new Animal();
	const Animal* 	j = new Dog();
	const Animal* 	i = new Cat();
	Animal*			a;
	Dog*			d = new Dog();
	Cat*			c = new Cat();
	Animal			stat;

	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << CYN "\n+++ EXTRA TESTS +++\n" NC;
	d->makeSound();
	a = c;
	a->makeSound();
	a = d;
	a->makeSound();
	stat.makeSound();
	stat = *c;
	stat.makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete d;
	delete c;
	return (0);
}