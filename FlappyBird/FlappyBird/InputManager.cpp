#include "InputManager.h"

InputManager::InputManager()
{
	//flapper = nullptr;
}
/*
InputManager::InputManager(Flapper* _flapper)
{
	flapper = _flapper;
}
*/
bool InputManager::IsGameClosed()
{
	return gameClosed;
}

void InputManager::Update()
{	/*
	if (Keyboard::KeyDown(GLFW_KEY_SPACE) || Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT))
	{
		flapper->Flap();
	}

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