#pragma once
#include "SimpleSprites.h"
#include <algorithm>
#include <vector>
class Player :
	public SimpleSprites
{
public:
	Player();
	~Player();
	std::vector<SimpleSprites*> *projectiles;
	SimpleSprites* laserL;
	SimpleSprites* laserR;
	float speed;
	void shoot();
	void action();
	void drawProjectiles();
};

