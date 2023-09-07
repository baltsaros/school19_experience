#pragma once

#include <string>
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
	private:
		std::string	_type;

	public:
		ATarget();
		ATarget(std::string type);
		ATarget(const ATarget &src);
		virtual ~ATarget();

		ATarget&			operator=(const ATarget &rhs);
		virtual ATarget*	clone() = 0;
		void				getHitBySpell(const ASpell &spell) const;
		std::string			getType() const;
};