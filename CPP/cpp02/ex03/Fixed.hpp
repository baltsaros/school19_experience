/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:33:42 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:33:43 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define NC "\e[0m"
#define BGRN "\e[1;32m"
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define REDB "\e[1;31m"
#define REDL "\e[41m"
#define GRNL "\e[42m"
#define CYN "\e[0;36m"
#define YLW "\e[0;33m"
#define YLWB "\e[1;33m"
#define BLKB "\e[1;30m"

#include <iostream>
#include <string>
#include <cmath>

class	Fixed {
	private:
		int					_fpn;
		static const int	_nBits = 8;

	public:
		// constructors
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(Fixed const &src);

		// destructors
		~Fixed(void);

		// math and assign operations
		Fixed &	operator=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;

		// prefix de/increment
		Fixed &	operator++(void);
		Fixed &	operator--(void);

		// postfix de/increment
		Fixed	operator++(int);
		Fixed	operator--(int);

		// comparison operators
		bool	operator>(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;

		// max min
		static Fixed &	min(Fixed &f1, Fixed &f2);
		static Fixed &	max(Fixed &f1, Fixed &f2);
		static Fixed const &	min(const Fixed &f1, const Fixed &f2);
		static Fixed const &	max(const Fixed &f1, const Fixed &f2);

		// other member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	absVal(void) const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif