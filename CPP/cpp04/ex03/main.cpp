#include "include/AMateria.hpp"
#include "include/Character.hpp"
#include "include/Ice.hpp"
#include "include/Cure.hpp"
#include "include/MateriaSource.hpp"
// #include "include/"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	std::cout << tmp->getType() << std::endl;
	me->equip(tmp);
	me->showEquip();
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}
