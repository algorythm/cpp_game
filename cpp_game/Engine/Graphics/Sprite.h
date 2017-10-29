#pragma once

#include "GLFW/glfw3.h"
#include "Texture.h"
#include "../GameObject.h"

#include <iostream>
#include <string>

class Sprite : public GameObject {
public:
	Sprite();
	Sprite(string _imagePath);
	Sprite(string _imagePath, float _xPos, float _yPos);
	Sprite(Texture _texture);
	Sprite(Texture _texture, float _xPos, float _yPos);

	void Update();
	void Render();
private:
	Texture texture;
};