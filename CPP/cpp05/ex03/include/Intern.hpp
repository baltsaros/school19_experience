#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern {
	typedef struct s_forms {
		std::string	name;
		AForm*		(Intern::*fun)(std::string target);
	}	t_forms;

	private:
		t_forms		*_forms;
		AForm*		_pardon(std::string target);
		AForm*		_robotomy(std::string target);
		AForm*		_shrubbery(std::string target);

	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern&		operator=(Intern const &rhs);
		AForm*		makeForm(std::string form, std::string target);

		class NotValidTarget: public std::exception {
				const char*	what(void) const throw();
		};

		class NotValidForm: public std::exception {
				const char*	what(void) const throw();
		};
};

std::string	strToLower(std::string const form);

#endif