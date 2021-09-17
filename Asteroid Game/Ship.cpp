#include "Ship.h"
#include <math.h>
#include "raylib.h"

static float playerBaseSize = 20.0f;
static int playerMaxShoot = 10;

Ship::Ship(Vector2 speed, int acceleration, int rotation, Color color)
{
    this->speed = speed ;
    this->acceleration = acceleration;
    this->rotation = rotation;
    this->color = color;
    
    shipHeight = (playerBaseSize / 2) / tanf(20 * DEG2RAD);
    collider = { position.x + (float)sin(rotation * DEG2RAD) * (shipHeight / 2.5f), position.y - (float)cos(rotation * DEG2RAD) * (shipHeight / 2.5f), 12};
    position = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 - shipHeight / 2 };
}
Ship::~Ship()
{

}
void Ship::Shoot()
{
    if (IsKeyPressed(IsMouseButtonPressed(3)))
    {
        for (int i = 0; i < playerMaxShoot; i++)
        {
            shoot[i].positionShoot = { 0, 0 };
            shoot[i].speed = { 0, 0 };
            shoot[i].radius = 2;
            shoot[i].active = false;
            shoot[i].lifeSpawn = 0;
            shoot[i].color = WHITE;
        }
    }
}
void Ship::move()
{
    
}
void Ship::draw()
{
    Vector2 v1 = { position.x + sinf(rotation * DEG2RAD) * (shipHeight), position.y - cosf(rotation * DEG2RAD) * (shipHeight) };
    Vector2 v2 = { position.x - cosf(rotation * DEG2RAD) * (playerBaseSize / 2), position.y - sinf(rotation * DEG2RAD) * (playerBaseSize / 2) };
    Vector2 v3 = { position.x + cosf(rotation * DEG2RAD) * (playerBaseSize / 2), position.y + sinf(rotation * DEG2RAD) * (playerBaseSize / 2) };
    DrawTriangle(v1, v2, v3, color);
}
Vector2 Ship::getPosition()
{
    return position;
}