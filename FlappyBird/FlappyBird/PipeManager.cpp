#include "PipeManager.h"

#include "../Engine/Engine.h"
#include "../Engine/Graphics/SpriteRenderer.h"
#include "Bird.h"

PipeManager::PipeManager() :
	xSeparation(400.0f),
	minSpawnY(Engine::SCREEN_HEIGHT - 200),
	maxSpawnY(200),
	totalPipes(0)
{
	CreatePipe();
}

PipeManager::~PipeManager()
{
	for (unsigned int i = 0; i < pipes.size(); ++i)
	{
		delete pipes[i];
		pipes[i] = nullptr;
	}
}

void PipeManager::Update()
{
	std::vector<unsigned int> pipesToDelete;
	for (unsigned int i = 0; i < pipes.size(); ++i)
	{
		pipes[i]->Update();
		if (pipes[i]->GetPosX() < -pipes[i]->GetWidth())
		{
			pipesToDelete.push_back(i);
		}

		if (i == pipes.size() - 1)
		{
			if (pipes[i]->GetPosX() < Engine::SCREEN_WIDTH - xSeparation)
			{
				CreatePipe();
			}
		}
	}

	for (unsigned int i = 0; i < pipesToDelete.size(); ++i)
	{
		delete pipes[pipesToDelete[i]];
		pipes.erase(pipes.begin() + pipesToDelete[i]);
	}
}

void PipeManager::Render(SpriteRenderer& _renderer)
{
	for (unsigned int i = 0; i < pipes.size(); ++i)
	{
		pipes[i]->Render(_renderer);
	}
}

bool PipeManager::CheckCollision(Bird& _bird)
{
	bool isColliding = false;
	for (unsigned int i = 0; i < pipes.size(); ++i)
	{
		isColliding = _bird.rb.CheckCollision(_bird, pipes[i]->topPipe) ||
					  _bird.rb.CheckCollision(_bird, pipes[i]->botPipe);
		if (isColliding)
		{
			pipes[i]->ToggleActiveState();
			break;
		}
	}

	return isColliding;
}

std::vector<Pipe*> PipeManager::GetPipes() const
{
	return pipes;
}

void PipeManager::CreatePipe()
{
	GLfloat spawnY = (GLfloat)(rand() % (minSpawnY - maxSpawnY) + maxSpawnY);
	Pipe* pipe = new Pipe(glm::vec2(Engine::SCREEN_WIDTH + 90.0f, spawnY), glm::vec2(90.0f, 500.0f), ResourceManager::GetTexture("pipe"), 200.0f, 75.0f);
	
	pipes.push_back(pipe);
	totalPipes++;
}