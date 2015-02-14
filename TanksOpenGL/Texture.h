#pragma once
#include <string>
#include "Color.h"

class Texture :
	public Color {
public:
	Texture(std::string);
	~Texture();
	GLuint getTextureID() override;
private:
	std::string originalFilePath;
	unsigned char *bitmap;
};