#include <SFML/Graphics.hpp>
#include "src/Ball.h"
#include "src/Paddle.h"

int main() {
    const float windowWidth = 800;
    const float windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bouncing Ball Game");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
        return -1; // Use a valid system font path or bundle a font
    }

    sf::Text gameOverText("Game Over\nPress R to Restart", font, 32);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(windowWidth / 2 - 150, windowHeight / 2 - 50);

    Ball ball(10.f, windowWidth / 2, windowHeight / 2);
    Paddle paddle(100.f, 20.f, windowWidth / 2 - 50, windowHeight - 40);

    bool isGameOver = false;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (isGameOver && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                // Reset game
                ball = Ball(10.f, windowWidth / 2, windowHeight / 2);
                paddle = Paddle(100.f, 20.f, windowWidth / 2 - 50, windowHeight - 40);
                isGameOver = false;
            }
        }

        if (!isGameOver) {
            // Paddle input
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                paddle.moveLeft();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                paddle.moveRight();
            else
                paddle.stop();

            ball.update(windowWidth, windowHeight);
            paddle.update(windowWidth);

            // Collision with paddle
            if (ball.getBounds().intersects(paddle.getBounds())) {
                ball.bounceY();
            }

            // Ball missed the paddle
            if (ball.getBounds().top > windowHeight) {
                isGameOver = true;
            }
        }

        window.clear(sf::Color::Black);

        if (isGameOver) {
            window.draw(gameOverText);
        } else {
            ball.draw(window);
            paddle.draw(window);
        }

        window.display();
    }

    return 0;
}
