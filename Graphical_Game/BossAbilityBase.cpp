#include "BossAbilityBase.h"
#include "Boss.h"
#include "Player.h"


BossAbilityBase::BossAbilityBase()
{
}


BossAbilityBase::~BossAbilityBase()
{
}



void BossAbilityBase::drawBullets(BossBulletPool* bbpool)
{
	for (int i = 0; i < bbpool->free->size(); i++) {
		if (bbpool->free->at(i) == true) {
			bbpool->pool->at(i)->translate(Vector2{ (bbpool->pool->at(i)->travelDistance.x / bbpool->pool->at(i)->distance) * 4,(bbpool->pool->at(i)->travelDistance.y / bbpool->pool->at(i)->distance) *4 });
			bbpool->pool->at(i)->draw();
			DrawRectangle(bbpool->pool->at(i)->collider.x, bbpool->pool->at(i)->collider.y, bbpool->pool->at(i)->collider.width, bbpool->pool->at(i)->collider.height, BLACK);
			if (SimpleSprites::collisionCheck(Background::playArea, bbpool->pool->at(i)->collider)) {
				bbpool->recycle(bbpool->pool->at(i));
			}
		}
	}
}
