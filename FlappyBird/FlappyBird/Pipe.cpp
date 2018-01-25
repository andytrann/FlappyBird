#include "Pipe.h"

GLfloat Pipe::speed = -150.f;
GLfloat Pipe::gap = 200.f;

Pipe::Pipe() : 
	isActive(true),
	topRB(),
	botRB(),
	pos(glm::vec2(0.0f, 0.0f)),
	topPipe(),
	botPipe()
{
}

Pipe::Pipe(glm::vec2 _pos, glm::vec2 _size, Texture2D _sprite, GLfloat _speed, GLfloat _gap, glm::vec2 _rbOffset) : 
	isActive(true),
	topRB(),
	botRB(),
	pos(_pos),
	topPipe(_pos, _size, _sprite),
	botPipe(_pos, _size, _sprite)
{
	speed = -_speed;
	gap = _gap;
	topRB.Init(0.0f, 1.0f, _rbOffset);
	botRB.Init(0.0f, 1.0f, _rbOffset);
	topPipe.pos = glm::vec2(pos.x - _size.x, pos.y - gap - _size.y);
	topPipe.vel.x = speed;
	botPipe.pos = glm::vec2(pos.x - _size.x, pos.y + gap);
	botPipe.vel.x = speed;
	botPipe.rot = 3.14159f;
}

void Pipe::Update()
{
	topRB.Update(topPipe);
	botRB.Update(botPipe);
}

void Pipe::Render(SpriteRenderer & _renderer)
{
	//topRB.Render(topPipe, _renderer);
	//botRB.Render(botPipe, _renderer);

	_renderer.DrawSprite(topPipe.sprite, topPipe.pos, topPipe.size, topPipe.rot);
	_renderer.DrawSprite(botPipe.sprite, botPipe.pos, botPipe.size, botPipe.rot);
}

void Pipe::ToggleActiveState()
{
	isActive = false;
}

bool Pipe::IsActive() const
{
	return isActive;
}

GLfloat Pipe::GetPosX() const
{
	return pos.x;
}



