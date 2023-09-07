#pragma once

# include <map>
# include "ASpell.hpp"

class SpellBook {
	private:
		std::map<std::string, ASpell*>	_spellBook;

	public:
		SpellBook();
		~SpellBook();

		void		learnSpell(ASpell *spell);
		void		forgetSpell(const std::string &spell);
		ASpell*		createSpell(const std::string &spell);
};