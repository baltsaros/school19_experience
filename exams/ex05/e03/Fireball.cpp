#include "Fireball.hpp"

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp") {}

Fireball::~Fireball() {}

Fireball*	Fireball::clone() {
	Fireball *tmp = new Fireball();
	return tmp;
}
