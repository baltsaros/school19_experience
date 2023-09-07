#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter") {}

Polymorph::~Polymorph() {}

Polymorph*	Polymorph::clone() {
	Polymorph *tmp = new Polymorph();
	return tmp;
}
