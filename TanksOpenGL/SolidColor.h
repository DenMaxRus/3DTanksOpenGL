#pragma once
#include "Color.h"
class SolidColor :
	public Color {
public:
	SolidColor(int, int, int, int = 0xFF);
	~SolidColor();
	GLuint getTextureID() override;
private:
	unsigned char alpha, r, g, b;
};