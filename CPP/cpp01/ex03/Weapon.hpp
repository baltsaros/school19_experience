#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include <new>

class	Weapon{
	private:
		std::string			_type;

	public:
		Weapon(std::string weapon);
		std::string const	&getType(void) const;
		void				setType(std::string type);
};

#endif
