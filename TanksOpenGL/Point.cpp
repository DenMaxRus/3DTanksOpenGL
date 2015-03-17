#include "Point.h"

Point::RotationAngle::RotationAngle() : xAngle(0.0), yAngle(0.0), zAngle(0.0) {}
// Get rotation angles
const double& Point::RotationAngle::getX() const { return xAngle; }
const double& Point::RotationAngle::getY() const { return yAngle; }
const double& Point::RotationAngle::getZ() const { return zAngle; }
// Set absolute rotation angles
void Point::RotationAngle::setX(double value) { xAngle = getNormalAngle(value); }
void Point::RotationAngle::setY(double value) { yAngle = getNormalAngle(value); }
void Point::RotationAngle::setZ(double value) { zAngle = getNormalAngle(value); }
// Set relative rotation angles
void Point::RotationAngle::setXr(double value) { xAngle = getNormalAngle(xAngle += value); }
void Point::RotationAngle::setYr(double value) { yAngle = getNormalAngle(yAngle += value); }
void Point::RotationAngle::setZr(double value) { zAngle = getNormalAngle(zAngle += value); }

double& Point::RotationAngle::getNormalAngle(double &value) const {
	if(value >= 360.0)
		return value -= 360.0;
	else if(value < 0.0)
		return value += 360.0;
	else
		return value;
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z), rotationAngle() {}
Point::~Point() {}

// Transformations
// Simplify rotation by setting rotationAngle x, y, z values
void Point::rotate(double x, double y, double z) {
	rotationAngle.setX(x);
	rotationAngle.setY(y);
	rotationAngle.setZ(z);
}
// Change rotationAngle x, y, z values by relative values
void Point::rotateRelative(double xAngleDelta, double yAngleDelta, double zAngleDelta) {
	rotationAngle.setXr(xAngleDelta);
	rotationAngle.setYr(yAngleDelta);
	rotationAngle.setZr(zAngleDelta);
}
// Change center coordinates
void Point::moveTo(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}
// Change center coordinates by relative values
void Point::shiftBy(double xDelta, double yDelta, double zDelta) {
	x += xDelta;
	y += yDelta;
	z += zDelta;
}
