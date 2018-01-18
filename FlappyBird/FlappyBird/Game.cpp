#include "Game.h"

#include "../Engine/Engine.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Graphics/SpriteRenderer.h"
#include "../Engine/Graphics/PostProcessor.h"
#include "../Engine/Graphics/TextRenderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <irrKlang.h>

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace irrklang;

//Game-related State data
SpriteRenderer* spriteRenderer;
PostProcessor* postProcessor;
TextRenderer* textRenderer;
ISoundEngine* soundEngine = createIrrKlangDevice();

Game::Game(GLuint _width, GLuint _height) :
	state(GameState::GAME_ACTIVE),
	width(_width),
	height(_height)
{

}

Game::~Game()
{
	delete spriteRenderer;
	spriteRenderer = nullptr;

	delete postProcessor;
	postProcessor = nullptr;

	delete textRenderer;
	textRenderer = nullptr;

	delete soundEngine;
	soundEngine = nullptr;
}

void Game::Init()
{
	//Load shaders
	ResourceManager::LoadShader("Engine/Graphics/Shaders/Sprite.vs", "Engine/Graphics/Shaders/Sprite.fs", nullptr, "sprite");
	ResourceManager::LoadShader("Engine/Graphics/Shaders/PostProcessing.vs", "Engine/Graphics/Shaders/PostProcessing.fs", nullptr, "postprocessing");

	//Configure shaders
	glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(width),
		static_cast<GLfloat>(height), 0.0f, -1.0f, 1.0f);
	ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
	ResourceManager::GetShader("particle").Use().SetInteger("sprite", 0);
	ResourceManager::GetShader("particle").SetMatrix4("projection", projection);

	//Load textures
	ResourceManager::LoadTexture("Assets/Textures/background.png", GL_FALSE, "background");

	//Set render-specific controls
	spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	postProcessor = new PostProcessor(ResourceManager::GetShader("postprocessing"), width, height);

	//Load audio

	//Load text font
	textRenderer = new TextRenderer(width, height);
	textRenderer->Load("Assets/Fonts/arialbd.ttf", 24);

	//Load bird

	//Load pipes
}

void Game::Update()
{

}

void Game::Render()
{
	postProcessor->BeginRender();
	spriteRenderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), glm::vec2(width, height), 0.0f);
	postProcessor->EndRender();
	postProcessor->Render();
	textRenderer->RenderText("Did i do it", 20.0f, 20.0f, 1.0f);
}

void Game::Reset()
{

}