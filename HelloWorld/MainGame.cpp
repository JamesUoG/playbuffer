//#define PLAY_IMPLEMENTATION
//#define PLAY_USING_GAMEOBJECT_MANAGER




#include "MyPlayer.h"
#include "Ball.h"
#include "Statics.h"


#include <iostream>
//#include <iterator>



std::list<myGameObject*> myGameObjects;
MyPlayer player = MyPlayer();

Ball ball = Ball();

//myGameObject walls[] = new myGameObject[]; // {myGameObject(), myGameObject() , myGameObject() , myGameObject() , myGameObject() };

// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(Statics::DISPLAY_WIDTH, Statics::DISPLAY_HEIGHT, Statics::DISPLAY_SCALE);

	float ScreenCentreX = Statics::DISPLAY_WIDTH * 0.5f;
	float ScreenCentreY = Statics::DISPLAY_HEIGHT * 0.5f;

	player.Init("paddle", { ScreenCentreX, Statics::DISPLAY_HEIGHT * 0.8f }, { 160, 20 });
	ball.Init("ball", { ScreenCentreX, ScreenCentreY }, { 25.0f, 25.0f });

	myGameObjects.push_back(&player );
	myGameObjects.push_back(&ball );

	//for (myGameObject x : walls)
	//{
	//	x.Init("ball", { 0, 0}, { 25.0f, 25.0f });

	//	myGameObjects.push_back(&x);

	//}

}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	Play::ClearDrawingBuffer(Play::cBlack);


	for (myGameObject* x : myGameObjects) 
	{
		x->Update();

		if (x != &ball) 			ball.CheckBounce(*x);

	}

	Play::PresentDrawingBuffer();
	return Play::KeyDown(VK_ESCAPE);
}

// Gets called once when the player quits the game 
int MainGameExit(void)
{
	Play::DestroyManager();
	return PLAY_OK;
}

