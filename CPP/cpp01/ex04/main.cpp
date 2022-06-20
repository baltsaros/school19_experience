#include "SearchReplace.hpp"

int	main(int argc, char **argv){
	if (argc != 4){
		std::cout << "Invalid argc" << std::endl;
		return (-1);
	}

	int				ret;
	SearchReplace	replacer(argv[1], argv[2], argv[3]);
	ret = replacer.openReplace();
	if (ret){
		std::cout << "Error opening file" << std::endl;
		return (-3);
	}
	return (0);
}