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
	//static variable for scale
	static float i = 1.f;

	if (boss.moveTo(Vector2{ SCREENWIDTH / 2, SCREENHEIGHT / 3 })) {
		if (i > 7.5f) {
			Startscreen::play = false;
			i = 1;
		}
		else if (i > 5.f) {
			DrawText("It exploded into thin air....", 250, 400,100, WHITE);
			i += .01f;
		}
		else if (i > 3.5f) {
			DrawText("AHHHHHH!!!!!!!!!!!", 750+(i*10), 200, 100, WHITE);
			draw(boss, i);
		}
		else if (i > 2.5f) {
			DrawText("Make it STOP!", 725+ (i * 10), 200, 100, WHITE);
			draw(boss, i);
		}
		else if (i > 1.5f) {
			DrawText("What is happening?", 550+ (i * 10), 200, 100, WHITE);
			draw(boss, i);
		}
		
		else {
			draw(boss, i);
		}
	}
	else {
		boss.draw(i);
	}
}

//draw the boss so it shakes as it grows
void BossDeath::draw(Boss & boss, float &i)
{
	boss.pos.x -= boss.texture.width * (1 + i) / boss.texture.width;
	boss.pos.y -= boss.texture.height * (1 + i) / boss.texture.height;
	boss.draw(i);
	i += .01f;
}
