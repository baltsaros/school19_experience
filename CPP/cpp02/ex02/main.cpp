#include "Fixed.hpp"

int main( void ) {
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c(9);
	Fixed d(5);
	Fixed e(5);
	std::cout << "++++ STANDARD TESTS ++++" << std::endl;
	
	
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "++++ MY TESTS ++++" << std::endl;
	
	std::cout << "++++ COMPARISONS ++++" << std::endl;
	// std::cout << "c is equal to " << c << std::endl;
	// std::cout << "d is equal to " << d << std::endl;
	// std::cout << "e is equal to " << e << std::endl;
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
	// std::cout.width(15); std::cout << std::left << "c  > d? " << (c > d) << std::endl;
	// std::cout.width(15); std::cout << std::left << "c  < d? " << (c < d) << std::endl;
	// std::cout.width(15); std::cout << std::left << "e >= d? " << (e >= d) << std::endl;
	// std::cout.width(15); std::cout << std::left << "c <= d? " << (c <= d) << std::endl;
	// std::cout.width(15); std::cout << std::left << "e == d? " << (e == d) << std::endl;
	// std::cout.width(15); std::cout << std::left << "e != d? " << (e != d) << std::endl;
	// std::cout.width(15); std::cout << std::left << "c != d? " << (c != d) << std::endl;


	return (0);
}
