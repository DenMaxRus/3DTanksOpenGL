#include "NotImplementedException.h"
#include "Box.h"

primitives::Box::Box(double width, double length, double height, double x, double y, double z) : DrawableObject(width, length, height, x, y, z) {}

primitives::Box::~Box() {}

void primitives::Box::draw() {
	throw NotImplementedException();
}