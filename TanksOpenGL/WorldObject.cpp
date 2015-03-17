#include "WorldObject.h"

WorldObject::WorldObject(double width, double length, double height, double x, double y, double z) : Point(x, y, z), width(width), length(length), height(height), halfWidth(width/2.0), halfLength(length/2.0), halfHeight(height/2.0) {}
WorldObject::~WorldObject() {}
// Get sizes
const double& WorldObject::getWidth() const { return width; }
const double& WorldObject::getLength() const { return length; }
const double& WorldObject::getHeight() const { return height; }
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
const double& WorldObject::getHWidth() const { return halfWidth; }
const double& WorldObject::getHLength() const { return halfLength; }
const double& WorldObject::getHHeight() const { return halfHeight; }