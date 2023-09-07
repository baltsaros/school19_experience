#pragma once

# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock {
	private:
		std::string						_name;
		std::string						_title;
		std::map<std::string, ASpell*>	_spellBook;

	public:
		// Warlock();
		Warlock(std::string name, std::string title);
		// Warlock(const Warlock &src);
		~Warlock();

		// Warlock&	operator=(const Warlock &rhs);
		void		introduce() const;
		void		learnSpell(ASpell *spell);
		void		forgetSpell(std::string toForget);
		void		launchSpell(std::string spell, const ATarget &target);

		void		setTitle(const std::string &title);

		std::string	getName() const;
		std::string	getTitle() const;


};