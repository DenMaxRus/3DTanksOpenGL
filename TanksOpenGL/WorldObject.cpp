#include "WorldObject.h"

WorldObject::RotationAngle::RotationAngle() : xAngle(0.0), yAngle(0.0), zAngle(0.0) {}
// Get rotation angles
const double& WorldObject::RotationAngle::getX() const { return xAngle; }
const double& WorldObject::RotationAngle::getY() const { return yAngle; }
const double& WorldObject::RotationAngle::getZ() const { return zAngle; }
// Set absolute rotation angles
void WorldObject::RotationAngle::setX(double value) { xAngle = getNormalAngle(value); }
void WorldObject::RotationAngle::setY(double value) { yAngle = getNormalAngle(value); }
void WorldObject::RotationAngle::setZ(double value) { zAngle = getNormalAngle(value); }
// Set relative rotation angles
void WorldObject::RotationAngle::setXr(double value) { xAngle = getNormalAngle(xAngle += value); }
void WorldObject::RotationAngle::setYr(double value) { yAngle = getNormalAngle(yAngle += value); }
void WorldObject::RotationAngle::setZr(double value) { zAngle = getNormalAngle(zAngle += value); }

double& WorldObject::RotationAngle::getNormalAngle(double &value) const {
	if(value >= 360.0)
		return value -= 360.0;
	else if(value < 0.0)
		return value += 360.0;
	else
		return value;
}

WorldObject::WorldObject(double width, double length, double height, double x, double y, double z) : x(x), y(y), z(z), width(width), length(length), height(height), halfWidth(width/2.0), halfLength(length/2.0), halfHeight(height/2.0), rotationAngle() {}
WorldObject::~WorldObject() {}
// Get sizes
double WorldObject::getWidth() const { return width; }
double WorldObject::getLength() const { return length; }
double WorldObject::getHeight() const { return height; }
// Set sizes
void WorldObject::setWidth(double value)  {
	if(value > 0.0) {
		width = value;
		halfWidth = width / 2.0;
	} else
		width = halfWidth = 0.0;
}
void WorldObject::setLength(double value) {
	if(value > 0.0) {
		length = value;
		halfLength = length / 2.0;
	} else
		length = halfLength = 0.0;
}
void WorldObject::setHeight(double value) {
	if(value > 0) {
		height = value;
		halfHeight = height / 2.0;
	} else
		height = halfHeight = 0;
}
// Get half sizes
double WorldObject::getHWidth() const { return halfWidth; }
double WorldObject::getHLength() const { return halfLength; }
double WorldObject::getHHeight() const { return halfHeight; }
// Transformations
// Simplify rotation by setting rotationAngle x, y, z values
void WorldObject::rotate(double x, double y, double z) {
	rotationAngle.setX(x);
	rotationAngle.setY(y);
	rotationAngle.setZ(z);
}
// Change rotationAngle x, y, z values by relative values
void WorldObject::rotateRelative(double xAngleDelta, double yAngleDelta, double zAngleDelta) {
	rotationAngle.setXr(xAngleDelta);
	rotationAngle.setYr(yAngleDelta);
	rotationAngle.setZr(zAngleDelta);
}
// Change center coordinates
void WorldObject::moveTo(double x, double y, double z) {
	x = x;
	y = y;
	z = z;
}
// Change center coordinates by relative values
void WorldObject::shiftBy(double xDelta, double yDelta, double zDelta) {
	x += xDelta;
	y += yDelta;
	z += zDelta;
}