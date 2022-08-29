/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:36:46 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/29 16:36:47 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	
	std::cout << std::endl;
	tmp = src->createMateria("ice");
	std::cout << tmp->getType() << std::endl;
	me->equip(tmp);
	me->showEquip();
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->showEquip();
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	return (0);
}
