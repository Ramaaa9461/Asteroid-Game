#pragma once
#include "Meteorito.h"
#include "raylib.h"

class Meteorito
{
private:

	Vector2 meteoritoPosition;
	int velocityY;
	int velocityX;
	int radius;
	Color color;
	


public:
	Meteorito(int radius, int velocityX, int velocityY, Color color);
	~Meteorito();
	void spawnRandomPosition(Vector2& meteoritoPosition);
	void move(Vector2& meteoritoPosition, int velocityX, int velocityY);
	void screenLimits(Vector2& meteoritoPosition);
};

