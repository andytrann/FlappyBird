#include "Bird.h"

Bird::Bird() : 
	GameObject(),
	radius(30.0f),
	flapForce(100.0f)
{
}

Bird::Bird(glm::vec2 _pos, GLfloat _radius, Texture2D _sprite, glm::vec2 _vel, GLfloat _flapForce) :
	GameObject(_pos, glm::vec2(_radius * 2.0f, _radius * 2.0f), _sprite, glm::vec3(1.0f), _vel),
	radius(_radius),
	flapForce(_flapForce)

{

}

void Bird::Update()
{

}

void Bird::Render(SpriteRenderer& _renderer)
{
	_renderer.DrawSprite(sprite, pos, size, rot, color);
}

void Bird::Flap()
{

}