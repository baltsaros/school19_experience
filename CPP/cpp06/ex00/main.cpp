#include "Convertor.hpp"

int	main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: Invalid amout of arguments" << std::endl;
		return (1);
	}
	try {
		Convertor	in(argv[1]);

		std::cout << in;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}