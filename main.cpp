#include <SFML/Graphics.hpp>
#include "src/Ball.h"
#include "src/Paddle.h"
#include "src/Scorecard.h"

enum class GameState {
    Start,
    Playing,
    GameOver
};

int main() {
    constexpr float windowWidth = 800;
    constexpr float windowHeight = 600;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Bouncing Ball Game");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
        return -1;
    }

    sf::Text startText("Press any key to Start", font, 32);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(windowWidth / 2 - 160, windowHeight / 2 - 50);

    sf::Text gameOverText("Game Over\nPress R to Restart", font, 32);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(windowWidth / 2 - 150, windowHeight / 2 - 50);

    Ball ball(10.f, windowWidth / 2, windowHeight / 2);
    Paddle paddle(100.f, 20.f, windowWidth / 2 - 50, windowHeight - 40);
    Scorecard scorecard;

    GameState gameState = GameState::Start;
    bool collisionHappened = false;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Handle input based on game state
            if (gameState == GameState::Start && event.type == sf::Event::KeyPressed){
                gameState = GameState::Playing;
            }

            if (gameState == GameState::GameOver && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R) {
                // Reset game
                scorecard.reset();
                ball = Ball(10.f, windowWidth / 2, windowHeight / 2);
                paddle = Paddle(100.f, 20.f, windowWidth / 2 - 50, windowHeight - 40);
                collisionHappened = false;
                gameState = GameState::Start;
            }
        }

        if (gameState == GameState::Playing) {
            // Paddle control
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                paddle.moveLeft();
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                paddle.moveRight();
            else
                paddle.stop();

            ball.update(windowWidth, windowHeight);
            paddle.update(windowWidth);

            if (ball.getBounds().intersects(paddle.getBounds())) {
                float ballBottom = ball.getBounds().top + ball.getBounds().height;
                float paddleTop = paddle.getBounds().top;

                if (ballBottom < paddleTop + 10.0f) {
                    if (!collisionHappened) {
                        ball.bounceY();
                        scorecard.increment();
                        float newSpeed = 4.0f + static_cast<float>(scorecard.getScore()) * 0.7f;
                        ball.setSpeed(newSpeed);
                        collisionHappened = true;
                    }
                }
            } else {
                collisionHappened = false;
            }

            if (ball.getBounds().top > windowHeight) {
                gameState = GameState::GameOver;
            }
        }

        // DRAW
        window.clear(sf::Color::Black);

        if (gameState == GameState::Start) {
            window.draw(startText);
        } else if (gameState == GameState::Playing) {
            ball.draw(window);
            paddle.draw(window);
            scorecard.draw(window);
        } else if (gameState == GameState::GameOver) {
            scorecard.draw(window);
            window.draw(gameOverText);
        }

        window.display();
    }

    return 0;
}
