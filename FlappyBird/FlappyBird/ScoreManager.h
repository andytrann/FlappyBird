#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

#include "PipeManager.h"


class ScoreManager 
{
public:
	ScoreManager(PipeManager& _pipeManager);
	bool Update();
	
	GLuint GetScore() const;
private:
	PipeManager& pipeManager;
	GLuint score;
};

#endif