#ifndef BIRD_H
#define BIRD_H

#include "../Engine/GameObject.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Physics/Rigidbody.h"

enum class State
{
	ALIVE,
	DEAD
};

class Bird : public GameObject
{
public:
	Bird();
	Bird(glm::vec2 _pos, GLfloat _radius, Texture2D _sprite, glm::vec2 _vel, GLfloat _flapForce);

	void Update();
	void Render(SpriteRenderer& _renderer);

	void Flap();

private:
	GLfloat radius;
	GLfloat flapForce;

	Rigidbody rb;
};

#endif
