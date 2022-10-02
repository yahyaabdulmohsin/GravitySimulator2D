class CelestialBody
{
private:
    sf::Vector2f pos;
    float mass;
    float xVelocity;
    float yVelocity;
    sf::CircleShape s;

public:
    CelestialBody(float pos_x, float pos_y, float radius, float mass, char color, float velocity, float direction);
    void render(sf::RenderWindow &wind);
    void move();
    sf::Vector2f get_pos();
    float get_mass();
    float get_xVelocity();
    void accelerate(float hforce, float vforce);
};