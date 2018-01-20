#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "../GameObject.h"
#include "../Engine.h"

class Rigidbody
{
public:
	Rigidbody();

	void Init(GLfloat _gravity, GLfloat friction);
	void Update(GameObject& _object);
	void Render(GameObject& _object);
private:
	GLfloat gravity;
	GLfloat friction;
};

#endif
