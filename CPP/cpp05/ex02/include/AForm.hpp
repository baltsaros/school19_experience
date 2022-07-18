#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {
	private:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signature;

	public:
		AForm(void);
		AForm(std::string name, int sign, int exec);
		AForm(AForm const &src);
		virtual ~AForm(void);

		AForm&				operator=(AForm const &rhs);
		std::string			getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSignature(void) const;
		bool				beSigned(Bureaucrat const &b);

		class GradeTooHighException: public std::exception {
				const char*	what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
				const char*	what(void) const throw();
		};
};
std::ostream&	operator<<(std::ostream& o, AForm const & bob);

#endif
