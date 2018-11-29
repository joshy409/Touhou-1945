#include "Player.h"

#include "Boss.h"

Player::Player() : SimpleSprites("GameAssets/Ships/player_ship.png")
{
	texture = LoadTexture("GameAssets/Ships/player_ship.png");
	setPos (Vector2{ (float) SCREENWIDTH / 2 , (float)SCREENHEIGHT - texture.height });
	collider = Rectangle{ pos.x +70, pos.y +45,30,55 };
	speed = 4;
	bullets = new BulletPool;
}


Player::~Player()
{
}

//update function to check player inputs
void Player::update(Boss& boss)
{
	this->draw();
	if (IsKeyDown(KEY_LEFT)) {
		translate(Vector2{ -speed,0 });
	}  
	
	if (IsKeyDown(KEY_UP)) {
		translate(Vector2{ 0,-speed });
	}  
	if (IsKeyDown(KEY_DOWN)) {
		translate(Vector2{ 0,speed });
	}
	if (IsKeyDown(KEY_RIGHT)) {
		translate(Vector2{ speed,0 });
	}
	shoot();
	drawBullets();
	hit(boss);
	DrawText(std::to_string(hits).c_str(), 100, 50, 50, WHITE);
	pos.x = std::clamp((int)pos.x, 0, SCREENWIDTH - texture.width);
	pos.y = std::clamp((int)pos.y, 0, SCREENHEIGHT - texture.height);
	collider.x = std::clamp((int)collider.x, 70, SCREENWIDTH -102);
	collider.y = std::clamp((int)collider.y, 45, SCREENHEIGHT - 106);
}


void Player::shoot() {
	if (IsKeyPressed(KEY_LEFT_CONTROL)) {
		SimpleSprites* left = bullets->retrieve();
		left->setPos(Vector2{ pos.x + 40, pos.y });
		SimpleSprites* right = bullets->retrieve();
		right->setPos(Vector2{ pos.x + texture.width - 50, pos.y });
	}
}

void Player::drawBullets() {
	for (int i = 0; i < bullets->free->size(); i++) {
		if (bullets->free->at(i) == true) {
			bullets->pool->at(i)->translate(Vector2{ 0,-speed - 1 });
			bullets->pool->at(i)->draw();
			if (collisionCheck(Background::playArea, bullets->pool->at(i)->collider)) {
				bullets->recycle(bullets->pool->at(i));
			}
		}
	}
}

//when player bullet hits the boss
void Player::hit(Boss &enemy) {
	for (int i = 0; i < bullets->free->size(); i++) {
		if (bullets->free->at(i) == true) {
			if (CheckCollisionCircleRec(enemy.collider.center, enemy.collider.radius, bullets->pool->at(i)->collider)) {
				hits++;
				bullets->recycle(bullets->pool->at(i));
			}
		}
	}
}
