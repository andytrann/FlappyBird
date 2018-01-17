#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"

class InputManager
{
public:
	InputManager();
	//InputManager(Flapper* _flapper);

	bool IsGameClosed();

	void Update();
private:
	//Flapper* flapper;
	bool gameClosed = false;
};

#endif
