#include "Texture.h"

Texture::Texture() {
	this->id = -1;
}

Texture::Texture(int _id) {
	this->id = _id;

	if (!this->GetTextureParams()) {
		cout << "[ERROR] Failed to load image with id: " << _id << endl;
	}
}

Texture::Texture(string _path) {
	id = SOIL_load_OGL_texture(_path.c_str(), SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MULTIPLY_ALPHA);

	if (!this->GetTextureParams()) {
		cout << "[ERROR] Failed to load image: " << _path << endl;
	}
}

int Texture::GetId()
{
	return this->id;
}

int Texture::GetWidth()
{
	return this->width;
}

int Texture::GetHeight()
{
	return this->height
}

bool Texture::GetTextureParams() {
	if (id <= 0) return false;

	int mipLevel = 0;
	glBindTexture(GL_TEXTURE_2D, id); // Bind out texture to gl texture
	glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_WIDTH, &width);   // Store width
	glGetTexLevelParameteriv(GL_TEXTURE_2D, mipLevel, GL_TEXTURE_HEIGHT, &height); // Store height
}
