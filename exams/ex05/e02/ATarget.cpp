#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget(std::string type) : _type(type) {}

ATarget::ATarget(const ATarget &src) {*this = src;}

ATarget::~ATarget() {}

ATarget&	ATarget::operator=(const ATarget &rhs) {
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

void		ATarget::getHitBySpell(const ASpell &spell) const {
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}

std::string	ATarget::getType() const {return _type;}