#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class	Cure : public AMateria {
	private:
		std::string	_type;

	public:
		Cure(void);
		Cure(Cure const &src);
		~Cure(void);

		Cure&		operator=(Cure const &rhs);
		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
