#pragma once
#include "ObjectPool.h"
class BossBulletPool :
	public ObjectPool
{
public:
	BossBulletPool();
	~BossBulletPool();

	SimpleSprites* bullets;

};

