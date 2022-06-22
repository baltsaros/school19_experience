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
#include <cmath>

class	Fixed {
	private:
		int					_num;
		static const int	_nBits = 8;

	public:
		Fixed(void);
		Fixed(const int i);
		Fixed(const float f);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed&	operator=(Fixed const &rhs);
		void	operator<<(Fixed const rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

#endif