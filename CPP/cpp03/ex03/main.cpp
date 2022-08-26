/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:50:58 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:50:59 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {
	ClapTrap	one("Toto");
	DiamondTrap	four("D");
	std::string	target;

	target = "Jo";
	std::cout << YLWB "\n+++++ STANDARD TESTS +++++\n";
	four.guardGate();
	four.highFivesGuys();
	one.approach();
	four.highFivesGuys(one);
	four.attack(one);
	four.attack(one);
	four.beRepaired(1);
	four.whoAmI();

	std::cout << YLWB "\n+++++ SOME EXTRA TESTS +++++\n";
	DiamondTrap	five(four);
	DiamondTrap	six;

	five = six;
	std::cout << std::endl;
	return (0);
}
