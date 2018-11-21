#pragma once
#include "ObjectPool.h"
class BossBulletPool :
	public ObjectPool
{
public:
	BossBulletPool();
	~BossBulletPool();
	struct Circle {
		Vector2 center;
		float radius;
	};
	SimpleSprites* bullets;
	Circle collider;
};

