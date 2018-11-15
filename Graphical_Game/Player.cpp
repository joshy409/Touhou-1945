#include "Player.h"



Player::Player()
{
	texture = LoadTexture("GameAssets/Ships/player_ship.png");
	pos = Vector2{ (float) SCREENWIDTH / 2 , (float)SCREENHEIGHT - texture.height };
}


Player::~Player()
{
}
