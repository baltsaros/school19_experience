#include "Data.hpp"
#include <iomanip>

int	main(void) {
	Data		*test = new Data;
	uintptr_t	uptr;

	uptr = test->serialize(test);	
	std::cout << "before: " << test << std::endl;
	std::cout << "serialization: " << uptr << std::endl;
	std::cout << "deserialization: " << test->deserialize(uptr) << std::endl;

	delete test;
	return (0);
}