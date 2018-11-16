#pragma once
#include "SimpleSprites.h"
#include "BulletPool.h"
#include <algorithm>
#include <vector>
class Player :
	public SimpleSprites
{
public:
	Player();
	~Player();
	BulletPool *bullets;
	std::vector<SimpleSprites*> *projectiles;
	int hits;
	float speed;
	void shoot();
	void action();
	void drawProjectiles();
	void hit(Player enemy);
};

