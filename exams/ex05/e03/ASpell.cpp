#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects) {

}

ASpell::ASpell(const ASpell &src) {
	*this = src;
}

ASpell::~ASpell() {}

ASpell&		ASpell::operator=(const ASpell &rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_effects = rhs._effects;
	}
	return *this;
}

void		ASpell::launch(const ATarget &target) const {
	target.getHitBySpell(*this);
}

std::string	ASpell::getName() const {return _name;}
std::string	ASpell::getEffects() const {return _effects;}