#include "Engine/Engine.h"
#include "FlappyBird/Game.h"
#include "FlappyBird/InputManager.h"
#include "Engine\ResourceManager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include <iostream>
#include <time.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(NULL));
	
	Engine engine;
	engine.Init("FlappyBird");
	
	Game flappyBird(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
	flappyBird.Init();
	
	InputManager im;
	
	while (!flappyBird.IsGameClosed())
	{
		//im.Update();
		flappyBird.ProcessInput();
		engine.Update();
		flappyBird.Update();
		flappyBird.Render();

		glfwSwapBuffers(engine.GetWindow());
	}
	ResourceManager::Clear();
	glfwTerminate();

	return 0;
}