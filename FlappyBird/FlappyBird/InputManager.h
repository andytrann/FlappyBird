#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "../Engine/Engine.h"
#include "../Engine/IO/Keyboard.h"
#include "Bird.h"
#include <irrKlang.h>

using namespace irrklang;

class Game;

class InputManager
{
public:
	InputManager();

	bool IsGameClosed();

	void Update(Game& _game, Bird& _bird, ISoundEngine* _sound);
private:
	bool gameClosed = false;
};

#endif
