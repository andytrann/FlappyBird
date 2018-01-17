#include "Engine/Engine.h"
#include "FlappyBird/InputManager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Engine/ResourceManager.h"
#include "Engine/Graphics/SpriteRenderer.h"
#include "Engine/Graphics/PostProcessor.h"
#include "Engine/Graphics/TextRenderer.h"

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

	ResourceManager::LoadShader("Engine/Graphics/Shaders/Sprite.vs", "Engine/Graphics/Shaders/Sprite.fs", nullptr, "sprite");
	ResourceManager::LoadShader("Engine/Graphics/Shaders/PostProcessing.vs", "Engine/Graphics/Shaders/PostProcessing.fs", nullptr, "postprocessing");
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat> (Engine::SCREEN_WIDTH),
		static_cast<GLfloat>(Engine::SCREEN_HEIGHT), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

	ResourceManager::LoadTexture("Assets/Textures/background.png", GL_TRUE, "background");

	SpriteRenderer* renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	PostProcessor* pp = new PostProcessor(ResourceManager::GetShader("postprocessing"), Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
	TextRenderer* textRenderer = new TextRenderer(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT);
	textRenderer->Load("Assets/Fonts/arialbd.ttf", 24);
	

	while (!im.IsGameClosed())
	{
		engine.Update();
		im.Update();
		pp->BeginRender();
		renderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0, 0), glm::vec2(Engine::SCREEN_WIDTH, Engine::SCREEN_HEIGHT), 0.0f);
		pp->EndRender();
		pp->Render();
		textRenderer->RenderText("Did i do it", 20.0f, 20.0f, 1);

		glfwSwapBuffers(engine.GetWindow());
	}
	delete textRenderer;
	delete pp;
	delete renderer;
	ResourceManager::Clear();
	glfwTerminate();
	return 0;
}