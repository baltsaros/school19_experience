#ifndef SEARCHREPLACE_HPP
# define SEARCHREPLACE_HPP

# include <iostream>
# include <string>
# include <fstream>

class	SearchReplace{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;

	public:
		SearchReplace(std::string filename, std::string s1, std::string s2);
		~SearchReplace(void);

		void	openReplace(void);
};

#endif