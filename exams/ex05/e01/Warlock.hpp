#pragma once

# include <string>
# include <iostream>

class Warlock {
	private:
		std::string	_name;
		std::string	_title;

	public:
		// Warlock();
		Warlock(std::string name, std::string title);
		// Warlock(const Warlock &src);
		~Warlock();

		// Warlock&	operator=(const Warlock &rhs);
		void		introduce() const;

		void		setTitle(const std::string &title);

		std::string	getName() const;
		std::string	getTitle() const;


};