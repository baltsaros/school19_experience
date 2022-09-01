/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:22:26 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 11:51:01 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP

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
# include <iomanip>
# include <string>
# include <exception>
# include <stdio.h>
# include <cmath>

class	Convertor {
	private:
		std::string	_input;
		char		_c;
		int			_i;
		float		_f;
		double		_d;

	public:
		Convertor(void);
		Convertor(std::string input);
		Convertor(Convertor const &src);
		~Convertor(void);

		Convertor&	operator=(Convertor const &rhs);
		void		detectType(void);
		void		makeConversion(void);
		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;

		class InvalidInput: public std::exception {
		const char*	what(void) const throw();
		};

		class NonDisplayable: public std::exception {
		const char*	what(void) const throw();
		};

		class Impossible: public std::exception {
		const char*	what(void) const throw();
		};
};
std::ostream&	operator<<(std::ostream& o, Convertor const & in);

#endif
