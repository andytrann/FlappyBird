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

void InputManager::Update(Game& _game, Bird& _bird, ISoundEngine* _sound)
{
	if (_game.state == GameState::GAME_MENU)
	{
		if (Keyboard::KeyDown(GLFW_KEY_SPACE))
		{
			_game.state = GameState::GAME_ACTIVE;
			_bird.state = BirdState::ALIVE;
			_bird.Flap();
			_sound->play2D("Assets/Sounds/FlapFX.mp3", GL_FALSE);
		}
	}
	if (_game.state == GameState::GAME_ACTIVE)
	{
		if (Keyboard::KeyDown(GLFW_KEY_SPACE) /*|| Mouse::ButtonDown(GLFW_MOUSE_BUTTON_LEFT)*/)
		{
			_bird.Flap();
			_sound->play2D("Assets/Sounds/FlapFX.mp3", GL_FALSE);
		}
	}
	
	if (_game.state == GameState::GAME_LOSE && _bird.state == BirdState::DEAD)
	{
		if (Keyboard::KeyDown(GLFW_KEY_SPACE))
		{
			_game.Reset();
		}
	}

	if (Keyboard::KeyDown(GLFW_KEY_ESCAPE))
	{
		gameClosed = true;
	}
}