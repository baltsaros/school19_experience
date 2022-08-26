/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:33:50 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 15:33:51 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class	Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point(void);
		Point(const float f1, const float f2);
		Point(Point const &src);
		~Point(void);
		Point&	operator=(Point const &rhs);

		Fixed const	getX(void) const;
		Fixed const	getY(void) const;
};

#endif