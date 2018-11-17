#include "BulletPool.h"



BulletPool::BulletPool()
{
	laserL = new SimpleSprites("GameAssets/Lasers/laserGreen10.png");
	laserR = new SimpleSprites("GameAssets/Lasers/laserGreen10.png");
	pool = new std::vector<SimpleSprites*>;
	free = new std::vector<bool>;

	for (int i = 0; i < 20; i++) {
		auto temp = laserL->Clone();
		pool->push_back(temp);
		temp = laserR->Clone();
		pool->push_back(temp);
		free->push_back(false);
		free->push_back(false);
	}
}


BulletPool::~BulletPool()
{
}


