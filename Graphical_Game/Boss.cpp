#include "Boss.h"

#include "Player.h"

Boss::Boss()
{
	texture = LoadTexture("GameAssets/Boss/parrot.png");
	setPos(Vector2{ SCREENWIDTH / 2,100 });
	collider.center = Vector2{ pos.x + (texture.width / 2),pos.y + (texture.height / 2) };
	collider.radius = texture.width / 2;
	hp = 100;
	//AIBrain.push(ability1);
	AIBrain.push(ability2);
	AIBrain.push(ability3);
	bbpool = new BossBulletPool();

}


Boss::~Boss()
{
}

void Boss::update(Player& player)
{
	if (isAlive(player.hits)) {
		if (AIBrain.front()->pattern(*this, player, bbpool)) {

		} else { 
			AIBrain.pop();
		}

		AIBrain.front()->drawBullets(bbpool);
	}
	else {
		DrawText("yay", SCREENWIDTH / 2, SCREENHEIGHT / 2, 100, WHITE);
	}
}

bool Boss::isAlive(const int hits)
{
	return hits < hp;
}



bool Boss::moveTo(Vector2 dest)
{
	if (abs(dest.x - pos.x) <= 5 && abs(dest.y - pos.y) <= 5) {
		return true;
	}
	else {
		travelDistance.x = dest.x - pos.x;
		travelDistance.y = dest.y - pos.y;
		distance = sqrt(pow((pos.x - dest.x), 2) + pow((pos.y - dest.y), 2));
		pos.x += travelDistance.x / distance * 5;
		pos.y += travelDistance.y / distance * 5;
		collider.center.x += travelDistance.x / distance * 5;
		collider.center.y += travelDistance.y / distance * 5;
		return false;
	}
}