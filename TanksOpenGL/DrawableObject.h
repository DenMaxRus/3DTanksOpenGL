#pragma once
#include "WorldObject.h"
#include "Color.h"

// TODO Implement scaling?

class DrawableObject :
	public WorldObject {
public:
	virtual ~DrawableObject();
	virtual void draw() const = 0;
	Color *texture;
protected:
	DrawableObject(double width, double length, double height, double &x, double &y, double &z);
};