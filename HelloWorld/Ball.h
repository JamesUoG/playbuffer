#pragma once

#include "myGameObject.h"

class Ball :
    public myGameObject
{
public:

	void Update();
	void Init(std::string spriteName, Vector2f startPos, Vector2f startScale);

	void BounceX();
	void BounceY();
	Ball();
	~Ball();
};

