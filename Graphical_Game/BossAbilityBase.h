#pragma once
#include "SimpleSprites.h"
#include "BossBulletPool.h"
#include <algorithm>
#include <vector>
#include <functional>
class Player;
class Boss;

class BossAbilityBase
{
public:
	BossAbilityBase();
	~BossAbilityBase();

	virtual bool pattern(Boss & boss, Player & player, BossBulletPool* bbpool) { return true; };
	void drawBullets(BossBulletPool* bbpool);

};

