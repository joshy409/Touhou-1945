#pragma once
#include "SimpleSprites.h"
#include "BossAbilityController.h"
#include "Background.h"
#include <queue>


class Player;

class Boss :
	public SimpleSprites
{
public:
	struct Circle {
		Vector2 center;
		float radius;
	};
	Boss();
	~Boss();
	Circle collider;
	int hp;
	void update(Player& player);
	bool isAlive(const int hits);
	
	std::queue<BossAbilityController*> AIBrain;
	BossAbilityController* abilityControl;

};

