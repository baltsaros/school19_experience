#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	private:
		const std::string		_target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);

		std::string				getTarget(void) const;
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const &rhs);
};

#endif
