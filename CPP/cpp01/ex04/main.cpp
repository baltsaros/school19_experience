#include "SearchReplace.hpp"

int	main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Invalid argc" << std::endl;
		return (-1);
	}

	std::fstream	fs;
	fs.open(argv[1]);
	if (!fs.is_open()){
		std::cout << "Error opening file" << std::endl;
		return (-3);
	}

	SearchReplace	replacer(argv[1], argv[2], argv[3]);
	replacer.openReplace();
	return (0);
}