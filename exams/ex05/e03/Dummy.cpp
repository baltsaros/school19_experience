#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

Dummy*	Dummy::clone() {
	Dummy	*tmp = new Dummy();
	return tmp;
}