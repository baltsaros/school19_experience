#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class	Ice : public AMateria {
	private:
		std::string	_type;

	public:
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);

		Ice&		operator=(Ice const &rhs);
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
