#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <fstream>
# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	private:
		const std::string		_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);

		std::string				getTarget(void) const;
		RobotomyRequestForm&	operator=(RobotomyRequestForm const &rhs);
};

#endif