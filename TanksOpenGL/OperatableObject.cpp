#define _USE_MATH_DEFINES
#include <cmath>

#include "OperatableObject.h"

OperatableObject::OperatableObject(double width, double length, double height, double x, double y, double z) : WorldObject(width, length, height, x, y, z) {}

OperatableObject::~OperatableObject() {}

void OperatableObject::move(OperatableObject::Direction direction) {
	switch(direction) {
	case FORWARD:case BACKWARD:{
		double currentSpeed(direction == FORWARD ? forwardSpeed : -backwardSpeed),
			sinA(sin(rotationAngle.getY())), cosA(cos(rotationAngle.getY())),
			deltaY(currentSpeed*sinA), deltaX(currentSpeed*cosA);
		shiftBy(deltaX, 0.0, deltaY);
	}
				 break;
	case LEFT:case RIGHT:{
		double currentAngle((rotationAngle.getY() + (direction == LEFT ? 90 : -90)) * M_PI / 180.0),
			sinA(sin(currentAngle)), cosA(cos(currentAngle)),
			deltaY(forwardSpeed*cosA), deltaX(forwardSpeed*sinA);
		shiftBy(deltaX, 0.0, deltaY);
	}
			  break;
	case UP:

		break;
	}
}