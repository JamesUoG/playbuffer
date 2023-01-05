
#include "Ball.h"
#include "Statics.h"

#include <iostream>


void Ball::Update()
{
	Vector2f position = GetPosition();

	if (position.x <= 0 || position.x + rectScale.x >= Statics::DISPLAY_WIDTH) 		BounceX();
	if (position.y <= 0) 		BounceY();
	if (position.y >= Statics::DISPLAY_HEIGHT)
	{
		SetVelocity({ 1.0f,-1.0f });
		SetPosition({ Statics::DISPLAY_WIDTH * 0.5f, Statics::DISPLAY_HEIGHT * 0.5f });
	}


	Draw();


}

void Ball::Init(std::string spriteName, Vector2f startPos, Vector2f startScale)
{
	objectID = CreateMyGameObject(0, startPos, spriteName.c_str());
	rectScale = startScale;

	SetVelocity({ 1.0f,-1.0f });
}

void Ball::CheckBounce(myGameObject otherObject)
{
	if (CheckOverlap(otherObject))
	{
		Vector2f otherPos = otherObject.GetPosition();
		Vector2f thisPos = GetPosition();
		Vector2f difference = otherPos - thisPos;
		if (std::abs( difference.y ) < std::abs(difference.x))
		{
			BounceY();
		}
		else {
			BounceX();
		}
	}

}

void Ball::BounceX()
{
	Vector2f velocity = GetVelocity();
	velocity.x = velocity.x * -1.0f;
	SetVelocity(velocity);
}

void Ball::BounceY()
{
	Vector2f velocity = GetVelocity();
	velocity.y = velocity.y * -1.0f;
	SetVelocity(velocity);
}

Ball::Ball()
{
}

Ball::~Ball()
{
}