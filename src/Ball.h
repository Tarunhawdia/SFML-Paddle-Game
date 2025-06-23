//
// Created by admin on 16/06/25.
//

#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball(float radius, float startX, float startY);
    ~Ball();

    void update(float windowWidth, float windowHeight);
    void draw(sf::RenderWindow &window);

    void bounceX();
    void bounceY();

    void incrementVelocity(float x, float y);
    void setSpeed(float speed);

    sf::FloatRect getBounds() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif // BALL_H
