/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:19:36 by abuzdin           #+#    #+#             */
/*   Updated: 2022/09/01 10:19:37 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

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
# include <iostream>

template <typename T, typename U>
class	Array {
	private:
		unsigned int	_size;
		T				*_array;

	public:
		Array<T, U>(void);
		Array<T, U>(unsigned int n);
		Array<T, U>(Array<T, U> const &src);
		~Array<T, U>(void);

		Array<T, U>&	operator=(Array<T, U> const &rhs);
		T&				operator[](U const i);
		unsigned int	size(void) const;

		class outOfRange: public std::exception {
			const char*	what(void) const throw();
		};
};
template <typename T, typename U>
std::ostream &	operator<<(std::ostream & o, Array<T, U> & ar);

#endif
