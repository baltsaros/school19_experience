#pragma once

# include <map>
# include "ATarget.hpp"

class TargetGenerator {
	private:
		std::map<std::string, ATarget*>	_targets;

	public:
		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType(ATarget *);
		void		forgetTargetType(const std::string &target);
		ATarget*	createTarget(const std::string &target);

};