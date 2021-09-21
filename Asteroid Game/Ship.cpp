#include "Ship.h"
#include <math.h>
#include "raylib.h"

static float playerBaseSize = 20.0f;
static int playerMaxShoot = 10;

Ship::Ship(Vector2 speed, Vector2 acceleration, int rotation, Color color)
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
void Ship::Rotation()
{
    Direccion.x = GetMouseX() - position.x;
    Direccion.y = GetMouseY() - position.y;

    angulo = sqrt(pow(Direccion.x, 2) + pow(Direccion.y, 2));

    angulo = atan(Direccion.y / Direccion.x);

    //Ver deg y rad, y revisar caudrante
    if (Direccion.x < GetScreenWidth() / 2 && Direccion.y < GetScreenHeight() / 2)
    {
        //2
        angulo += 180;
    }
    if (Direccion.x < GetScreenWidth() / 2 && Direccion.y > GetScreenHeight() / 2)
    {
        //3
        angulo += 180;
    }
    if (Direccion.x > GetScreenWidth() / 2 && Direccion.y > GetScreenHeight() / 2)
    {
        //4
        angulo += 360;
    }
    rotation = angulo;

    if (IsMouseButtonPressed(3))
    {
        DireccionNormalizada.x = Direccion.x / Direccion.x;
        DireccionNormalizada.y = Direccion.y / Direccion.y;

        acceleration.x += DireccionNormalizada.x;
        acceleration.y += DireccionNormalizada.y;

        FinalPosition.x = position.x + acceleration.x * GetFrameTime();
        FinalPosition.y = position.y + acceleration.y * GetFrameTime();
    }



    


    
}
void Ship::Move()
{
    
}
void Ship::draw()
{
    Vector2 v1 = { FinalPosition.x + sinf(rotation * DEG2RAD) * (shipHeight), FinalPosition.y - cosf(rotation * DEG2RAD) * (shipHeight) };
    Vector2 v2 = { FinalPosition.x - cosf(rotation * DEG2RAD) * (playerBaseSize / 2), FinalPosition.y - sinf(rotation * DEG2RAD) * (playerBaseSize / 2) };
    Vector2 v3 = { FinalPosition.x + cosf(rotation * DEG2RAD) * (playerBaseSize / 2), FinalPosition.y + sinf(rotation * DEG2RAD) * (playerBaseSize / 2) };
    DrawTriangle(v1, v2, v3, color);
}
Vector2 Ship::getPosition()
{
    return position;
}