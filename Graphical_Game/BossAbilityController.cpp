#include "BossAbilityController.h"
#include "Boss.h"
#include "Player.h"


BossAbilityController::BossAbilityController()
{
	bbpool = new BossBulletPool();
}


BossAbilityController::~BossAbilityController()
{
}

bool BossAbilityController::pattern1(Boss & boss, Player & player, const Vector2 bossDest)
{
	//move to left side shoot 3 rays of bullets toward players location
	//then repeats the process in the middle of the room and right side of the room
	static int delayframe = 0;

	//move boss
	if (boss.moveTo(bossDest)) {
		//fire when boss is at the destination
		if (delayframe > GetFPS() / 4  && std::count(bbpool->free->begin(),bbpool->free->end(), true) < 7) {
			SimpleSprites* temp = bbpool->retrieve();
			if (temp != NULL) {
				setDestination(temp, boss, player);
			}
			delayframe = 0;

		}

	}
	delayframe++;
	return true;

}

void BossAbilityController::setDestination(SimpleSprites * temp, Boss & boss, Player & player)
{
	temp->setPos(boss.pos);
	temp->destination = player.pos;
	temp->travelDistance = Vector2{ player.pos.x - temp->pos.x, player.pos.y - temp->pos.y };
	temp->distance = sqrt(pow((temp->pos.x - player.pos.x), 2) + pow((temp->pos.y - player.pos.y), 2));
}

void BossAbilityController::drawBullets()
{
	for (int i = 0; i < bbpool->free->size(); i++) {
		if (bbpool->free->at(i) == true) {
			bbpool->pool->at(i)->translate(Vector2{ (bbpool->pool->at(i)->travelDistance.x / bbpool->pool->at(i)->distance) * 3,(bbpool->pool->at(i)->travelDistance.y / bbpool->pool->at(i)->distance) *3 });
			bbpool->pool->at(i)->draw();

			if (SimpleSprites::collisionCheck(Background::playArea, bbpool->pool->at(i)->collider)) {
				bbpool->recycle(bbpool->pool->at(i));
			}
		}
	}
}
