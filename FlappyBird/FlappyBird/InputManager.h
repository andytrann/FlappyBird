#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "Bird.h"

class InputManager
{
public:
	InputManager();

	bool IsGameClosed();

	void Update(Bird& _bird);
private:
	bool gameClosed = false;
};

#endif
