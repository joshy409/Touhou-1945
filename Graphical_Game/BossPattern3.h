#pragma once
#include "BossAbilityBase.h"
class BossPattern3 :
	public BossAbilityBase
{
public:
	BossPattern3();
	~BossPattern3();

	bool pattern(Boss & boss, Player & player, BossBulletPool* bbpool) override;
	void setDestination(SimpleSprites * temp, Boss & boss);
private:
	std::vector<Vector2> bossDest;
};

