#include "ScoreManager.h"

ScoreManager::ScoreManager(PipeManager& _pipeManager) :
	pipeManager(_pipeManager),
	score(0)
{
}

bool ScoreManager::Update()
{
	std::vector<Pipe*> pipes = pipeManager.GetPipes();
	for (unsigned int i = 0; i < pipes.size(); ++i)
	{
		if (pipes[i]->GetPosX() < (Engine::SCREEN_WIDTH / 2) - 100 && pipes[i]->IsActive())
		{
			pipes[i]->ToggleActiveState();
			score++;
			return true;
		}
	}
	return false;
}

GLuint ScoreManager::GetScore() const
{
	return score;
}