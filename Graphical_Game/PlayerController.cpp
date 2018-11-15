#include "PlayerController.h"



PlayerController::PlayerController() : Player()
{

}

void PlayerController::action()
{
	if (IsKeyDown(KEY_LEFT)) {
		translate(Vector2{ -3,0 });
	} else if (IsKeyDown(KEY_RIGHT)) {
		translate(Vector2{ 3,0 });
	}
	if (IsKeyDown(KEY_UP)) {
		translate(Vector2{ 0,-3 });
	} else if (IsKeyDown(KEY_DOWN)) {
		translate(Vector2{ 0,3 });
	}

	if (IsKeyDown(KEY_SPACE)) {
		//fire 2 lasers every on cooldown
	}
}


