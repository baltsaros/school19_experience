#include "classes.hpp"

// Contact::Contact(std::string fname, std::string lname, std::string nname, std::string num, std::string dsecret){
// Contact::Contact(void){
// 	std::cout << "Contact constructor" << std::endl;
// 	return ;
// }

// Contact::~Contact(void){
// 	std::cout << "Contact destructor" << std::endl;
// 	return ;
// }

void	Contact::add(){
	std::cout << "Enter first name:" << std::endl;
	std::getline(std::cin, this->_first_name);
	std::cout << "Enter last name:" << std::endl;
	std::getline(std::cin, this->_last_name);
	std::cout << "Enter nickname:" << std::endl;
	std::getline(std::cin, this->_nickname);
	std::cout << "Enter phone number:" << std::endl;
	std::getline(std::cin, this->_number);
	std::cout << "Enter new contact's darkest secret:" << std::endl;
	std::getline(std::cin, this->_secret);
}

void	Contact::printContacts(){
		std::cout << this->_first_name << std::endl;
		std::cout << this->_last_name << std::endl;
		std::cout << this->_nickname << std::endl;
		std::cout << this->_number << std::endl;
		std::cout << this->_secret << std::endl;
}

std::string	Contact::getFname(void){
	return (_first_name);
}

std::string	Contact::getLname(void){
	return (_last_name);
}

std::string	Contact::getNname(void){
	return (_nickname);
}

