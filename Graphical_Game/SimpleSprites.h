#pragma once
#include <string>
#include "raylib.h"
#include <vector>
class SimpleSprites
{
public:
	Vector2 pos = { 0,0 };
	Rectangle collider;
	Texture2D texture;
	void translate(const Vector2 &delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	void setPos(const Vector2 &delta);
	SimpleSprites * Clone();
	static bool collisionCheck(std::vector<Rectangle> playArea, Rectangle collider);
	Vector2 destination;
	Vector2 travelDistance;
	float distance;
	SimpleSprites();
	SimpleSprites(const SimpleSprites &copy);
	SimpleSprites(const std::string & filename);
	~SimpleSprites();
};

