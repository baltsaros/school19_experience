#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(9);
	Fixed d(5);
	Fixed e(5);
	Fixed f(7.05f);
	Fixed g(25.05f);
	Fixed const k(25.05f);
	std::cout << YLWB "\n++++ STANDARD TESTS ++++" NC << std::endl;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << YLWB "\n++++ MY TESTS ++++" NC << std::endl;
	
	std::cout << YLW "\n++++ ARITHMETIC OPERATIONS ++++" NC << std::endl;
	std::cout << c << " + " << d << " =";
	std::cout.width(5); std::cout << (c + d) << std::endl;
	std::cout << c << " - " << d << " =";
	std::cout.width(4); std::cout << (c - d) << std::endl;
	std::cout << d << " * " << e << " =";
	std::cout.width(5); std::cout << (d * e) << std::endl;
	std::cout << f << " + " << c << " =";
	std::cout.width(9); std::cout << (c + f) << std::endl;
	std::cout << f << " - " << c << " =";
	std::cout.width(9); std::cout << (f - c) << std::endl;
	std::cout << g << " / " << e << " =";
	std::cout.width(9); std::cout << (g / e) << std::endl;

	std::cout << YLW "\n++++ COMPARISONS ++++" NC << std::endl;
	std::cout << c << "  > " << d << "? ";
	std::cout.width(5); std::cout << (c > d) << std::endl;
	std::cout << c << "  < " << d << "? ";
	std::cout.width(5); std::cout << (c < d) << std::endl;
	std::cout << e << " >= " << d << "? ";
	std::cout.width(5); std::cout << (e >= d) << std::endl;
	std::cout << c << " <= " << d << "? ";
	std::cout.width(5); std::cout << (c <= d) << std::endl;
	std::cout << e << " == " << d << "? ";
	std::cout.width(5); std::cout << (e == d) << std::endl;
	std::cout << e << " != " << d << "? ";
	std::cout.width(5); std::cout << (e != d) << std::endl;
	std::cout << c << " != " << d << "? ";
	std::cout.width(5); std::cout << (c != d) << std::endl;

	std::cout << YLW "\n++++ DE/INCREMENTATION ++++" NC << std::endl;
	std::cout << "f is equal to ";
	std::cout.width(11); std::cout << f << std::endl;
	std::cout << "++f is equal to ";
	std::cout.width(9); std::cout << ++f << std::endl;
	std::cout << "g is equal to ";
	std::cout.width(11); std::cout << g << std::endl;
	std::cout << "--g is equal to ";
	std::cout.width(9); std::cout << --g << std::endl;
	std::cout << "c is equal to ";
	std::cout.width(5); std::cout << c << std::endl;
	std::cout << "c++ is equal to ";
	std::cout.width(3); std::cout << c++ << std::endl;
	std::cout << "c is equal to ";
	std::cout.width(11); std::cout << c << std::endl;
	std::cout << "d is equal to ";
	std::cout.width(5); std::cout << d << std::endl;
	std::cout << "d-- is equal to ";
	std::cout.width(3); std::cout << d-- << std::endl;
	std::cout << "d is equal to ";
	std::cout.width(11); std::cout << d << std::endl;


	std::cout << YLW "\n++++ MIN/MAX ++++" NC << std::endl;
	std::cout << "max(" << c << ", " << d << ")";
	std::cout.width(11); std::cout << Fixed::max(c, d) << std::endl;
	std::cout << "min(" << c << ", " << d << ")";
	std::cout.width(11); std::cout << Fixed::min(c, d) << std::endl;
	std::cout << "min(" << e << ", " << d << ")";
	std::cout.width(17); std::cout << Fixed::min(e, d) << std::endl;
	std::cout << "const max(" << b << ", " << k << ")";
	std::cout.width(8); std::cout << Fixed::max(b, k) << std::endl;
	std::cout << "const min(" << b << ", " << k << ")";
	std::cout.width(8); std::cout << Fixed::min(b, k) << std::endl;

	return (0);
}
