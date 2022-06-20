#include "SearchReplace.hpp"

SearchReplace::SearchReplace(std::string filename, std::string s1, std::string s2):
	_filename(filename), _s1(s1), _s2(s2){
		std::cout << "Got input!" << std::endl;
		return ;
	}

SearchReplace::~SearchReplace(void){
	std::cout << "Done!" << std::endl;
	return ;
}

int	SearchReplace::openReplace(void){
	std::fstream	input;
	std::fstream	output;
	std::string		read;

	input.open(this->_filename.c_str());
	if (!input.is_open())
		return (-3);
	output.open((this->_filename + ".replace").c_str(), output.out);
	while (input){
		std::getline(input, read);
		output << read;
		output << std::endl;
	}
	input.close();
	output.close();
	return (0);
}
