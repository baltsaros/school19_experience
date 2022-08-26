/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:49:52 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:49:53 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	one("Toto");
	FragTrap	four("Al");
	std::string	target;

	target = "Jo";
	std::cout << YLWB "\n+++++ STANDARD TESTS +++++\n";
	four.highFivesGuys();
	one.approach();
	four.highFivesGuys(one);
	four.attack(one);
	four.attack(one);
	four.beRepaired(1);

	std::cout << YLWB "\n+++++ SOME EXTRA TESTS +++++\n";
	ClapTrap	two("Jo");
	ClapTrap	three(two);
	FragTrap	five(four);
	FragTrap	six;

	two = one;
	five = six;
	std::cout << "New name of Jo is " << two.getName() << std::endl;
	std::cout << std::endl;
	return (0);
}
