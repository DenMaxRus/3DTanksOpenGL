#pragma once
#include <GL\freeglut.h>
class Color {
public:
	virtual GLuint getTextureID() = 0;
protected:
	Color();
	virtual ~Color();
};