/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:11:25 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/12 10:19:34 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static std::string	format_str(std::string str)
{
	std::string	tmp;

	tmp = str;
	if (tmp.length() > 10){
		tmp = str.substr(0, 10);
		tmp[9] = '.';
	}
	return (tmp);
}

void	PhoneBook::fillContact(size_t i){
	this->_pb[i].add();
	std::cout << GRNB "The contact was added!" NC << std::endl;
	std::cout << "Type a command (ADD, SEARCH or EXIT):" << std::endl;
}

void	PhoneBook::displayList(){
	Contact		contact;
	size_t		j;

	j = 0;
	std::cout << "Here is the list of all contacts from your PhoneBook:" << std::endl;
	std::cout << std::right << "|";
	std::cout.width(10); std::cout << std::right << "index";
	std::cout << std::right << "|";
	std::cout.width(10); std::cout << std::right << "first name";
	std::cout << std::right << "|";
	std::cout.width(10); std::cout << std::right << "last name";
	std::cout << std::right << "|";
	std::cout.width(10); std::cout << std::right << "nickname";
	std::cout << std::right << "|\n";
	while (j < 8){
		contact = this->getContact(j);
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << j + 1;
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << format_str(contact.getFname());
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << format_str(contact.getLname());
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << format_str(contact.getNname());
		std::cout << std::right << "|\n";
		++j;
	}
}

Contact	PhoneBook::getContact(size_t i){
	return (this->_pb[i]);
}

