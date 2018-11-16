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

SimpleSprites * BulletPool::retrieve()
{
	for (int i = 0; i < pool->size(); i++) {
		if (free->at(i) == false) {
			free->at(i) = true;
			return pool->at(i);
		}
	}
	return NULL;
}

void BulletPool::recycle(SimpleSprites * obj)
{
	auto temp = std::find(pool->begin(), pool->end(), obj);
	free->at(std::distance(pool->begin(), temp)) = false;
}

size_t BulletPool::capacity()
{
	return pool->size();
}
