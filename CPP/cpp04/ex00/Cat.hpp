#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"

class	Cat: public	Animal {
	private:
		std::string	_type;

	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat&		operator=(Cat const &rhs);
		void		makeSound(void) const;
};

#endif