#ifndef CLASSES_HPP
# define CLASSES_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <unistd.h>

class	Contacts {
	private:
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	secret;
		// Contacts(std::string fname, std::string lname, std::string nname, std::string num, std::string dsecret);
		// Contacts(void);
		// ~Contacts(void);
};

class	Phonebook {
	private:
	public:
		// Phonebook(void);
		// ~Phonebook(void);
		Contacts	pb[8];
};


#endif