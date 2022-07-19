#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	private:
		const std::string		_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm(void);

		PresidentialPardonForm&	operator=(PresidentialPardonForm const &rhs);
		std::string				getTarget(void) const;
		void					formAction(void) const;
};

#endif