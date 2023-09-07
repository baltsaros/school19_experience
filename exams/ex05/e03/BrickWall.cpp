#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::~BrickWall() {}

BrickWall*	BrickWall::clone() {
	BrickWall	*tmp = new BrickWall();
	return tmp;
}
