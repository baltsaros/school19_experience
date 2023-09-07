#pragma once

# include <new>
# include "ASpell.hpp"

class Fireball: public ASpell {
	public:
		Fireball();
		~Fireball();

		Fireball*	clone();
};