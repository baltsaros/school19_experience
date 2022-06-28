#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public	Animal {
	private:
		std::string	_type;
		Brain*		_brains;

	public:
		Cat(void);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat&		operator=(Cat const &rhs);
		void		makeSound(void) const;
};

#endif