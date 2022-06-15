#ifndef CLASSES_HPP
# define CLASSES_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

class	Contact {
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;

	public:
		void		add(void);
		void		printContact(void);
		std::string	getFname(void);
		std::string	getLname(void);
		std::string	getNname(void);
};

class	PhoneBook {
	private:
		Contact		_pb[8];
	public:
		void		fillContact(size_t i);
		void		displayList(void);
		Contact		getContact(size_t i);
		// PhoneBook(void);
		// ~PhoneBook(void);
};

#endif