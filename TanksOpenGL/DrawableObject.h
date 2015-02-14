#pragma once
#include "WorldObject.h"
#include "Color.h"
class DrawableObject :
	public WorldObject {
public:
	virtual ~DrawableObject();
	virtual void draw() = 0;
	Color *texture;
protected:
	DrawableObject(double width, double length, double height, double &x, double &y, double &z);
};

