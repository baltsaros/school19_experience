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
