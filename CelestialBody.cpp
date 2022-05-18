#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "CelestialBody.h"

CelestialBody::CelestialBody(float pos_x, float pos_y, float radius, float mass, char color, float velocity, float direction) : pos{pos_x, pos_y}, mass{mass}
{
    s.setRadius(radius);
    s.setOrigin(radius, radius);
    s.setPosition(pos);
    if (color == 'r')
    {
        s.setFillColor(sf::Color::Red);
    }
    else if (color == 'g')
    {
        s.setFillColor(sf::Color::Green);
    }
    else if (color == 'b')
    {
        s.setFillColor(sf::Color::Blue);
    }

    float angleRADS = (3.1415926536 / 180) * (direction);
    if (direction == 0)
    {
        xVelocity = velocity;
        yVelocity = 0.f;
    }
    else if (direction < 90)
    {
        xVelocity = velocity * std::cos(angleRADS);
        yVelocity = velocity * std::sin(angleRADS);
    }
    else if (direction == 90)
    {
        xVelocity = 0.f;
        yVelocity = velocity;
    }
    else if (direction < 180)
    {
        xVelocity = -1 * velocity * std::cos(3.1415926536 - angleRADS);
        yVelocity = velocity * std::sin(3.1415926536 - angleRADS);
    }
    else if (direction == 180)
    {
        xVelocity = -1 * velocity;
        yVelocity = 0.f;
    }
    else if (direction < 270)
    {
        xVelocity = -1 * velocity * std::sin(((3 * 3.1415926536) / 2) - angleRADS);
        yVelocity = -1 * velocity * std::cos(((3 * 3.1415926536) / 2) - angleRADS);
    }
    else if (direction == 270)
    {
        xVelocity = 0.f;
        yVelocity = -1 * velocity;
    }
    else if (direction < 360)
    {
        xVelocity = velocity * std::cos((2 * 3.1415926536) - angleRADS);
        yVelocity = -1 * velocity * std::sin((2 * 3.1415926536) - angleRADS);
    }
    else if (direction == 360)
    {
        xVelocity = velocity;
        yVelocity = 0.f;
    }
}

void CelestialBody::render(sf::RenderWindow &wind)
{
    wind.draw(s);
}

sf::Vector2f CelestialBody::get_pos()
{
    return pos;
}

float CelestialBody::get_mass()
{
    return mass;
}

float CelestialBody::get_xVelocity()
{
    return xVelocity;
}

void CelestialBody::move()
{
    s.move(xVelocity / 1000, (-1 * yVelocity) / 1000);
    this->pos.x = s.getPosition().x;
    this->pos.y = s.getPosition().y;
}

void CelestialBody::accelerate(float hforce, float vforce)
{
    float ha = (hforce / mass);
    float va = (vforce / mass);
    xVelocity = xVelocity + ha;
    yVelocity = yVelocity + va;
}