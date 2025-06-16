//
// Created by admin on 16/06/25.
//

#include "Paddle.h"

Paddle::Paddle(float width, float height, float startX, float startY)
    :speed(4.5f)
    ,direction(0)
{
    shape.setSize({width,height});
    shape.setPosition({startX,startY});
    shape.setFillColor(sf::Color::White);
}

void Paddle::update(float windowWidth) {
   sf::Vector2f pos= shape.getPosition();
    float paddleWidth = shape.getSize().x;

    float move=direction*speed;

    if (pos.x+move>=0  && (pos.x +move +paddleWidth<=windowWidth)) {
        shape.move(move,0);
    }
}

void Paddle::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Paddle::moveLeft() {
    direction = -1;
}

void Paddle::moveRight() {
    direction = 1;
}

void Paddle::stop() {
    direction = 0;
}

sf::FloatRect Paddle::getBounds() const {
    return shape.getGlobalBounds();
}

Paddle::~Paddle() = default;



