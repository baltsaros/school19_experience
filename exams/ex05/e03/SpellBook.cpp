#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	std::map<std::string, ASpell *>::iterator	it;
	for (it = _spellBook.begin(); it != _spellBook.end(); ++it)
		delete it->second;
}

void	SpellBook::learnSpell(ASpell *spell) {
	if (!spell)
		return ;
	_spellBook.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void	SpellBook::forgetSpell(const std::string &spell) {
	std::map<std::string, ASpell *>::iterator	it;
	it = _spellBook.find(spell);
	if (it == _spellBook.end())
		return ;
	delete it->second;
	_spellBook.erase(it);
}

ASpell*	SpellBook::createSpell(const std::string &spell) {
	std::map<std::string, ASpell *>::iterator	it;
	it = _spellBook.find(spell);
	if (it == _spellBook.end())
		return NULL;
	return it->second;
}
