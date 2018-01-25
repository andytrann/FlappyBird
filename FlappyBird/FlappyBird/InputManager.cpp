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
	
	if (Keyboard::Key(GLFW_KEY_W))
	{
		_bird.pos.y -= 1.f;
	}
	if (Keyboard::Key(GLFW_KEY_S))
	{
		_bird.pos.y += 1.f;
	}
	if (Keyboard::Key(GLFW_KEY_A))
	{
		_bird.pos.x -= 1.f;
	}
	if (Keyboard::Key(GLFW_KEY_D))
	{
		_bird.pos.x += 1.f;
	}
	if (Keyboard::KeyDown(GLFW_KEY_Q))
	{
		_bird.rot += 3.14159f / 4.0f;
	}
	if (Keyboard::KeyDown(GLFW_KEY_E))
	{
		_bird.rot -= 3.14159f / 4.0f;
	}
	*/
	if (Keyboard::KeyDown(GLFW_KEY_ESCAPE))
	{
		gameClosed = true;
	}
}