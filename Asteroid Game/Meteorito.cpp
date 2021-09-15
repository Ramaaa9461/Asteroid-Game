#include "Meteorito.h"
#include "raylib.h"

Meteorito::Meteorito(int radius, int velocityX, int velocityY, Color color)
{
	this->radius = radius;
	this->velocityX = velocityX;
	this->velocityY = velocityY;
	this->color = color;
	meteoritoPosition = { 0,0 };
}
Meteorito::~Meteorito()
{

}
void Meteorito::spawnRandomPosition(Vector2& meteoritoPosition)
{
	int random = GetRandomValue(0, 3);

	switch (random)
	{
	case 0:
		meteoritoPosition.x = 0 + GetRandomValue(0, GetScreenWidth());
		meteoritoPosition.y = 0;
		break;
	case 1:
		meteoritoPosition.x = 0;
		meteoritoPosition.y = 0 + GetRandomValue(0, GetScreenHeight());
		break;
	case 2:
		meteoritoPosition.x = GetScreenWidth();
		meteoritoPosition.y = 0 + GetRandomValue(0, GetScreenHeight());
		break;
	case 3:
		meteoritoPosition.x = 0 + GetRandomValue(0, GetScreenWidth());
		meteoritoPosition.y = GetScreenHeight();
		break;
	default:
		meteoritoPosition.x = GetScreenWidth() / 2;
		meteoritoPosition.y = GetScreenHeight() / 2;
		break;
	}
}
void Meteorito::move(Vector2& meteoritoPosition, int velocityX, int velocityY)
{
	meteoritoPosition.x += velocityX;
	meteoritoPosition.y += velocityY;
}
void Meteorito::screenLimits(Vector2& meteoritoPosition)
{
	if (meteoritoPosition.x == GetScreenWidth())
	{
		meteoritoPosition.x == 0;
	}
	if (meteoritoPosition.x == 0)
	{
		meteoritoPosition.x == GetScreenWidth();
	}
	if (meteoritoPosition.y == 0)
	{
		meteoritoPosition.y = GetScreenHeight();
	}
	if (meteoritoPosition.y == GetScreenHeight())
	{
		meteoritoPosition.y = 0;
	}
}