#pragma once

# include <new>
# include "ASpell.hpp"

class Polymorph: public ASpell {
	public:
		Polymorph();
		~Polymorph();

		Polymorph*	clone();
};