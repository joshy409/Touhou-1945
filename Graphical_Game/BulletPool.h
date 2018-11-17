#pragma once
#include "SimpleSprites.h"
#include "ObjectPool.h"
#include <algorithm>
#include <vector>

class BulletPool : public ObjectPool
{
public:
	BulletPool();
	~BulletPool();

	SimpleSprites* laserL;
	SimpleSprites* laserR;
     
};

