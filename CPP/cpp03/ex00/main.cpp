#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	one("Toto");
	ClapTrap	two("Jo");
	ClapTrap	three("Ba");	
	std::string	target;

	target = "Jo";
	std::cout << YLWB "\n+++++ STANDARD TESTS +++++\n";
	one.attack(target);
	one.takeDamage(1);
	one.takeDamage(3);
	one.takeDamage(4);
	one.beRepaired(1);
	one.takeDamage(10);
	one.takeDamage(3);
	one.attack(target);

	std::cout << YLWB "\n+++++ EXTRA TESTS +++++\n";
	two.attack(three);
	three.attack(two);
	two.attack(three);
	three.attack(two);
	two.beRepaired(7);
	three.beRepaired(2);
	std::cout << std::endl;
	return (0);
}
