/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 10:53:24 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/30 10:53:25 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		bool				execute(Bureaucrat const &executor) const;
		virtual void		formAction(void) const = 0;

		class GradeTooHighToSign: public std::exception {
				const char*	what(void) const throw();
		};

		class GradeTooLowToSign: public std::exception {
				const char*	what(void) const throw();
		};

		class GradeTooHighToExec: public std::exception {
				const char*	what(void) const throw();
		};

		class GradeTooLowToExec: public std::exception {
				const char*	what(void) const throw();
		};

		class FormNotSigned: public std::exception {
				const char*	what(void) const throw();
		};
};
std::ostream&	operator<<(std::ostream& o, AForm const & bob);

#endif
