#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Graphics/Texture2D.h"
#include "Graphics/SpriteRenderer.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

class GameObject
{
public:
	GameObject();
	GameObject(glm::vec2 _pos, glm::vec2 _size, Texture2D _sprite, glm::vec3 _color = glm::vec3(1.0f), glm::vec2 _vel = glm::vec2(0.0f, 0.0f));

	void Draw(SpriteRenderer& _renderer);

	glm::vec2 pos, size, vel;
	glm::vec3 color;
	GLfloat rot;
	GLboolean isSolid;
	GLboolean destroyed;
	Texture2D sprite;
};

#endif
