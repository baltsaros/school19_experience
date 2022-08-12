/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abuzdin <abuzdin@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 10:11:19 by abuzdin           #+#    #+#             */
/*   Updated: 2022/08/12 10:20:08 by abuzdin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void	welcome_msg(void)
{
	std::cout << "Welcome to your PhoneBook! Choose one of the following commands:" << std::endl;
	std::cout << "1) ADD to add a new contact;" << std::endl;
	std::cout << "2) SEARCH to search for a contact;" << std::endl;
	std::cout << "3) EXIT to exit;" << std::endl;
	std::cout << "WARNING! Unathorized commands will launch self-destruction!" << std::endl;
}

void	error_msg(void)
{
	std::cout << REDB "DESTRUCTION IN..." << std::endl;
	std::cout << "3" << std::endl;
	usleep(1000000);
	std::cout << "2" << std::endl;
	usleep(1000000);
	std::cout << "1.5" << std::endl;
	usleep(1000000);
	std::cout << "1" << std::endl;
	usleep(1000000);
	std::cout << "Boom!" << std::endl;
	usleep(1000000);
	std::cout << "Bam!" << std::endl;
	usleep(1000000);
	std::cout << NC "Just kidding (:: Choose a proper command please:" << std::endl;
	std::cout << "1) ADD to add a new contact;" << std::endl;
	std::cout << "2) SEARCH to search for a contact;" << std::endl;
	std::cout << "3) EXIT to exit;" << std::endl;
}

void	search_contact(PhoneBook phonebook, int i)
{
	std::string	input;
	Contact		contact;
	int			j;

	j = 0;
	while (i > 0){
		std::cout << "Write index of the entry to display:" << std::endl;
		std::getline(std::cin, input);
		j = atoi(input.c_str()) - 1;
		if (j >= 0 && j <= 7 && j < i){
			contact = phonebook.getContact(j);
			contact.printContact();
			break ;
		}
		else
			std::cout << REDL "Wrong input! Try again." NC << std::endl;
	}
	if (i == 0)
		std::cout << REDL "The PhoneBook is empty! Fill it with ADD command." NC << std::endl;

}

int	main(int argc, char *argv[]){
	std::string	input;
	PhoneBook	phonebook;
	int			i;

	if (argc != 1)
		return (-1);
	(void)argv;
	i = 0;
	welcome_msg();
	while (19){
		std::getline(std::cin, input);
		if (input == "ADD"){
			phonebook.fillContact(i % 8);
			++i;
		}
		else if (input == "SEARCH"){
			phonebook.displayList();
			search_contact(phonebook, i);
		}
		else if (input == "EXIT"){
			std::cout << GRNB "Bye!" NC << std::endl;
			return (0);
		}
		else
			error_msg();
	}
	return (0);
}