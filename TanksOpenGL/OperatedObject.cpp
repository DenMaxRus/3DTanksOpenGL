#define _USE_MATH_DEFINES
#include <cmath>

#include "OperatedObject.h"

OperatedObject::OperatedObject(double width, double length, double height, double x, double y, double z) : WorldObject(width, length, height, x, y, z) {}

OperatedObject::~OperatedObject() {}

void OperatedObject::move(OperatedObject::Direction &direction) {
	switch(direction) {
	case FORWARD:case BACKWARD:{
		double currentSpeed(direction == FORWARD ? speed : -speed),
			sinA(sin(rotationAngle.getY())), cosA(cos(rotationAngle.getY())),
			deltaY(currentSpeed*sinA), deltaX(currentSpeed*cosA);
		shiftBy(deltaX, 0.0, deltaY);
	}
		break;
	case LEFT:case RIGHT:{
		double currentAngle((rotationAngle.getY() + (direction == LEFT ? 90 : -90)) * M_PI / 180.0),
			sinA(sin(currentAngle)), cosA(cos(currentAngle)),
			deltaY(speed*cosA), deltaX(speed*sinA);
		shiftBy(deltaX, 0.0, deltaY);
	}
		break;
	}
}