#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
	std::map<std::string, ASpell *>::iterator	it;
	for (it = _spellBook.begin(); it != _spellBook.end(); ++it)
		delete it->second;
}

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void		Warlock::learnSpell(ASpell *spell) {
	if (!spell)
		return ;
	_spellBook.insert(std::pair<std::string, ASpell*>(spell->getName(), spell->clone()));
}

void		Warlock::forgetSpell(std::string toForget) {
	std::map<std::string, ASpell *>::iterator	it;
	it = _spellBook.find(toForget);
	if (it == _spellBook.end())
		return ;
	delete it->second;
	_spellBook.erase(it);
}

void		Warlock::launchSpell(std::string spell, const ATarget &target) {
	std::map<std::string, ASpell *>::iterator	it;
	it = _spellBook.find(spell);
	if (it == _spellBook.end())
		return ;
	it->second->launch(target);
}

void		Warlock::setTitle(const std::string &title) {_title = title;}

std::string	Warlock::getName() const { return _name;}
std::string	Warlock::getTitle() const { return _title;}