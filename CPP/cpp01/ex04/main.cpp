#include "SearchReplace.hpp"

int	main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Invalid argc" << std::endl;
		return (-1);
	}

	int				ret;
	SearchReplace	replacer(argv[1], argv[2], argv[3]);
	ret = replacer.openReplace();
	if (ret){
		if (ret == -3)
			std::cerr << "Error opening file" << std::endl;
		else if (ret == -4)
			std::cerr << "Error while replacing" << std::endl;
		else
			std::cerr << "Damn, something went wront" << std::endl;
		return (ret);
	}
	return (0);
}