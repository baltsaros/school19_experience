#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria*		_stored[4];

	public:
	 	MateriaSource(void);
		MateriaSource(MateriaSource const &src);
		~MateriaSource(void);

		MateriaSource&	operator=(MateriaSource const &rhs);
		void			learnMateria(AMateria* par);
		AMateria*		createMateria(std::string const & type);
};

#endif
