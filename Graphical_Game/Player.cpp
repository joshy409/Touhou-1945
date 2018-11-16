#include "Player.h"



Player::Player() : SimpleSprites("GameAssets/Ships/player_ship.png")
{
	texture = LoadTexture("GameAssets/Ships/player_ship.png");
	setPos (Vector2{ (float) SCREENWIDTH / 2 , (float)SCREENHEIGHT - texture.height });
	speed = 4;
	//projectiles = new std::vector<SimpleSprites*>;
	bullets = new BulletPool;
}


Player::~Player()
{
}

void Player::action()
{
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
	drawProjectiles();
	pos.x = std::clamp((int)pos.x, 0, SCREENWIDTH - texture.width);
	pos.y = std::clamp((int)pos.y, 0, SCREENHEIGHT - texture.height);
}
void Player::shoot() {
	if (IsKeyPressed(KEY_LEFT_CONTROL)) {
		SimpleSprites* left = bullets->retrieve();
		left->setPos(Vector2{ pos.x + 40, pos.y });
		SimpleSprites* right = bullets->retrieve();
		right->setPos(Vector2{ pos.x + texture.width - 50, pos.y });
	}
}

void Player::drawProjectiles() {
	for (int i = 0; i < bullets->free->size(); i++) {
		if (bullets->free->at(i) == true) {
			bullets->pool->at(i)->translate(Vector2{ 0,-speed - 1 });
			bullets->pool->at(i)->draw();
			if (bullets->pool->at(i)->pos.y < 0) {
				bullets->recycle(bullets->pool->at(i));
			}
		}
	}
}



void Player::hit(Player enemy) {}

//void Player::shoot() {
//	if (IsKeyPressed(KEY_LEFT_CONTROL)) {
// 		auto temp = laserL->Clone();
//		temp->setPos( Vector2{ pos.x + 40, pos.y });
//		projectiles->push_back(temp);
//		temp = laserR->Clone();
//		temp->setPos(Vector2{ pos.x + texture.width - 50, pos.y });
//		projectiles->push_back(temp);
//	}
//}
//
//
//void Player::drawProjectiles() { 
//	std::vector<int> removeIndex;
//	DrawText(std::to_string(projectiles->size()).c_str(), 100, 400, 50, BLACK);
//	DrawText(std::to_string(hits).c_str(), 100, 0, 50, BLACK);
//	for (int i = 0; i < projectiles->size(); i++) { 
//		projectiles->at(i)->translate(Vector2{ 0,-speed-1 });
//		DrawTexture(projectiles->at(i)->texture, projectiles->at(i)->pos.x, projectiles->at(i)->pos.y, WHITE);
//		DrawRectangle(projectiles->at(i)->collider.x, projectiles->at(i)->collider.y, projectiles->at(i)->collider.width, projectiles->at(i)->collider.height, BLACK);
//		if (projectiles->at(i)->pos.y < 0) {  
//			removeIndex.push_back(i);
//		}
//	}
//	for (int& i : removeIndex) {
//		if (projectiles->size() < 2) {
//			projectiles->clear();
//			hits = 0;
//			break;
//		}
//		else {
//			projectiles->erase(projectiles->begin() + i);
//		}
//	}
//	removeIndex.clear();
//
//
//
//}
//
//void Player::hit(Player enemy)
//{
//	std::vector<int> removeIndex;
//	for (int i = 0; i < projectiles->size(); i++) {
//		if (CheckCollisionRecs(projectiles->at(i)->collider,enemy.collider)) {
//			hits++;
//			removeIndex.push_back(i);
//		}
//	}
//	for (int& i : removeIndex) {
//		if (projectiles->size() < 2) {
//			projectiles->clear();
//			break;
//		}
//		else {
//			projectiles->erase(projectiles->begin() + i);
//
//		}
//	}
//	removeIndex.clear();
//}
