#pragma once


#include <string>
#include "Play.h"	

class myGameObject
{
public:
	int objectID = 0;

	Vector2f rectScale;


	myGameObject()
	{	}
	~myGameObject() 
	{	}
	virtual void Update();
	virtual void Init(std::string spriteName, Vector2f startPos, Vector2f startScale);

	int CreateMyGameObject(int type, Point2f newPos, const char *spriteName);

	void SetVelocity(Point2f newVelocity);
	void SetPosition(Point2f newVelocity);
	void SetAcceleration(Point2f newAcceleration);


	
	Vector2f GetVelocity();
	Vector2f GetAcceleration();
	Vector2f GetPosition();

	void Draw();

	bool CheckOverlap(myGameObject otherObject);

	bool IsLeavingPlayArea();



};

