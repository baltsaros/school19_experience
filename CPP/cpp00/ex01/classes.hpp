#ifndef CLASSES_HPP
# define CLASSES_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <unistd.h>

class	Contacts {
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;

	public:
		void		add(void);
		void		printContacts(void);
		std::string	getFname(void);
		std::string	getLname(void);
		std::string	getNname(void);
};

class	PhoneBook {
	private:
	public:
		Contacts	_pb[8];
		// PhoneBook(void);
		// ~PhoneBook(void);
};

#endif