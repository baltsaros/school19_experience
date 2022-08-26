/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:33:07 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:33:08 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define NC "\e[0m"
#define BGRN "\e[1;32m"
#define GRN "\e[0;32m"
#define RED "\e[0;31m"
#define BRED "\e[1;31m"
#define REDB "\e[41m"

#include <iostream>
#include <string>

class	Fixed {
	private:
		int					_fpn;
		static const int	_nBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed&	operator=(Fixed const &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif