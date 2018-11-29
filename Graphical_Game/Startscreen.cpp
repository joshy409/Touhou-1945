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
	DrawText("Touhou", SCREENWIDTH / 2, SCREENHEIGHT - 600, 100, WHITE);
	DrawText("1945", SCREENWIDTH / 2, SCREENHEIGHT - 500, 100, WHITE);
	DrawTextureEx(texture, pos, 0, 1.5, WHITE);
	DrawText("PLAY", pos.x, pos.y, 35, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), collider)) {
		DrawTextureEx(texture2, pos, 0, 1.5, WHITE);
		DrawText("PLAY", pos.x, pos.y, 35, WHITE);
	}
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), collider)) {
		play = true;
	}
}


