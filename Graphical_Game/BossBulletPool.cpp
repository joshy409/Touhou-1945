#include "BossBulletPool.h"



BossBulletPool::BossBulletPool()
{
	bullets = new SimpleSprites("GameAssets/Boss/tank_explosion2.png");
	pool = new std::vector<SimpleSprites*>;
	free = new std::vector<bool>;
	for (int i = 0; i < 100; i++) {
		auto temp = bullets->Clone();
		pool->push_back(temp);
		free->push_back(false);
	}
}


BossBulletPool::~BossBulletPool()
{
}
