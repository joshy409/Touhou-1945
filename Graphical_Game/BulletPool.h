#pragma once
#include "SimpleSprites.h"
#include <algorithm>
#include <vector>

class BulletPool
{
public:
	BulletPool();
	~BulletPool();

	SimpleSprites* laserL;
	SimpleSprites* laserR;

	std::vector<SimpleSprites*> *pool;                            
	std::vector<bool> *free;

	SimpleSprites* retrieve();                     
	void recycle(SimpleSprites* obj);              

	size_t capacity();                  
};

