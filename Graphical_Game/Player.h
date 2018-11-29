#pragma once
#include "SimpleSprites.h"
#include "BulletPool.h"
#include "Background.h"
#include "PlayerDeath.h"

class Boss;

class Player :
	public SimpleSprites
{
public:
	Player();
	~Player();
	//TODO: Bullet Sound
	BulletPool *bullets;
	PlayerDeath death;
	int hits;
	float speed;
	void shoot();
	void update(Boss& boss);
	void drawBullets();
	void hit(Boss& enemy);
	void reset();
	bool isAlive(const int hits);
};

