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
	int i = 0;
	
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);
		//TODO: BGM
		background.draw();
		if (!Startscreen::play) {
			startscreen.update();
		}
		else {
			//DrawCircle(boss.collider.center.x, boss.collider.center.y, boss.collider.radius, BLACK);

			//DrawRectangle(player.collider.x, player.collider.y, player.collider.width, player.collider.height, BLACK);
			player.update(boss);
			boss.update(player);
		}

		//TODO: End Screen and win screen
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}