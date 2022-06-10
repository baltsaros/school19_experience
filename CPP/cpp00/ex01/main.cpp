#include "classes.hpp"

int	main(int argc, char *argv[]){
	std::string	input;
	Contacts	contact;
	PhoneBook	phonebook;
	size_t		i;

	if (argc != 1)
		return (-1);
	(void)argv;
	i = 0;
	std::cout << "Welcome to your PhoneBook! Choose one of the following commands" << std::endl;
	std::cout << "ADD to add a new contact" << std::endl;
	std::cout << "SEARCH to search for a contact" << std::endl;
	std::cout << "EXIT to exit" << std::endl;
	std::cout << "Unathorized commands will launch self-destruction" << std::endl;
	while (19){
		std::getline(std::cin, input);
		// std::cout << input << std::endl;
		if (input.compare("ADD") == 0){
			std::cout << "Enter first name" << std::endl;
			std::getline(std::cin, contact.first_name);
			std::cout << "Enter last name" << std::endl;
			std::getline(std::cin, contact.last_name);
			std::cout << "Enter nickname" << std::endl;
			std::getline(std::cin, contact.nickname);
			std::cout << "Enter phone number" << std::endl;
			std::getline(std::cin, contact.number);
			std::cout << "Enter new contact's darkest secret" << std::endl;
			std::getline(std::cin, contact.secret);
			phonebook.pb[i] = contact;
			std::cout << "The contact was added!" << std::endl;
			std::cout << phonebook.pb[i].first_name << std::endl;
			++i;
		}
		else {
			std::cout << "DESTRUCTION IN." << std::endl;
			std::cout << "DESTRUCTION IN.." << std::endl;
			std::cout << "DESTRUCTION IN..." << std::endl;
			
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			return (-1);
		}
	}
	return (0);
}