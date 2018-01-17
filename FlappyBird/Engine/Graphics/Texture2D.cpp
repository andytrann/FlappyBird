#include "Texture2D.h"

#include <iostream>

Texture2D::Texture2D() :
	width(0),
	height(0),
	internal_Format(GL_RGB),
	image_Format(GL_RGB),
	wrap_S(GL_REPEAT),
	wrap_T(GL_REPEAT),
	filter_Min(GL_LINEAR),
	filter_Max(GL_LINEAR)
{
	glGenTextures(1, &ID);
}

void Texture2D::Generate(GLuint _width, GLuint _height, unsigned char* _data)
{
	width = _width;
	height = _height;
	// Create Texture
	glBindTexture(GL_TEXTURE_2D, ID);
	glTexImage2D(GL_TEXTURE_2D, 0, internal_Format, _width, _height, 0, image_Format, GL_UNSIGNED_BYTE, _data);

	// Set Texture wrap and filter modes
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_S);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_T);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_Min);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_Max);

	// Unbind texture
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, ID);
}