#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

Fwoosh*	Fwoosh::clone() {
	Fwoosh *tmp = new Fwoosh();
	return tmp;
}