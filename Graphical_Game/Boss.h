#pragma once
#include "SimpleSprites.h"
#include "BossPattern1.h"
#include "BossPattern2.h"
#include "BossPattern3.h"
#include "BossDeath.h"
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
	//TODO: Bullet sound
	Circle collider;
	int hp;
	int hits = 0;
	void update(Player& player);
	bool isAlive(const int hits);
	bool moveTo(Vector2 dest);
	void hit(Player& player);
	void draw(float scale);
	BossPattern1* ability1 = new BossPattern1();
	BossPattern2* ability2 = new BossPattern2();	
	BossPattern3* ability3 = new BossPattern3();
	BossDeath* death = new BossDeath();
	std::queue<BossAbilityBase*> AIBrain;
	BossBulletPool* bbpool;
};

