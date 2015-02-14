#include "WorldObject.h"

WorldObject::RotationAngle::RotationAngle() : x(0.0), y(0.0), z(0.0) {}

const double& WorldObject::RotationAngle::getX() const { return x; }
const double& WorldObject::RotationAngle::getY() const { return y; }
const double& WorldObject::RotationAngle::getZ() const { return z; }
void WorldObject::RotationAngle::setX(double value) { x = getNormalAngle(value); }
void WorldObject::RotationAngle::setY(double value) { y = getNormalAngle(value); }
void WorldObject::RotationAngle::setZ(double value) { z = getNormalAngle(value); }

double& WorldObject::RotationAngle::getNormalAngle(double &value) const {
	if(value >= 360.0)
		return value -= 360.0;
	else if(value < 0.0)
		return value += 360.0;
	else
		return value;
}

WorldObject::WorldObject(double width, double length, double height, double x, double y, double z) : x(x), y(y), z(z), width(width), length(length), height(height), rotationAngle() {}
WorldObject::~WorldObject() {}

double WorldObject::getWidth() const { return width; }
double WorldObject::getLength() const { return length; }
double WorldObject::getHeight() const { return height; }

void WorldObject::rotate(double x, double y, double z) {
	rotationAngle.setX(x);
	rotationAngle.setY(y);
	rotationAngle.setZ(z);
}