#include "raylib.h"
#include "Background.h"
#include "Player.h"
#include "Boss.h"
#include "Startscreen.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = SCREENWIDTH;
	int screenHeight = SCREENHEIGHT;
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "Touhou 1945 - Joshua Yang");
	Background background;
	Startscreen startscreen;
	Player player;
	Boss boss;
	SetTargetFPS(120);
	//--------------------------------------------------------------------------------------
	
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
	
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		//TODO: BGM
		background.draw();
		//if it is on start screen wait for the button press
		if (!Startscreen::play) {
			startscreen.update();
			boss.reset();
			player.reset();
		}
		//play the game
		else {
			player.update(boss);
			boss.update(player);
			//DrawCircle(boss.collider.center.x, boss.collider.center.y, boss.collider.radius, BLACK);
			//DrawRectangle(player.collider.x, player.collider.y, player.collider.width, player.collider.height, BLACK);
		}
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}