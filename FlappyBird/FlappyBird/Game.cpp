#include "Game.h"

#include "../Engine/Engine.h"
#include "../Engine/ResourceManager.h"
#include "../Engine/Graphics/SpriteRenderer.h"
#include "../Engine/Graphics/PostProcessor.h"
#include "../Engine/Graphics/TextRenderer.h"
#include "Bird.h"
#include "Pipe.h"
#include "PipeManager.h"
#include "InputManager.h"
#include "ScoreManager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <irrKlang.h>

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>

using namespace irrklang;

//Game-related State data
SpriteRenderer* spriteRenderer;
PostProcessor* postProcessor;
TextRenderer* textRenderer;
ISoundEngine* soundEngine = createIrrKlangDevice();

Bird* bird;
PipeManager* pipeManager;
ScoreManager* scoreManager;
InputManager* im;

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

	delete bird;
	bird = nullptr;

	delete im;
	im = nullptr;

	delete pipeManager;
	pipeManager = nullptr;

	delete scoreManager;
	scoreManager = nullptr;
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
	ResourceManager::LoadTexture("Assets/Textures/bird.png", GL_TRUE, "bird");
	ResourceManager::LoadTexture("Assets/Textures/outline.png", GL_TRUE, "outline");
	ResourceManager::LoadTexture("Assets/Textures/pipe.png", GL_TRUE, "pipe");

	//Set render-specific controls
	spriteRenderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));
	postProcessor = new PostProcessor(ResourceManager::GetShader("postprocessing"), width, height);

	//Load audio

	//Load text font
	textRenderer = new TextRenderer(width, height);
	textRenderer->Load("Assets/Fonts/arialbd.ttf", 24);

	//Load bird
	glm::vec2 playerPos = glm::vec2((width / 2) - BIRD_RADIUS, (height / 2) - BIRD_RADIUS);
	bird = new Bird(playerPos, BIRD_RADIUS, ResourceManager::GetTexture("bird"), glm::vec2(0.0f, 0.0f), 550.0f, 30.0f, glm::vec2(8.0f,10.0f));

	//Load pipes
	pipeManager = new PipeManager();

	//Load scoremanager
	scoreManager = new ScoreManager(*pipeManager);

	//Load input manager
	im = new InputManager();
}

void Game::ProcessInput()
{
	im->Update(*bird);
}

void Game::Update()
{
	bird->Update();
	pipeManager->Update();
	
	bool isColliding = pipeManager->CheckCollision(*bird);
	//std::cout << (isColliding ? "COLLIDING!!!" : "....") << std::endl;
	if (scoreManager->Update())
	{
		soundEngine->play2D("Assets/Sounds/ScoreFX.mp3", GL_FALSE);
	}
	
}

void Game::Render()
{
	postProcessor->BeginRender();

	spriteRenderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), glm::vec2(width, height));
	pipeManager->Render(*spriteRenderer);
	bird->Render(*spriteRenderer);

	postProcessor->EndRender();
	postProcessor->Render();
	std::stringstream score;
	score << scoreManager->GetScore();
	textRenderer->RenderText(score.str(), 20.0f, 20.0f, 1.0f);
}

void Game::Reset()
{

}

GLboolean Game::IsGameClosed()
{
	return im->IsGameClosed();
}
