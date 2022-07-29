#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	int		num;
	Base	*ret;

	num = rand() % 3 + 1;
	switch(num) {
		case 1:
			ret = new (A);
			break ;
		case 2:
			ret = new (B);
			break ;
		case 3:
			ret = new (C);
			break ;
	}
	return (ret);
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "class C" << std::endl;
	else
		std::cout << "Damn, something went wront!" << std::endl;
	return ;
}

void	identify(Base &p) {
	try {
		A	&a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch(std::bad_cast &bc) {
		std::cerr << "Not A: " << bc.what() << std::endl;
	}
	try {
		B	&b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch(std::bad_cast &bc) {
		std::cerr << "Not B: " << bc.what() << std::endl;
	}
	try {
		C	&c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch(std::bad_cast &bc) {
		std::cerr << "Not C: " << bc.what() << std::endl;
	}
	return ;
}

int	main(void) {
	srand(time(0));
	std::cout << "Test 1" << std::endl;
	Base	*one;
	one = generate();
	identify(one);
	identify(*one);
	std::cout << std::endl;

	std::cout << "Test 2" << std::endl;
	Base	*two;
	two = generate();
	identify(two);
	identify(*two);
	std::cout << std::endl;

	std::cout << "Test 3" << std::endl;
	Base	*three;
	three = generate();
	identify(three);
	identify(*three);
	std::cout << std::endl;

	delete one;
	delete two;
	delete three;
	return (0);
}