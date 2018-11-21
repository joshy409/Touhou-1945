#include "raylib.h"
#include "Background.h"
#include "Player.h"
#include "Boss.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = SCREENWIDTH;
	int screenHeight = SCREENHEIGHT;
	srand(time(NULL));
	InitWindow(screenWidth, screenHeight, "Touhou 1945 - Joshua Yang");
	Background background;
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
		
		background.draw();

		boss.draw();
		DrawCircle(boss.collider.center.x, boss.collider.center.y, boss.collider.radius, BLACK);
		player.draw();
		DrawRectangle(player.collider.x, player.collider.y, player.collider.width, player.collider.height, BLACK);
		player.update(boss);
		boss.update(player);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}