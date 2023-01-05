#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER

#include "myGameObject.h"

void myGameObject::Update()
{
}


void myGameObject::Init(std::string spriteName, Vector2f startPos, Vector2f startScale)
{

}

int myGameObject::CreateMyGameObject(int type, Point2f newPos, const char* spriteName)
{

	return Play::CreateGameObject(type, newPos, 0, spriteName);
}
void myGameObject::SetPosition(Point2f newPosition)
{
	GameObject& obj_player = Play::GetGameObject(objectID);
	obj_player.pos = newPosition;
}



void myGameObject::SetVelocity(Point2f newVelocity)
{
	GameObject& obj_player = Play::GetGameObject(objectID);
	obj_player.velocity = newVelocity;
}

void myGameObject::SetAcceleration(Point2f newAcceleration)
{
	GameObject& obj_player = Play::GetGameObject(objectID);
	obj_player.acceleration = newAcceleration;
}

Point2f myGameObject::GetVelocity()
{
	GameObject& obj_player = Play::GetGameObject(objectID);

	return obj_player.velocity;
}

Point2f myGameObject::GetAcceleration()
{
	GameObject& obj_player = Play::GetGameObject(objectID);

	return obj_player.acceleration;
}

Vector2f myGameObject::GetPosition()
{
	GameObject& obj_player = Play::GetGameObject(objectID);
	return obj_player.pos;
}

void myGameObject::Draw()
{
	GameObject& obj_player = Play::GetGameObject(objectID);
	Play::UpdateGameObject(obj_player);
	Play::DrawObjectRotated(obj_player);
}

bool myGameObject::IsLeavingPlayArea()
{
	GameObject& obj_player = Play::GetGameObject(objectID);

	if (Play::IsLeavingDisplayArea(obj_player))
	{
		obj_player.pos = obj_player.oldPos;
		return true;
	}
	else	return false;
}

bool myGameObject::CheckOverlap(myGameObject otherObject)
{
	PlayGraphics& pblt = PlayGraphics::Instance();

	int objBounds[] = {0,0, rectScale.x, rectScale.y};
	int otherobjBounds[] = {0,0, otherObject.rectScale.x, otherObject.rectScale.y};

	GameObject& obj_player1 = Play::GetGameObject(objectID);
	GameObject& obj_player2 = Play::GetGameObject(otherObject.objectID);


	

	return pblt.SpriteCollide(obj_player1.spriteId, obj_player1.pos, 0, 0, objBounds, obj_player2.spriteId, obj_player2.pos, 0, 0, otherobjBounds);



	







	/*Vector2f	topLeftPos = GetPosition();
	Vector2f	bottomRightPos = topLeftPos + rectScale;

	Vector2f	otherTopLeftPos = otherObject.GetPosition();
	Vector2f	otherBottomRightPos = otherTopLeftPos + otherObject.rectScale;

	bool xOverlap = bottomRightPos.x > otherTopLeftPos.x && otherBottomRightPos.x > topLeftPos.x;
	bool yOverlap = bottomRightPos.y > otherTopLeftPos.y && otherBottomRightPos.y > topLeftPos.y;

	if (xOverlap && yOverlap) 		return true;
	return false;*/
}


