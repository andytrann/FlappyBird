#include "Bird.h"

#include <iostream>

Bird::Bird() : 
	GameObject(),
	radius(30.0f),
	flapForce(700.0f),
	rb()
{
}

Bird::Bird(glm::vec2 _pos, GLfloat _radius, Texture2D _sprite, glm::vec2 _vel, GLfloat _flapForce) :
	GameObject(_pos, glm::vec2(_radius * 2.0f, _radius * 2.0f), _sprite, glm::vec3(1.0f), _vel),
	radius(_radius),
	flapForce(_flapForce),
	rb()

{
	rb.Init(1.0f, 1.0f);
}

void Bird::Update()
{
	rb.Update(*this);
	std::cout << vel.y << std::endl;
}

void Bird::Render(SpriteRenderer& _renderer)
{
	_renderer.DrawSprite(sprite, pos, size, rot, color);
	_renderer.DrawSprite(ResourceManager::GetTexture("outline"), pos, size, rot, color);
}

void Bird::Flap()
{
	vel.y = flapForce;
}