#ifndef PIPE_MANAGER_H
#define PIPE_MANAGER_H

#include "Pipe.h"

#include <vector>

class Bird;
class SpriteRenderer;
 
class PipeManager
{
public:
	PipeManager();
	~PipeManager();

	void Update();
	void Render(SpriteRenderer& _renderer);

	bool CheckCollision(Bird& _bird);

	std::vector<Pipe*> GetPipes() const;

private:
	void CreatePipe();

	std::vector<Pipe*> pipes;
	GLfloat xSeparation;
	GLuint minSpawnY;
	GLuint maxSpawnY;
	GLuint totalPipes;
};

#endif
