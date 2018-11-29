#include "Boss.h"

#include "Player.h"

Boss::Boss()
{
	texture = LoadTexture("GameAssets/Boss/parrot.png");
	setPos(Vector2{ SCREENWIDTH / 2,100 });
	collider.center = Vector2{ pos.x + (texture.width / 2),pos.y + (texture.height / 2) };
	collider.radius = texture.width / 2;
	hp = 1;
	AIBrain.push(ability1);
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
		this->draw(1);
		if (AIBrain.front()->pattern(*this, player, bbpool)) {
		} else { 
			AIBrain.pop();
			if (AIBrain.size() < 1) {
				AIBrain.push(ability1);
				AIBrain.push(ability2);
				AIBrain.push(ability3);
			}
		}

		AIBrain.front()->drawBullets(bbpool);
		DrawText(std::to_string(hits).c_str(), 100, 100, 50, WHITE);
		hit(player);
	}
	else {
		//TODO: death animation
		death->update(*this);
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

//when boss's buleet hits the player
void Boss::hit(Player & player)
{
	for (int i = 0; i <  bbpool->free->size(); i++) {
		if (bbpool->free->at(i) == true) {
			if (CheckCollisionRecs(bbpool->pool->at(i)->collider, player.collider)) {
				hits++;
				//player game over
				bbpool->recycle(bbpool->pool->at(i));
			}
		}
	}
}

void Boss::draw(float scale)
{
	DrawTextureEx(texture, pos, 0, scale, WHITE);
}

