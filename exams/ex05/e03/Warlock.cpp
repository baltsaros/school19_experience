#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void		Warlock::learnSpell(ASpell *spell) {
	_spellBook.learnSpell(spell);
}

void		Warlock::forgetSpell(const std::string &spell) {
	_spellBook.forgetSpell(spell);
}

void		Warlock::launchSpell(const std::string &spell, const ATarget &target) {
	ASpell	*tmp;

	tmp = _spellBook.createSpell(spell);
	if (tmp != NULL)
		tmp->launch(target);
}

void		Warlock::setTitle(const std::string &title) {_title = title;}

std::string	Warlock::getName() const { return _name;}
std::string	Warlock::getTitle() const { return _title;}