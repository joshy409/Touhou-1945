#include "raylib.h"
#include "SimpleSprites.h"
#include "Background.h"
#include "PlayerController.h"
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = SCREENWIDTH;
	int screenHeight = SCREENHEIGHT;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	Background background;
	PlayerController player;
	SetTargetFPS(120);
	//--------------------------------------------------------------------------------------

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
		player.draw();
		player.action();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}