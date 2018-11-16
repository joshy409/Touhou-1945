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
	int hits;
	float speed;
	void shoot();
	void update();
	void drawBullets();
	void hit(Player enemy);
};

