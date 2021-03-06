#include "Bird.h"

#include <iostream>

Bird::Bird() : 
	GameObject(),
	radius(30.0f),
	flapForce(500.0f),
	rb(),
	state(BirdState::FROZEN)
{
}

Bird::Bird(glm::vec2 _pos, GLfloat _radius, Texture2D _sprite, glm::vec2 _vel, GLfloat _flapForce, GLfloat _gravity, glm::vec2 _rbOffset) :
	GameObject(_pos, glm::vec2(_radius * 2.0f, _radius * 2.0f), _sprite, glm::vec3(1.0f), _vel),
	radius(_radius),
	flapForce(_flapForce),
	rb(),
	state(BirdState::FROZEN)

{
	rb.Init(_gravity, 1.0f, _rbOffset);
}

void Bird::Update()
{
	if (state != BirdState::FROZEN)
	{
		rb.Update(*this);
		if (vel.y > maxFallSpeed)
			vel.y = maxFallSpeed;

		if (vel.y >= 400.0f)
			rot += glm::radians((maxRot / flapForce) * vel.y * .075f);
		if (rot < glm::radians(minRot))
			rot = glm::radians(minRot);
		if (rot > glm::radians(maxRot))
			rot = glm::radians(maxRot);
		if (pos.y > Engine::SCREEN_HEIGHT + 5)
		{
			pos.y = (GLfloat)Engine::SCREEN_HEIGHT + 6;
			state = BirdState::DEAD;
		}
	}
}

void Bird::Render(SpriteRenderer& _renderer)
{
	_renderer.DrawSprite(sprite, pos, size, rot, color);
	//rb.Render(*this, _renderer);
}

void Bird::Flap()
{
	vel.y = -flapForce;
	rot = glm::radians(minRot);
}