#include "Player.h"



Player::Player()
{
	texture = LoadTexture("GameAssets/Ships/player_ship.png");
	pos = Vector2{ (float) SCREENWIDTH / 2 , (float)SCREENHEIGHT - texture.height };
	speed = 4;
	laserL = new SimpleSprites("GameAssets/Lasers/laserGreen10.png");
	laserR = new SimpleSprites("GameAssets/Lasers/laserGreen10.png");
	projectiles = new std::vector<SimpleSprites*>;
}


Player::~Player()
{
}

void Player::action()
{
	if (IsKeyDown(KEY_LEFT)) {
		translate(Vector2{ -speed,0 });
	}  
	if (IsKeyDown(KEY_RIGHT)) {
		translate(Vector2{ speed,0 });
	}
	if (IsKeyDown(KEY_UP)) {
		translate(Vector2{ 0,-speed });
	}  
	if (IsKeyDown(KEY_DOWN)) {
		translate(Vector2{ 0,speed });
	}
	shoot();
	drawProjectiles();
	pos.x = std::clamp((int)pos.x, 0, SCREENWIDTH - texture.width);
	pos.y = std::clamp((int)pos.y, 0, SCREENHEIGHT - texture.height);
}

void Player::shoot() {
	if (IsKeyPressed(KEY_SPACE)) {
		auto temp = laserL->Clone();
		temp->pos = Vector2{ pos.x + 40, pos.y };
		projectiles->push_back(temp);
		temp = laserR->Clone();
		temp->pos = Vector2{ pos.x + texture.width - 50, pos.y };
		projectiles->push_back(temp);
	}
}

//projectile doesn't shoot when I move NW direction
void Player::drawProjectiles() { 
	std::vector<int> removeIndex;
	for (int i = 0; i < projectiles->size(); i++) {
		projectiles->at(i)->translate(Vector2{ 0,-speed });
		DrawTexture(projectiles->at(i)->texture, projectiles->at(i)->pos.x, projectiles->at(i)->pos.y, WHITE);

		if (projectiles->at(i)->pos.y < 0) {  
			removeIndex.push_back(i);
		}
	}

	for (int& i : removeIndex) {
		if (projectiles->size() < 2) {
			projectiles->clear();
			break;
		}
		else {
			projectiles->erase(projectiles->begin() + i);

		}
	}
	removeIndex.clear();
}