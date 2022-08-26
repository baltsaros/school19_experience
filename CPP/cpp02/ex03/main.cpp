/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:33:47 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:33:48 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <unistd.h>

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point const	A(0, 0);
	Point const	B(10, 30);
	Point const	C(20, 0);
	Point const	P(2, 7.43);
	Point const	D(10.3, 14.9);
	bool		result;

	std::cout << YLWB "Let's see whether the dot is inside the triangle or not!" NC << std::endl;
	std::cout << std::endl;

	std::cout << "Corner points of a triangle:" << std::endl;
	std::cout << "A(" << A.getX() << ", " << A.getY() << ")" << std::endl;
	std::cout << "B(" << B.getX() << ", " << B.getY() << ")" << std::endl;
	std::cout << "C(" << C.getX() << ", " << C.getY() << ")" << std::endl;
	std::cout << std::endl;
	
	std::cout << "Point:" << std::endl;
	std::cout << CYN "P(" NC << P.getX() << CYN ", " NC << P.getY() << CYN ")" NC<< std::endl;
	result = bsp(A, B, C, P);
	std::cout << YLW "Result is " NC << result<< std::endl;
	std::cout << std::endl;
	std::cout << "Point:" << std::endl;
	std::cout << CYN "D(" NC << D.getX() << CYN ", " NC << D.getY() << CYN ")" NC<< std::endl;
	result = bsp(A, B, C, D);
	std::cout << YLW "Result is " NC << result<< std::endl;
	
	usleep(2000000);
	std::cout << std::endl;
	std::cout << GRNL BLKB "Do you want to try your values?" NC << std::endl;
	while (19) {
		float	x, y;
		int		exit;
		std::cout << "Enter a value for X:" << std::endl;
		std::cin >> x;
		if (std::cin.fail())
			break ; 
		std::cout << "Enter a value for Y:" << std::endl;
		std::cin >> y;
		if (std::cin.fail())
			break ; 
		Point	U(x, y);
		std::cout << "Point:" << std::endl;
		std::cout << CYN "U(" NC << U.getX() << CYN ", " NC << U.getY() << CYN ")" NC<< std::endl;
		result = bsp(A, B, C, U);
		std::cout << YLW "Result is " NC << result<< std::endl;
		std::cout << std::endl;
		std::cout << RED "You can " NC << REDB "exit" NC << RED " the loop by typing any " NC;
		std::cout << REDB "non-numeric value." NC << std::endl;
		std::cout << RED "Type any other " NC << REDB "number to continue." NC << std::endl;
		std::cin >> exit;
		if (std::cin.fail() || exit == 777)
			break ;
	}
	return (0);
}
