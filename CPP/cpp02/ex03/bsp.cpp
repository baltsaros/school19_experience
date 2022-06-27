#include "Point.hpp"
#include "Fixed.hpp"

Fixed	triangleArea(Point const p1, Point const p2, Point const p3) {
	Fixed	Result;

	Result = (p1.getX() * (p2.getY() - p3.getY())
		+ p2.getX() * (p3.getY() - p1.getY())
		+ p3.getX() * (p1.getY() - p2.getY())) / 2;
	return (Result.absVal());

}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	A;
	Fixed	A1;
	Fixed	A2;
	Fixed	A3;

	A = triangleArea(a, b, c);
	A1 = triangleArea(a, b, point);
	A2 = triangleArea(a, point, c);
	A3 = triangleArea(point, b, c);

	// std::cout << "A is " << A << std::endl;
	// std::cout << "A1 is " << A1 << std::endl;
	// std::cout << "A2 is " << A2 << std::endl;
	// std::cout << "A3 is " << A3 << std::endl;
	// std::cout << "Sum is " << A1 + A2 + A3 << std::endl;
	if (A1 + A2 + A3 == A)
		return (true);
	return (false);
}
