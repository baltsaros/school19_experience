#include <iostream>
#include <string>
#include "whatever.hpp"

int	main(void) {
	std::cout << std::endl;

	std::cout << YLWB "Testing swap" NC << std::endl;
	int			n1 = 6;
	int			n2 = 1;
	float		f1 = 3.027f;
	float		f2 = 9.301f;
	char		c1 = 'a';
	char		c2 = 'b';
	std::string	s1 = "one";
	std::string	s2 = "two";

	std::cout << "n1 is " << n1 << ", n2 is " << n2 << std::endl;
	std::cout << "swaping..." << std::endl;
	swap<int>(n1, n2);
	std::cout << "n1 is " << n1 << ", n2 is " << n2 << std::endl;
	std::cout << std::endl;
	std::cout << "f1 is " << f1 << ", f2 is " << f2 << std::endl;
	std::cout << "swaping..." << std::endl;
	swap<float>(f1, f2);
	std::cout << "f1 is " << f1 << ", f2 is " << f2 << std::endl;
	std::cout << std::endl;
	std::cout << "c1 is " << c1 << ", c2 is " << c2 << std::endl;
	std::cout << "swaping..." << std::endl;
	swap<char>(c1, c2);
	std::cout << "c1 is " << c1 << ", c2 is " << c2 << std::endl;
	std::cout << std::endl;
	std::cout << "s1 is " << s1 << ", s2 is " << s2 << std::endl;
	std::cout << "swaping..." << std::endl;
	swap<char>(s1, s2);
	std::cout << "s1 is " << s1 << ", s2 is " << s2 << std::endl;
	std::cout << std::endl;

	std::cout << YLWB "Testing min" NC << std::endl;
	std::cout << "n1 is " << n1 << ", n2 is " << n2 << std::endl;
	std::cout << "min is " << min<int>(n1, n2) << std::endl;
	std::cout << std::endl;
	std::cout << "f1 is " << f1 << ", f2 is " << f2 << std::endl;
	std::cout << "min is " << min<float>(f1, f2) << std::endl;
	std::cout << std::endl;
	std::cout << "c1 is " << c1 << ", c2 is " << c2 << std::endl;
	std::cout << "min is " << min<char>(c1, c2) << std::endl;
	std::cout << std::endl;
	// std::cout << "s1 is " << s1 << ", s2 is " << s2 << std::endl;
	// std::cout << "min is " << min(s1, s2) << std::endl;
	// std::cout << "s1 is " << s1 << ", s2 is " << s2 << std::endl;

	std::cout << YLWB "Testing max" NC << std::endl;
	std::cout << "n1 is " << n1 << ", n2 is " << n2 << std::endl;
	std::cout << "max is " << max<int>(n1, n2) << std::endl;
	std::cout << std::endl;
	std::cout << "f1 is " << f1 << ", f2 is " << f2 << std::endl;
	std::cout << "max is " << max<float>(f1, f2) << std::endl;
	std::cout << std::endl;
	std::cout << "c1 is " << c1 << ", c2 is " << c2 << std::endl;
	std::cout << "max is " << max<char>(c1, c2) << std::endl;
	std::cout << std::endl;

	return (0);
}
