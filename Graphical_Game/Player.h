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
	PlayerDeath death;
	int getHits();
	void update(Boss& boss);
	void drawBullets();
	void reset();
	bool isAlive(const int hits);
private:
	int hits;
	void hit(Boss& enemy);
	void shoot();
	float speed;
	BulletPool *bullets;
};

