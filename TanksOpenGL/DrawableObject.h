#pragma once
#include "Color.h"

// TODO Implement scaling?

class DrawableObject {
public:
	virtual ~DrawableObject();
	virtual void draw() const = 0;
	Color *texture;
protected:
	DrawableObject();
};