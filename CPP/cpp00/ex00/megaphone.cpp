#include <iostream>

int	main(int argc, char **argv){
	size_t	i;
	size_t	j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else{
		while (argv[i]){
			j = 0;
			while (argv[i][j]){
				argv[i][j] = std::toupper(argv[i][j]);
				++j;
			}
			std::cout << argv[i];
			++i;
		}
		std::cout << std::endl;
	}
	return (0);
}
