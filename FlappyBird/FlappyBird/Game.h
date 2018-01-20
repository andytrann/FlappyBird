#ifndef GAME_H
#define GAME_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum class GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

const GLfloat BIRD_RADIUS = 30.0f;

class Game
{
public:
	Game(GLuint _width, GLuint _height);
	~Game();

	void Init();
	void ProcessInput();
	void Update();
	void Render();
	void Reset();

	GLboolean IsGameClosed();

private:
	GameState state;
	GLuint width, height;
};

#endif