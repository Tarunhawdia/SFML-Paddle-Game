//
// Created by admin on 16/06/25.
//

#include "Ball.h"

Ball::Ball(float radius, float startX, float startY)
    : shape(radius), velocity(4.f, 4.f)
{
    shape.setPosition(startX, startY);
    shape.setFillColor(sf::Color::Green);
}

void Ball::update(float windowWidth, float windowHeight) {
    shape.move(velocity);

    sf::Vector2f pos = shape.getPosition();
    float diameter = 2 * shape.getRadius();

    // Bounce off left/right
    if (pos.x <= 0 || pos.x + diameter >= windowWidth)
        bounceX();

    // Bounce off top
    if (pos.y <= 0)
        bounceY();

    // If it hits bottom, do nothing for now — handled in Game logic later
}

void Ball::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Ball::bounceX() {
    velocity.x = -velocity.x;
}

void Ball::bounceY() {
    velocity.y = -velocity.y;
}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}
Ball::~Ball() = default;



