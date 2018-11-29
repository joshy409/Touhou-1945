#pragma once
#include "BossAbilityBase.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class BossPattern1 :
	public BossAbilityBase
{
public:
	BossPattern1();
	~BossPattern1();

	bool pattern(Boss & boss, Player & player, BossBulletPool* bbpool) override;
	void setDestination(SimpleSprites * temp, Boss & boss, Player & player);
private:
	std::vector<Vector2> bossDest;
};

