#ifndef PIPE_H
#define PIPE_H

#include "../Engine/GameObject.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Physics/Rigidbody.h"

class Pipe 
{
public:
	Pipe();
	Pipe(glm::vec2 _pos, glm::vec2 _size, Texture2D _sprite, GLfloat _speed, GLfloat _gap, glm::vec2 _rbOffset = glm::vec2(0.0f, 0.0f));

	void Update();
	void Render(SpriteRenderer& _renderer);

	void ToggleActiveState();
	bool IsActive() const;

	GLfloat GetPosX() const;

	Rigidbody topRB;
	Rigidbody botRB;

	GameObject topPipe;
	GameObject botPipe;

private:
	glm::vec2 pos; //located in middle right edge of the gap
	
	static GLfloat speed;
	static GLfloat gap;

	bool isActive;
};

#endif
