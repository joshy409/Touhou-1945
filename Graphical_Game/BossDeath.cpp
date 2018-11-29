#include "BossDeath.h"
#include "Boss.h"


BossDeath::BossDeath()
{
}


BossDeath::~BossDeath()
{
}

void BossDeath::update(Boss & boss)
{
	static float i = 1.f;
	if (boss.moveTo(Vector2{ SCREENWIDTH / 2, SCREENHEIGHT / 3 })) {
		
		if (i > 5.f) {
			DrawText("It exploded into thin air....", 400, 500,100, WHITE);
		}
		else {
			boss.pos.x -= boss.texture.width * (1 + i) / boss.texture.width;
			boss.pos.y -= boss.texture.height * (1 + i) / boss.texture.height;
			boss.draw(i);
			i += .01f;
		}
	}
	else {
		boss.draw(i);
	}
}
