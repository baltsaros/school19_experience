#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class	Dog : public Animal {
	private:
		std::string	_type;
	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		Dog&		operator=(Dog const &rhs);
		void		makeSound(void) const;
};

#endif