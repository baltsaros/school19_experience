/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:04:02 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 11:04:03 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

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

# include <exception>
# include <algorithm>
# include <array>
# include <vector>
# include <list>
# include <iostream>

template <typename T>
class	Span {
	private:
		Span<T>(void);
		std::vector<T>	_cntr;
		unsigned int	_N;

	public:
		Span<T>(unsigned int N);
		Span<T>(Span<T> const &src);
		virtual ~Span<T>(void);

		Span<T>&		operator=(Span<T> const &rhs);
		T&				operator[](long const i);
		void			addNumber(T num);
		void			addNumber(typename std::vector<T>::iterator f,
									typename std::vector<T>::iterator l);
		T				shortestSpan(void);
		T				longestSpan(void);
		unsigned int	getSize(void);
		unsigned int	getCapacity(void);

		class noSpaceLeft: public std::exception {
			const char*	what(void) const throw();
		};

		class emptyCntr: public std::exception {
			const char*	what(void) const throw();
		};

		class noSpan: public std::exception {
			const char*	what(void) const throw();
		};

		class outOfRange: public std::exception {
			const char*	what(void) const throw();
		};
};
template <typename T>
std::ostream &	operator<<(std::ostream & o, Span<T> & sp);

#endif
