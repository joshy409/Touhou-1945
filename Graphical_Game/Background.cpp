#include "Background.h"

std::vector<Rectangle> Background::playArea;

Background::Background()
{
	texture = LoadTexture("GameAssets/Background/space.png");
	pos = Vector2{ 0, 0};
	playArea.push_back(Rectangle{ 0, 0, SCREENWIDTH, 1 });
	playArea.push_back(Rectangle{ 0, SCREENHEIGHT, SCREENWIDTH, 1 });
	playArea.push_back(Rectangle{ 0, 0, 1, SCREENHEIGHT });
	playArea.push_back(Rectangle{ SCREENWIDTH, 0, 1, SCREENHEIGHT });
}

void Background::draw()
{
	DrawTextureEx(texture, pos, 0, 1.5, WHITE);
}



