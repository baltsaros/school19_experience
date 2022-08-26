/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SearchReplace.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 09:43:01 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/26 10:26:49 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SearchReplace.hpp"

SearchReplace::SearchReplace(std::string filename, std::string s1, std::string s2):
	_filename(filename), _s1(s1), _s2(s2){
		std::cout << GRN "Got input!" NC << std::endl;
		return ;
	}

SearchReplace::~SearchReplace(void){
	std::cout << GRN "Done!" NC << std::endl;
	return ;
}

int	SearchReplace::ftReplace(std::string *read){
	std::size_t	found;

	if (!read || (*read).size() == std::string::npos)
		return (-4);
	found = (*read).find(this->_s1);
	while (found != std::string::npos){
		(*read).erase(found, this->_s1.length());
		(*read).insert(found, this->_s2);
		found = (*read).find(this->_s1);
	}
	return (0);
}

int	SearchReplace::openReplace(void){
	std::fstream	input;
	std::fstream	output;
	std::string		read;
	int				ret;

	if (this->_filename.size() == 0 || this->_s1.size() == 0 || this->_s2.size() == 0)
		return (-2);
	input.open(this->_filename.c_str(), std::fstream::in);
	if (!input.is_open())
		return (-3);
	output.open((this->_filename + ".replace").c_str(), std::fstream::out | std::fstream::trunc);
	if (!output.is_open())
		return (-3);
	while (std::getline(input, read)){
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
