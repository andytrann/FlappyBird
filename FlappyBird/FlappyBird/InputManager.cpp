#include "InputManager.h"

InputManager::InputManager()
{
	gameClosed = false;
}

bool InputManager::IsGameClosed()
{
	return gameClosed;
}

void InputManager::Update(Bird& _bird)
{	
	if (Keyboard::KeyDown(GLFW_KEY_SPACE) /*|| Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)*/)
	{
		_bird.Flap();
	}
	/*
	if (Keyboard::KeyDown(GLFW_KEY_GRAVE_ACCENT))
	{
		flapper->TogglePause();
	}
	*/

	if (Keyboard::KeyDown(GLFW_KEY_ESCAPE))
	{
		gameClosed = true;
	}
}