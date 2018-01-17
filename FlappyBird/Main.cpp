#include "Engine/Engine.h"
#include "FlappyBird/InputManager.h"

#include <iostream>
#include <time.h>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(NULL));
	
	Engine engine;
	engine.Init("FlappyBird");
	/*
	Game flappyBird(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
	flappyBird.Init();
	*/

	InputManager im;

	while (!im.IsGameClosed())
	{
		engine.Update();
		im.Update();

		glfwSwapBuffers(engine.GetWindow());
	}

	glfwTerminate();
	return 0;
}