#pragma once
#include "BossAbilityBase.h"

class BossPattern2 :
	public BossAbilityBase
{
public:
	BossPattern2();
	~BossPattern2();

	bool pattern(Boss & boss, Player & player, BossBulletPool* bbpool) override;
	void setDestination(SimpleSprites * temp, Boss & boss, int offset) ;
private:
	std::vector<Vector2> bossDest;
};

