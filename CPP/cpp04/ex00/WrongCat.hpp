#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class	WrongCat: public	WrongAnimal {
	private:
		std::string	_type;

	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		virtual ~WrongCat(void);

		WrongCat&	operator=(WrongCat const &rhs);
		// void		makeSound(void) const;
};

#endif