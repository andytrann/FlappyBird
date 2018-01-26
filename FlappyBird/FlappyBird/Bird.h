#ifndef BIRD_H
#define BIRD_H

#include "../Engine/GameObject.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Physics/Rigidbody.h"

enum class BirdState
{
	ALIVE,
	DEAD,
	FROZEN
};

class Bird : public GameObject
{
public:
	Bird();
	Bird(glm::vec2 _pos, GLfloat _radius, Texture2D _sprite, glm::vec2 _vel, GLfloat _flapForce, GLfloat _gravity = 30.0f, glm::vec2 _rbOffset = glm::vec2(0.0f, 0.0f));

	void Update();
	void Render(SpriteRenderer& _renderer);

	void Flap();
	Rigidbody rb;
	BirdState state;
private:
	GLfloat radius;
	GLfloat flapForce;
	GLfloat maxFallSpeed = 700.0f;
	GLfloat maxRot = 90.0f;
	GLfloat minRot = -30.0f;
};

#endif
