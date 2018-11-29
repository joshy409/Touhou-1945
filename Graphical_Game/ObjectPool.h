#pragma once
#include "SimpleSprites.h"
#include <algorithm>
#include <vector>

class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();

	std::vector<SimpleSprites*> *pool;
	std::vector<bool> *free;

	SimpleSprites* retrieve();
	void recycle(const SimpleSprites* obj);

	size_t capacity();

	void reset();
};

