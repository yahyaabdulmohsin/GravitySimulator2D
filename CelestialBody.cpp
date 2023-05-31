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

    xVelocity = velocity * std::cos(angleRADS);
    yVelocity = velocity * std::sin(angleRADS);
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
