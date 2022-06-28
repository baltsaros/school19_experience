#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);

		DiamondTrap&	operator=(DiamondTrap const &rhs);
		void		whoAmI(void);

		using ScavTrap::_ep;
		using ScavTrap::attack;
		using FragTrap::_hp;
		using FragTrap::_ad;
};

#endif

// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (Scavtrap)