#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "../GameObject.h"
#include "../Engine.h"
#include "../Graphics/SpriteRenderer.h"
#include "../ResourceManager.h"

class Rigidbody
{
public:
	Rigidbody();

	void Init(GLfloat _gravity, GLfloat friction, glm::vec2 _offset);
	void Update(GameObject& _object);
	void Render(GameObject& _object, SpriteRenderer& _renderer);

	bool CheckCollision(GameObject& _object1, GameObject& _object2);
private:
	GLfloat gravity;
	GLfloat friction;
	glm::vec2 offset;
};

#endif
