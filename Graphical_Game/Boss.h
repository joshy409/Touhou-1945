#pragma once
#include "SimpleSprites.h"
#include "BossPattern1.h"
#include "BossPattern2.h"
#include "BossPattern3.h"
#include "Background.h"
#include "BossBulletPool.h"
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
	bool moveTo(Vector2 dest);
	BossPattern1* ability1 = new BossPattern1();
	BossPattern2* ability2 = new BossPattern2();	
	BossPattern3* ability3 = new BossPattern3();
	std::queue<BossAbilityBase*> AIBrain;
	BossBulletPool* bbpool;
};

