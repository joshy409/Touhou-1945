#include "Background.h"



Background::Background()
{
	texture = LoadTexture("GameAssets/Background/space.png");
	pos = Vector2{ 0, };
}

void Background::draw()
{
	DrawTextureEx(texture, pos, 0, 1.5, WHITE);
}



