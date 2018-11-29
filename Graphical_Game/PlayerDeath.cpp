#include "PlayerDeath.h"

#include "Player.h"


PlayerDeath::PlayerDeath()
{
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion00.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion01.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion02.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion03.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion04.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion05.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion06.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion07.png"));
	explosions.emplace_back(new SimpleSprites("GameAssets/Explosion/explosion08.png"));
}


PlayerDeath::~PlayerDeath()
{
}

void PlayerDeath::update(Player & player)
{
	//delay variable
	static int wait = 0;

	DrawText("Game Over", 400, 350, 200, WHITE);

	for (int i = 0; i < explosions.size(); i++) {
		DrawTextureEx(explosions[i]->texture, player.pos, 0, .3, WHITE);
	}
	wait++;

	if (wait > 350) {
		wait = 0;
		Startscreen::play = false;
	}
}
