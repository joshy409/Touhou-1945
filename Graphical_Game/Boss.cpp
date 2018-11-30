#include "Boss.h"
#include "Player.h"

Boss::Boss()
{
	texture = LoadTexture("GameAssets/Boss/parrot.png");
	setPos(Vector2{ SCREENWIDTH / 2,100 });
	collider.center = Vector2{ pos.x + (texture.width / 2),pos.y + (texture.height / 2) };
	collider.radius = texture.width / 2;
	hp = 50;
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
	//if boss is alive
	if (isAlive(player.getHits())) {
		this->draw(1);
		//run boss pattern in order of AIBrain
		if (AIBrain.front()->pattern(*this, player, bbpool)) {
		} else { 
			//when the pattern is done pop it off
			AIBrain.pop();
			//if all 3 patterns are done and boss is still alive push 3 patterns
			if (AIBrain.size() < 1) {
				AIBrain.push(ability1);
				AIBrain.push(ability2);
				AIBrain.push(ability3);
			}
		}

		AIBrain.front()->drawBullets(bbpool);
		//DrawText(std::to_string(hits).c_str(), 100, 100, 50, WHITE);
		hit(player);
	}
	else {
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

//when boss's bullet hits the player
void Boss::hit(Player & player)
{
	for (int i = 0; i <  bbpool->free->size(); i++) {
		if (bbpool->free->at(i) == true) {
			if (CheckCollisionRecs(bbpool->pool->at(i)->collider, player.collider)) {
				hits++;
				bbpool->recycle(bbpool->pool->at(i));
			}
		}
	}
}

void Boss::draw(float scale)
{
	DrawTextureEx(texture, pos, 0, scale, WHITE);
}

void Boss::reset()
{
	setPos(Vector2{ SCREENWIDTH / 2,100 });
	collider.center = Vector2{pos.x + (texture.width / 2),pos.y + (texture.height / 2) };
	collider.radius = texture.width / 2;
	bbpool->reset();
	hits = 0;
	
}

int Boss::getHits()
{
	return hits;
}

