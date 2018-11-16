#pragma once
#include <string>
#include "raylib.h"
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

	SimpleSprites();
	SimpleSprites(const SimpleSprites &copy);
	SimpleSprites(const std::string & filename);
	~SimpleSprites();
};

