#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define NC "\e[0m"
# define GRNB "\e[1;32m"
# define GRN "\e[0;32m"
# define RED "\e[0;31m"
# define REDB "\e[1;31m"
# define REDL "\e[41m"
# define CYN "\e[0;36m"
# define CYNB "\e[1;36m"
# define YLW "\e[0;33m"
# define YLWB "\e[1;33m"
# define PRPL "\e[0;35m"
# define PRPLB "\e[1;35m"
# define WHT "\e[0;37m"
# define WHTB "\e[1;37m"
# define WHTL "\e[37m"
# define BLUE "\e[0;34m"
# define BLUEB "\e[1;34m"
# define BLUEL "\e[34m"

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat&			operator=(Bureaucrat const &rhs);
		std::string			getName(void) const;
		int					getGrade(void) const;
		void				increment(void);
		void				decrement(void);
		void				signForm(Form &f);

		class GradeTooHighException: public std::exception {
				const char*	what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
				const char*	what(void) const throw();
		};
};
std::ostream&	operator<<(std::ostream& o, Bureaucrat const & bob);


#endif
