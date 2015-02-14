#include "Texture.h"


Texture::Texture(std::string filePath) : originalFilePath(filePath){}

Texture::~Texture() {
	delete[] bitmap;
}

GLuint Texture::getTextureID(){
	return 0;
}