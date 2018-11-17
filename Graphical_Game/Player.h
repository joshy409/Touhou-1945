#pragma once
#include "SimpleSprites.h"
#include "BulletPool.h"
#include "Background.h"

class Boss;

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
	void update(Boss& boss);
	void drawBullets();
	void hit(Boss& enemy);
};

