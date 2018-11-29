#include "Startscreen.h"
bool Startscreen::play = false;

Startscreen::Startscreen()
{
	texture = LoadTexture("GameAssets/Background/blue_button00.png");
	texture2 = LoadTexture("GameAssets/Background/green_button00.png");
	pos = Vector2{ SCREENWIDTH / 2 - (float) texture.width*3/4, SCREENHEIGHT - 300 };
	collider = { pos.x, pos.y,  texture.width * (float) 1.5,(float)texture.height * (float) 1.5 };
}


Startscreen::~Startscreen()
{
}


void Startscreen::update()
{
	//Title
	DrawText("Touhou", SCREENWIDTH / 3, SCREENHEIGHT - 500, 200, WHITE);
	DrawText("1945", SCREENWIDTH / 3, SCREENHEIGHT - 300, 200, WHITE);

	//button
	DrawTextureEx(texture, pos, 0, 1.5, WHITE);
	DrawText("PLAY", pos.x + 50, pos.y+5, 50, WHITE);

	//change the button color to green if the mouse cursor is being hovered over
	if (CheckCollisionPointRec(GetMousePosition(), collider)) {
		DrawTextureEx(texture2, pos, 0, 1.5, WHITE);
		DrawText("PLAY", pos.x+50, pos.y+5, 50, WHITE);
	}

	//check for mouse click on the button
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), collider)) {
		play = true;
	}
}


