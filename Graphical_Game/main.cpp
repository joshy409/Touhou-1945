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

	InitWindow(screenWidth, screenHeight, "Touhou 1945 - Joshua Yang");
	Background background;
	Player player;
	Player enemy;
	enemy.pos = Vector2{ SCREENWIDTH / 2,100 };
	enemy.collider.x = enemy.pos.x;
	enemy.collider.y = enemy.pos.y;
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
		
		//background.draw();
		enemy.draw();
		DrawRectangle(enemy.collider.x, enemy.collider.y, enemy.collider.width, enemy.collider.height,BLACK);
		DrawText(std::to_string(enemy.collider.x).c_str(), 100, 100, 50, BLACK);
		DrawText(std::to_string(enemy.collider.y).c_str(), 100, 150, 50, BLACK);
		DrawText(std::to_string(enemy.collider.width).c_str(), 100, 200, 50, BLACK);
		DrawText(std::to_string(enemy.collider.height).c_str(), 100, 250, 50, BLACK);
		player.draw();
		player.update();
		player.hit(enemy);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}