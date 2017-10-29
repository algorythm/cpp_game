#include "Sprite.h"

Sprite::Sprite() : Sprite(Texture(), 0, 0) { }
Sprite::Sprite(string _imagePath) : Sprite(Texture(_imagePath), 0, 0) { }
Sprite::Sprite(string _imagePath, float _xPos, float _yPos) : Sprite(Texture(_imagePath), _xPos, _yPos) { }
Sprite::Sprite(Texture _texture) : Sprite(_texture, 0, 0) { }
Sprite::Sprite(Texture _texture, float _xPos, float _yPos)
{
	this->texture = _texture;
	this->x = _xPos;
	this->y = _yPos;
}

void Sprite::Update() 
{

}

void Sprite::Render() 
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, this->texture.GetID());
	glLoadIdentity();

	// Order here is importent
	// TRANSLATE -> ROTATE -> SCALE
	glTranslatef(this->x, this->y, 0); // <- this is the global translation

	// Rendering
	glColor4f(1, 1, 1, 1); // Set the color to white, full alpha
	glBegin(GL_QUADS); // Begin rendering
	// Coordinates in parenthesis below are local translation
	glTexCoord2f(0.0, 0.0); glVertex2f(0.0, 0.0);													// Top Left
	glTexCoord2f(1.0, 0.0); glVertex2f(this->texture.GetWidth(), 0.0);							// Bottom Left
	glTexCoord2f(1.0, 1.0); glVertex2f(this->texture.GetWidth(), this->texture.GetHeight());	// Bottom Right
	glTexCoord2f(0.0, 1.0); glVertex2f(0.0, this->texture.GetHeight());								// Top Left
	glEnd();

	glDisable(GL_TEXTURE_2D);
}