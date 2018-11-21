#include "BossPattern3.h"
#include "Boss.h"
#include "Player.h"


BossPattern3::BossPattern3()
{
	bossDest.push_back(Vector2{ SCREENWIDTH/2, SCREENHEIGHT/3 });
	
}


BossPattern3::~BossPattern3()
{
}

bool BossPattern3::pattern(Boss & boss, Player & player, BossBulletPool* bbpool)
{
	//move to left side shoot 3 rays of bullets toward players location
	//then repeats the process in the middle of the room and right side of the room
	static int delayframe = 0;
	static int bullet = 0;
	static int destIndex = 0;
	bool finish = true;

	//move boss
	if (boss.moveTo(bossDest[destIndex])) {
		//fire when boss is at the destination
		if (delayframe > GetFPS() / 5) {
			SimpleSprites* temp = bbpool->retrieve();
			bullet++;
			if (temp != NULL) {
				setDestination(temp, boss);
			}
			SimpleSprites* temp1 = bbpool->retrieve();
			bullet++;
			if (temp != NULL) {
				setDestination(temp1, boss);
			}
			delayframe = 0;

		}

		if (bullet > 99) {
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

void BossPattern3::setDestination(SimpleSprites * temp, Boss & boss)
{
	temp->setPos(boss.pos);
	temp->travelDistance = Vector2{ (float)(rand() % 1000+400)  - temp->pos.x, (float)(rand() % 500+500) - temp->pos.y };
	temp->distance = sqrt(pow((temp->pos.x - (float)(rand() % 1000+400)), 2) + pow((temp->pos.y - (float)(rand() % 500+500)), 2));
}
