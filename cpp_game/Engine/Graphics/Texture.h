#pragma once

#include "GLFW\glfw3.h"
#include "SOIL\src\SOIL.h"

#include <iostream>
#include <string>

using namespace std;

class Texture
{
public:
	Texture();
	Texture(int _id);
	Texture(std::string _path);
	~Texture();

	int GetId();
	int GetWidth();
	int GetHeight();
private:
	bool GetTextureParams();

	int id;
	int width;
	int height;
};