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

void	SearchReplace::openReplace(void){
	std::fstream	stream;

	stream.open((this->_filename + ".replace").c_str(), stream.out);
	stream.close();
	return ;
}
