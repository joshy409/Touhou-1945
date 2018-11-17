#pragma once
#include "SimpleSprites.h"
#include "BossBulletPool.h"
#include <algorithm>
#include <vector>
#include <functional>
class Player;
class Boss;

class BossAbilityController
{
public:
	BossAbilityController();
	~BossAbilityController();

	BossBulletPool* bbpool;
	bool pattern1(Boss & boss, Player & player, Vector2 bossDest);
	void setDestination(SimpleSprites * temp, Boss & boss, Player & player);
	void drawBullets();

};

