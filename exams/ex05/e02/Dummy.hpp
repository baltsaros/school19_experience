#pragma once

# include "ATarget.hpp"

class Dummy: public ATarget {
	public:
		Dummy();
		// Dummy(const Dummy &src);
		~Dummy();

		// Dummy&	operator=(const Dummy &rhs);
		Dummy*	clone();
};