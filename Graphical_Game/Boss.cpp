#include "Boss.h"

#include "Player.h"

Boss::Boss()
{
	texture = LoadTexture("GameAssets/Boss/parrot.png");
	setPos(Vector2{ SCREENWIDTH / 2,100 });
	collider.center = Vector2{ pos.x + (texture.width / 2),pos.y + (texture.height / 2) };
	collider.radius = texture.width / 2;
	hp = 10;
	abilityControl = new BossAbilityController();
	AIBrain.push(abilityControl);
	AIBrain.push(abilityControl);
	AIBrain.push(abilityControl);
}


Boss::~Boss()
{
}

void Boss::update(Player& player)
{
	if (isAlive(player.hits)) {
		if (abilityControl->pattern1(*this, player, Vector2{ SCREENWIDTH / 4, 100 })) {
			
		} else { 
			abilityControl->pattern1(*this, player, Vector2{ 1500, 100 });
		}

		//if (!(AIBrain.front()->pattern1(*this, player, Vector2{ SCREENWIDTH / 4, 100 }))) {
			//AIBrain.pop();
		//}


		abilityControl->drawBullets();
	}
	else {
		DrawText("yay", SCREENWIDTH / 2, SCREENHEIGHT / 2, 100, WHITE);
	}
}

bool Boss::isAlive(const int hits)
{
	return hits < hp;
}



