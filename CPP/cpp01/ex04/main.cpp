#include "SearchReplace.hpp"

int	main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Error: Invalid amount of arguments!" << std::endl;
		return (-1);
	}

	int				ret;
	SearchReplace	replacer(argv[1], argv[2], argv[3]);
	ret = replacer.openReplace();
	if (ret){
		if (ret == -2)
			std::cerr << "Error: Invalid arguments!" << std::endl;
		else if (ret == -3)
			std::cerr << "Error: Corrupted file!" << std::endl;
		else if (ret == -4)
			std::cerr << "Error: Incorrect replacement!" << std::endl;
		else
			std::cerr << "Damn, something went wrong!" << std::endl;
		return (ret);
	}
	return (0);
}
