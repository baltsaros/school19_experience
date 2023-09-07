#pragma once

# include <new>
# include "ASpell.hpp"

class Fwoosh: public ASpell {
	public:
		Fwoosh();
		~Fwoosh();

		Fwoosh*	clone();
};