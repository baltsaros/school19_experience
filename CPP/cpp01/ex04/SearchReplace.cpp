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

int	SearchReplace::ftReplace(std::string *read){
	std::size_t	found;

	if (!read || (*read).size() == std::string::npos)
		return (-4);
	found = 1;
	while (found){
		found = (*read).find(this->_s1);
		if (found == std::string::npos)
			return (0);
		(*read).erase(found, this->_s1.length());
		(*read).insert(found, this->_s2);
	}
	return (0);
}

int	SearchReplace::openReplace(void){
	std::fstream	input;
	std::fstream	output;
	std::string		read;
	int				ret;

	input.open(this->_filename.c_str(), std::fstream::in);
	if (!input.is_open())
		return (-3);
	output.open((this->_filename + ".replace").c_str(), std::fstream::out | std::fstream::trunc);
	while (input){
		std::getline(input, read);
		ret = this->ftReplace(&read);
		if (ret){
			input.close();
			output.close();
			return (ret);
		}
		output << read << std::endl;
	}
	input.close();
	output.close();
	return (0);
}
