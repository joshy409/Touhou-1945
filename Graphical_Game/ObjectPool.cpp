#include "ObjectPool.h"



ObjectPool::ObjectPool()
{
}


ObjectPool::~ObjectPool()
{
}


SimpleSprites * ObjectPool::retrieve()
{
	for (int i = 0; i < pool->size(); i++) {
		if (free->at(i) == false) {
			free->at(i) = true;
			return pool->at(i);
		}
	}
	return NULL;
}

void ObjectPool::recycle(const SimpleSprites * obj)
{
	auto temp = std::find(pool->begin(), pool->end(), obj);
	free->at(std::distance(pool->begin(), temp)) = false;
}

size_t ObjectPool::capacity()
{
	return pool->size();
}