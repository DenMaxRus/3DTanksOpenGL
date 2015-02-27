#pragma once
#include "WorldObject.h"
class OperatableObject :
	public WorldObject {
public:
	enum Direction { FORWARD = 1, BACKWARD = 2, LEFT = 4, RIGHT = 8, UP = 16, DOWN = 32 };
	double rotateSpeed, forwardSpeed, backwardSpeed, upSpeed, downSpeed, maxSpeed, acceleration;

	OperatableObject(double width, double length, double height, double x = 0.0, double y = 0.0, double z = 0.0);
	~OperatableObject();

	virtual void move(Direction direction);
private:
};