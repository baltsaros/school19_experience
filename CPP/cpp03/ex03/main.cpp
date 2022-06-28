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
