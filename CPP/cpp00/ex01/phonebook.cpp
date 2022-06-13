#include "classes.hpp"

// PhoneBook::PhoneBook(void){
// 	std::cout << "PhoneBook constructor" << std::endl;
// 	return ;
// }

// PhoneBook::~PhoneBook(void){
// 	std::cout << "PhoneBook destructor" << std::endl;
// 	return ;
// }

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
	std::cout << "DESTRUCTION IN..." << std::endl;
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
	std::cout << "Just kidding (:: Choose a proper command please:" << std::endl;
	usleep(1000000);
	std::cout << "1) ADD to add a new contact;" << std::endl;
	usleep(1000000);
	std::cout << "2) SEARCH to search for a contact;" << std::endl;
	usleep(1000000);
	std::cout << "3) EXIT to exit;" << std::endl;
}

std::string	format_str(std::string str)
{
	std::string	tmp;

	tmp = str;
	if (tmp.length() > 10){
		tmp = str.substr(0, 10);
		tmp[9] = '.';
	}
	return (tmp);
}

void	search_contact(PhoneBook *phonebook, size_t i)
{
	std::string	input;
	size_t		j;

	j = 0;
	while (j < i){
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << j;
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << format_str(phonebook->_pb[j].getFname());
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << format_str(phonebook->_pb[j].getLname());
		std::cout << std::right << "|";
		std::cout.width(10); std::cout << std::right << format_str(phonebook->_pb[j].getNname());
		std::cout << std::right << "|\n";
		++j;
	}
	while (i > 0){
		std::cout << "Write index of the entry to display:" << std::endl;
		std::getline(std::cin, input);
		j = stoi(input);
		if (j >= 0 && j <= 7 && j < i){
			phonebook->_pb[j].printContacts();
			break ;
		}
		else
			std::cout << "Wrong input! Try again." << std::endl;
	}
	if (i == 0)
		std::cout << "The PhoneBook is empty! Fill is with ADD command." << std::endl;

}

int	main(int argc, char *argv[]){
	std::string	input;
	PhoneBook	phonebook;
	Contacts	contact;
	size_t		i;

	if (argc != 1)
		return (-1);
	(void)argv;
	i = 0;
	welcome_msg();
	while (19){
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0){
			if (i == 8)
				i = 0;
			phonebook._pb[i].add();
			std::cout << "The contact was added!" << std::endl;
			++i;
		}
		else if (input.compare("SEARCH") == 0){
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
			search_contact(&phonebook, i);
		}
		else if (input.compare("EXIT") == 0){
			std::cout << "Bye!" << std::endl;
			exit (0);
		}
		else
			error_msg();
	}
	return (0);
}