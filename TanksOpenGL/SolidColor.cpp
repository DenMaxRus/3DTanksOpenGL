#include "SolidColor.h"

SolidColor::SolidColor(int r, int g, int b, int alpha): r(r), g(g), b(b), alpha(alpha){}

SolidColor::~SolidColor() {}

GLuint SolidColor::getTextureID() {
	return 0;
}