#include "Rigidbody.h"

#include <math.h>
#include <vector>
#include <algorithm>
#include <iterator>

Rigidbody::Rigidbody() : 
	gravity(0.0f),
	friction(1.0f)
{

}

void Rigidbody::Init(GLfloat _gravity, GLfloat _friction)
{
	gravity = _gravity;
	friction = _friction;
}

void Rigidbody::Update(GameObject& _object)
{
	_object.vel.x *= friction;
	_object.vel.y += gravity;

	_object.pos += (_object.vel * Engine::GetDT());
}

void Rigidbody::Render(GameObject& _object)
{
	
}
glm::vec2 Project(const glm::vec2& a, const glm::vec2& b);
bool Rigidbody::CheckCollision(GameObject& _obj1, GameObject& _obj2)
{
	//get center of RB1
	glm::vec2 center1 = _obj1.pos + (_obj1.size / 2.0f);
	
	//get vertices of RB before rotation
	glm::vec2 UL1 = _obj1.pos;
	glm::vec2 UR1 = glm::vec2(_obj1.pos.x + _obj1.size.x, _obj1.pos.y);
	glm::vec2 LL1 = glm::vec2(_obj1.pos.x, _obj1.pos.y + _obj1.size.y);
	glm::vec2 LR1 = glm::vec2(_obj1.pos.x + _obj1.size.x, _obj1.pos.y + _obj1.size.y);

	//apply rotation
	glm::vec2 tempUL1 = UL1 - center1;
	glm::vec2 tempUR1 = UR1 - center1;
	glm::vec2 tempLL1 = LL1 - center1;
	glm::vec2 tempLR1 = LR1 - center1;

	tempUL1 = glm::vec2((tempUL1.x *  cosf(_obj1.rot)) - (tempUL1.y * sinf(_obj1.rot)), (tempUL1.x * sinf(_obj1.rot)) + (tempUL1.y *  cosf(_obj1.rot)));
	tempUR1 = glm::vec2((tempUR1.x *  cosf(_obj1.rot)) - (tempUR1.y * sinf(_obj1.rot)), (tempUR1.x * sinf(_obj1.rot)) + (tempUR1.y *  cosf(_obj1.rot)));
	tempLL1 = glm::vec2((tempLL1.x *  cosf(_obj1.rot)) - (tempLL1.y * sinf(_obj1.rot)), (tempLL1.x * sinf(_obj1.rot)) + (tempLL1.y *  cosf(_obj1.rot)));
	tempLR1 = glm::vec2((tempLR1.x *  cosf(_obj1.rot)) - (tempLR1.y * sinf(_obj1.rot)), (tempLR1.x * sinf(_obj1.rot)) + (tempLR1.y *  cosf(_obj1.rot)));

	//new vertex values after rotation
	UL1 = tempUL1 + center1;
	UR1 = tempUR1 + center1;
	LL1 = tempLL1 + center1;
	LR1 = tempLR1 + center1;

	///////////////////////////////////////////////////

	//get center of RB2
	glm::vec2 center2 = _obj2.pos + (_obj2.size / 2.0f);

	//get vertices of RB before rotation
	glm::vec2 UL2 = _obj2.pos;
	glm::vec2 UR2 = glm::vec2(_obj2.pos.x + _obj2.size.x, _obj2.pos.y);
	glm::vec2 LL2 = glm::vec2(_obj2.pos.x, _obj2.pos.y + _obj2.size.y);
	glm::vec2 LR2 = glm::vec2(_obj2.pos.x + _obj2.size.x, _obj2.pos.y + _obj2.size.y);

	//apply rotation
	glm::vec2 tempUL2 = UL2 - center2;
	glm::vec2 tempUR2 = UR2 - center2;
	glm::vec2 tempLL2 = LL2 - center2;
	glm::vec2 tempLR2 = LR2 - center2;

	tempUL2 = glm::vec2((tempUL2.x *  cosf(_obj2.rot)) - (tempUL2.y * sinf(_obj2.rot)), (tempUL2.x * sinf(_obj2.rot)) + (tempUL2.y *  cosf(_obj2.rot)));
	tempUR2 = glm::vec2((tempUR2.x *  cosf(_obj2.rot)) - (tempUR2.y * sinf(_obj2.rot)), (tempUR2.x * sinf(_obj2.rot)) + (tempUR2.y *  cosf(_obj2.rot)));
	tempLL2 = glm::vec2((tempLL2.x *  cosf(_obj2.rot)) - (tempLL2.y * sinf(_obj2.rot)), (tempLL2.x * sinf(_obj2.rot)) + (tempLL2.y *  cosf(_obj2.rot)));
	tempLR2 = glm::vec2((tempLR2.x *  cosf(_obj2.rot)) - (tempLR2.y * sinf(_obj2.rot)), (tempLR2.x * sinf(_obj2.rot)) + (tempLR2.y *  cosf(_obj2.rot)));

	//new vertex values after rotation
	UL2 = tempUL2 + center2;
	UR2 = tempUR2 + center2;
	LL2 = tempLL2 + center2;
	LR2 = tempLR2 + center2;

	///////////////////////////////////////////////////

	float max1, min1, max2, min2 = 0.0f;
	glm::vec2 axis1 = UR1 - UL1;
	glm::vec2 axis2 = UR1 - LR1;
	glm::vec2 axis3 = UL2 - LL2;
	glm::vec2 axis4 = UL2 - UR2;

	std::vector<glm::vec2> axes;
	axes.push_back(axis1);
	axes.push_back(axis2);
	axes.push_back(axis3);
	axes.push_back(axis4);

	for (int i = 0; i < axes.size(); i++)
	{
		glm::vec2 ULProj1 = Project(UL1, axes[i]);
		glm::vec2 URProj1 = Project(UR1, axes[i]);
		glm::vec2 LLProj1 = Project(LL1, axes[i]);
		glm::vec2 LRProj1 = Project(LR1, axes[i]);
		glm::vec2 ULProj2 = Project(UL2, axes[i]);
		glm::vec2 URProj2 = Project(UR2, axes[i]);
		glm::vec2 LLProj2 = Project(LL2, axes[i]);
		glm::vec2 LRProj2 = Project(LR2, axes[i]);

		GLfloat ULScalar1 = glm::dot(ULProj1, axes[i]);
		GLfloat URScalar1 = glm::dot(URProj1, axes[i]);
		GLfloat LLScalar1 = glm::dot(LLProj1, axes[i]);
		GLfloat LRScalar1 = glm::dot(LRProj1, axes[i]);
		GLfloat ULScalar2 = glm::dot(ULProj2, axes[i]);
		GLfloat URScalar2 = glm::dot(URProj2, axes[i]);
		GLfloat LLScalar2 = glm::dot(LLProj2, axes[i]);
		GLfloat LRScalar2 = glm::dot(LRProj2, axes[i]);

		std::vector<GLfloat> scalars1;
		scalars1.push_back(ULScalar1);
		scalars1.push_back(URScalar1);
		scalars1.push_back(LLScalar1);
		scalars1.push_back(LRScalar1);
		min1 = *std::min_element(scalars1.begin(), scalars1.end());
		max1 = *std::max_element(scalars1.begin(), scalars1.end());

		std::vector<GLfloat> scalars2;
		scalars2.push_back(ULScalar2);
		scalars2.push_back(URScalar2);
		scalars2.push_back(LLScalar2);
		scalars2.push_back(LRScalar2);
		min2 = *std::min_element(scalars2.begin(), scalars2.end());
		max2 = *std::max_element(scalars2.begin(), scalars2.end());

		if (!(min2 <= max1 && max2 >= min1))
		{
			return false;
		}
	}
	
	return true;
}

glm::vec2 Project(const glm::vec2& a, const glm::vec2& b)
{
	return glm::vec2((glm::dot(a, b) / (powf(b.x, 2) + powf(b.y, 2))) * b.x,
					 (glm::dot(a, b) / (powf(b.x, 2) + powf(b.y, 2))) * b.y);
}