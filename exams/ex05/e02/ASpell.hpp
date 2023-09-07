#pragma once

#include <string>
#include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell {
	private:
		std::string	_name;
		std::string	_effects;

	public:
		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell &src);
		virtual ~ASpell();

		ASpell&			operator=(const ASpell &rhs);
		virtual ASpell*	clone() = 0;
		void			launch(const ATarget &target) const;

		std::string		getName() const;
		std::string		getEffects() const;
};