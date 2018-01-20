#include "Rigidbody.h"

Rigidbody::Rigidbody() : 
	gravity(0.0f),
	friction(1.0f)
{

}

void Rigidbody::Init(GLfloat _gravity, GLfloat _friction)
{
	gravity = _gravity;
	friction = _friction;
}

void Rigidbody::Update(GameObject& _object)
{
	_object.vel.x *= friction;
	_object.vel.y += gravity;

	_object.pos += (_object.vel * Engine::GetDT());
}

void Rigidbody::Render(GameObject& _object)
{

}