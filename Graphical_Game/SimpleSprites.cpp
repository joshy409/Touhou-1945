#include "SimpleSprites.h"



SimpleSprites::SimpleSprites()
{
}

SimpleSprites::SimpleSprites(const SimpleSprites & copy)
{
	texture = copy.texture;
	collider = copy.collider;

}

SimpleSprites::SimpleSprites(const std::string & filename)
{
	texture = LoadTexture(filename.c_str());
	collider = { pos.x, pos.y, (float)texture.width, (float) texture.height };
}

SimpleSprites::~SimpleSprites()
{
}

void SimpleSprites::translate(const Vector2 &delta)
{
	pos = { pos.x + delta.x , pos.y + delta.y };
	collider.x = collider.x + delta.x;
	collider.y = collider.y + delta.y;
}

void SimpleSprites::draw()
{
	DrawTexture(texture, pos.x, pos.y, WHITE);
}

void SimpleSprites::setPos(const Vector2 & delta)
{
	pos = {delta.x , delta.y };
	collider.x = delta.x;
	collider.y = delta.y;
}

SimpleSprites * SimpleSprites::Clone()
{
	return new SimpleSprites(*this);
}

bool SimpleSprites::collisionCheck(std::vector<Rectangle> playArea, Rectangle collider)
{
	for (auto rec : playArea) {
		if (CheckCollisionRecs(rec, collider)) {
			return true;
		}
	}
	return false;
}

bool SimpleSprites::moveTo(Vector2 dest)
{
	if (abs(dest.x - pos.x) <= 5 && abs(dest.y - pos.y) <= 5) {
		return true;
	}
	else {
		travelDistance.x = dest.x - pos.x;
		travelDistance.y = dest.y - pos.y;
		distance = sqrt(pow((pos.x - dest.x), 2) + pow((pos.y - dest.y), 2));
		pos.x += travelDistance.x / distance * 4;
		pos.y += travelDistance.y / distance * 4;
		return false;
	}
}
