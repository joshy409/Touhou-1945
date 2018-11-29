#include "BossPattern1.h"
#include "Boss.h"
#include "Player.h"


BossPattern1::BossPattern1()
{
	
	bossDest.push_back(Vector2{ (float)(rand() % 1600 + 100), (float)(rand() % 400) });
	bossDest.push_back(Vector2{ (float)(rand() % 1600 + 100),(float)(rand() % 400) });
	bossDest.push_back(Vector2{ (float)(rand() % 1600 + 100),(float)(rand() % 400) });
}


BossPattern1::~BossPattern1()
{
}

bool BossPattern1::pattern(Boss & boss, Player & player, BossBulletPool* bbpool)
{
	//selects a random spot, moves there and shoots 6 bullets at the players positon
	//repeat 3 times
	static int delayframe = 0;
	static int bullet = 0;
	static int destIndex = 0;
	bool finish = true;

	//move boss
	if (boss.moveTo(bossDest[destIndex])) {
		//fire when boss is at the destination
		if (delayframe > GetFPS() / 4) {
			SimpleSprites* temp = bbpool->retrieve();
			bullet++;
			if (temp != NULL) {
				setDestination(temp, boss, player);
			}
			delayframe = 0;

		}
	
		if (bullet > 5) {
			destIndex++;
			if (destIndex > bossDest.size()-1) {
				destIndex = 0;
				finish = false;
			}
			bullet = 0;
		}
	}

	delayframe++;
	return finish;

}

void BossPattern1::setDestination(SimpleSprites * temp, Boss & boss, Player & player)
{
	temp->setPos(boss.pos);
	temp->travelDistance = Vector2{ player.pos.x - temp->pos.x, player.pos.y - temp->pos.y };
	temp->distance = sqrt(pow((temp->pos.x - player.pos.x), 2) + pow((temp->pos.y - player.pos.y), 2));
}