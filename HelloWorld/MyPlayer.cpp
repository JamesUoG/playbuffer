
#include "MyPlayer.h"





MyPlayer::MyPlayer()
{


}

MyPlayer::~MyPlayer()
{
}

void MyPlayer::HandlePlayerControls()
{


	if (Play::KeyDown(VK_LEFT))
	{
		SetAcceleration({ -1, 0 });
	}
	else if (Play::KeyDown(VK_RIGHT))
	{
		SetAcceleration({ 1, 0 });
	}
	else
	{
		Vector2f velocity = GetVelocity();
		if (velocity.x != 0  || velocity.y != 0) SetVelocity(velocity * 0.9f);
		SetAcceleration({ 0, 0 });

	}
}



void MyPlayer::Update()
{
	
	HandlePlayerControls();
	if (IsLeavingPlayArea())
	{
		Vector2f velocity = GetVelocity();
		SetVelocity(velocity * - 0.5f);
		SetAcceleration({ 0.0f, 0.0f });


	}
	Draw();
}

void MyPlayer::Init(std::string spriteName, Vector2f startPos, Vector2f startScale)
{
	objectID = CreateMyGameObject(0, startPos, spriteName.c_str());
	rectScale = startScale;
}


