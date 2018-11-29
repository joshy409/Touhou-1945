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
	Boss();
	~Boss();
	//TODO: Bullet sound
	struct Circle {
		Vector2 center;
		float radius;
	};
	Circle collider;
	void update(Player& player);
	bool isAlive(const int hits);
	bool moveTo(Vector2 dest);
	void hit(Player& player);
	void draw(float scale);
	void reset();
	int getHits();
	BossBulletPool* bbpool;
private:
	BossPattern1* ability1 = new BossPattern1();
	BossPattern2* ability2 = new BossPattern2();
	BossPattern3* ability3 = new BossPattern3();
	BossDeath* death = new BossDeath();
	std::queue<BossAbilityBase*> AIBrain;
	int hp;
	int hits = 0;
	
};

