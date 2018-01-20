#include "Bird.h"

#include <iostream>

Bird::Bird() : 
	GameObject(),
	radius(30.0f),
	flapForce(500.0f),
	rb()
{
}

Bird::Bird(glm::vec2 _pos, GLfloat _radius, Texture2D _sprite, glm::vec2 _vel, GLfloat _flapForce) :
	GameObject(_pos, glm::vec2(_radius * 2.0f, _radius * 2.0f), _sprite, glm::vec3(1.0f), _vel),
	radius(_radius),
	flapForce(_flapForce),
	rb()

{
	rb.Init(30.0f, 1.0f);
}

void Bird::Update()
{
	rb.Update(*this);
	if (vel.y > maxFallSpeed)
		vel.y = maxFallSpeed;
	if(vel.y >= 400.0f)
		rot += glm::radians((maxRot / flapForce) * vel.y * .075f);
	if (rot < glm::radians(minRot))
		rot = glm::radians(minRot);
	if (rot > glm::radians(maxRot))
		rot = glm::radians(maxRot);
	std::cout << vel.y << std::endl;
}

void Bird::Render(SpriteRenderer& _renderer)
{
	_renderer.DrawSprite(sprite, pos, size, rot, color);
	_renderer.DrawSprite(ResourceManager::GetTexture("outline"), pos, size, rot, color);
}

void Bird::Flap()
{
	vel.y = -flapForce;
	rot = glm::radians(minRot);
}