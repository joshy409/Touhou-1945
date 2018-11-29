#include "BossPattern2.h"
#include "Boss.h"
#include "Player.h"

BossPattern2::BossPattern2()
{
	bossDest.push_back(Vector2{ 360 * 1, 100 });
	bossDest.push_back(Vector2{ 360 * 2, 100 });
	bossDest.push_back(Vector2{ 360 * 3, 100 });
	bossDest.push_back(Vector2{ 360 * 4, 100 });
}


BossPattern2::~BossPattern2()
{
}


bool BossPattern2::pattern(Boss & boss, Player & player, BossBulletPool* bbpool)
{
	//move to left side shoot 3 rays of bullets toward players location
	//then repeats the process 5 times starting at the left and moving right
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
				setDestination(temp, boss, 0);
			}
			SimpleSprites* temp1 = bbpool->retrieve();
			bullet++;
			if (temp != NULL) {
				setDestination(temp1, boss, 100);
			}
			SimpleSprites* temp2 = bbpool->retrieve();
			bullet++;
			if (temp != NULL) {
				setDestination(temp2, boss,-100);
			}
			delayframe = 0;

		}

		if (bullet > 15) {
			destIndex++;
			if (destIndex > bossDest.size() - 1) {
				destIndex = 0;
				finish = false;
			}
			bullet = 0;
		}
	}

	delayframe++;
	return finish;

}

void BossPattern2::setDestination(SimpleSprites * temp, Boss & boss, int offset)
{
	temp->setPos(boss.pos);
	temp->travelDistance = Vector2{ (boss.pos.x + offset) - temp->pos.x, (boss.pos.y+1000) - temp->pos.y };
	temp->distance = sqrt(pow((temp->pos.x - (boss.pos.x+offset)), 2) + pow((temp->pos.y - (boss.pos.y+1000)), 2));
}