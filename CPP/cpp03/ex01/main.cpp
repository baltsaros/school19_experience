#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	one("Toto");
	// ClapTrap	two("Jo");
	// ClapTrap	three("Ba");
	ScavTrap	four("Gi");
	std::string	target;

	target = "Jo";
	std::cout << YLWB "\n+++++ STANDARD TESTS +++++\n";
	four.guardGate();
	one.approach();
	four.attack(one);
	four.attack(one);
	four.beRepaired(1);
	return (0);
}
