#include "classes.hpp"

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
	std::cout << "1) ADD to add a new contact;" << std::endl;
	std::cout << "2) SEARCH to search for a contact;" << std::endl;
	std::cout << "3) EXIT to exit;" << std::endl;
}

void	search_contact(PhoneBook *phonebook, size_t i)
{
	std::string	input;
	Contact		contact;
	size_t		j;

	j = 0;
	while (i > 0){
		std::cout << "Write index of the entry to display:" << std::endl;
		std::getline(std::cin, input);
		j = stoi(input) - 1;
		if (j >= 0 && j <= 7 && j < i){
			contact = phonebook->getContact(j);
			contact.printContact();
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
	size_t		i;

	if (argc != 1)
		return (-1);
	(void)argv;
	i = 0;
	welcome_msg();
	while (19){
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0){
			phonebook.fillContact(i % 8);
			++i;
		}
		else if (input.compare("SEARCH") == 0){
			phonebook.displayList();
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