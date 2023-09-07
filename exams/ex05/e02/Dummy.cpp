#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy") {}

// Dummy::Dummy(const Dummy &src) : ATarget(src) {*this = src;}

Dummy::~Dummy() {}

// Dummy&	Dummy::operator=(const Dummy &rhs) {
// 	if (this != &rhs)
// 		_type = rhs._type;
// 	return *this;
// }

Dummy*	Dummy::clone() {
	Dummy	*tmp = new Dummy();
	return tmp;
}