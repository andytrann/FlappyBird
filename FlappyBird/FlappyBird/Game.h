
#include <GL/glew.h>
#include <GLFW/glfw3.h>

enum class GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};

class Game
{
public:
	Game(GLuint _width, GLuint _height);
	~Game();

	void Init();
	void Update();
	void Render();
	void Reset();

private:
	GameState state;
	GLuint width, height;
};