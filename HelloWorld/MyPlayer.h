#pragma once
#include "myGameObject.h"

class MyPlayer : public myGameObject
{

public:
	void Update();
	void Init(std::string spriteName, Vector2f startPos, Vector2f startScale);

	MyPlayer();
	~MyPlayer();
	void HandlePlayerControls();


};

