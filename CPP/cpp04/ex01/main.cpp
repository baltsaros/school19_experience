#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
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

	const WrongAnimal*	wa = new WrongAnimal();
	const WrongCat*		wc = new WrongCat();
	std::cout << wa->getType() << " " << std::endl;
	std::cout << wc->getType() << " " << std::endl;
	wa->makeSound();
	wc->makeSound();


	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	delete d;
	delete c;
	delete wa;
	delete wc;
	return (0);
}