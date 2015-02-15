#pragma once
#include "WorldObject.h"
class OperatedObject :
	public WorldObject {
public:
	enum Direction { FORWARD, BACKWARD , LEFT, RIGHT, UP, DOWN };
	double speed, maxSpeed, acceleration;

	OperatedObject(double width, double length, double height, double x = 0.0, double y = 0.0, double z = 0.0);
	~OperatedObject();

	virtual void move(Direction &direction);
private:
};