#include "InputManager.h"

#include "Game.h"

InputManager::InputManager()
{
	gameClosed = false;
}

bool InputManager::IsGameClosed()
{
	return gameClosed;
}

void InputManager::Update(Game& _game, Bird& _bird)
{
	if (_game.state == GameState::GAME_MENU)
	{
		if (Keyboard::KeyDown(GLFW_KEY_SPACE))
		{
			_game.state = GameState::GAME_ACTIVE;
			_bird.state = BirdState::ALIVE;
			_bird.Flap();
		}
	}
	if (_game.state == GameState::GAME_ACTIVE)
	{
		if (Keyboard::KeyDown(GLFW_KEY_SPACE) /*|| Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)*/)
		{
			_bird.Flap();
		}
	}
	
	if (_game.state == GameState::GAME_LOSE)
	{
		if (Keyboard::KeyDown(GLFW_KEY_SPACE))
		{
			_game.Reset();
		}
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