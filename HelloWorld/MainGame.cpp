//#define PLAY_IMPLEMENTATION
//#define PLAY_USING_GAMEOBJECT_MANAGER




#include "MyPlayer.h"
#include "Ball.h"
#include "Statics.h"


MyPlayer player = MyPlayer();
Ball ball = Ball();





// The entry point for a PlayBuffer program
void MainGameEntry(PLAY_IGNORE_COMMAND_LINE)
{
	Play::CreateManager(Statics::DISPLAY_WIDTH, Statics::DISPLAY_HEIGHT, Statics::DISPLAY_SCALE);

	float ScreenCentreX = Statics::DISPLAY_WIDTH * 0.5f;
	float ScreenCentreY = Statics::DISPLAY_HEIGHT * 0.5f;

	player.Init("paddle", { ScreenCentreX, Statics::DISPLAY_HEIGHT * 0.8f }, { 160, 20 });
	ball.Init("ball", { ScreenCentreX, ScreenCentreY }, { 25.0f, 25.0f });



}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate(float elapsedTime)
{
	Play::ClearDrawingBuffer(Play::cBlack);

	player.Update();
	ball.Update();


	Vector2f	topLeftBallPos = ball.GetPosition();
	Vector2f	bottomRightBallPos = topLeftBallPos + ball.rectScale;
	Vector2f	topLeftPlayerPos = player.GetPosition();
	Vector2f	bottomRightPlayerPos = topLeftPlayerPos + player.rectScale;



	bool xCollision = bottomRightBallPos.x > topLeftPlayerPos.x && bottomRightPlayerPos.x > topLeftBallPos.x;
	bool yCollision = bottomRightBallPos.y > topLeftPlayerPos.y && bottomRightPlayerPos.y > topLeftBallPos.y;

	if (xCollision && yCollision)
	{
		ball.BounceY();
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

