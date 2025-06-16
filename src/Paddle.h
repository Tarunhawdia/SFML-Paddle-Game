//
// Created by admin on 16/06/25.
//

#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle {

public:
    Paddle(float width, float height, float startX, float startY);

    ~Paddle();

    void update(float windowWidth);
    void draw(sf::RenderWindow &window);

    void moveLeft();
    void moveRight();
    void stop();

    sf::FloatRect getBounds() const;

    private:
    sf::RectangleShape shape;
    float speed;
    int direction;// -1 for left, 1 for right, 0 for idle
};



#endif //PADDLE_H
