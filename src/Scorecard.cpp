//
// Created by admin on 16/06/25.
//

#include "Scorecard.h"
#include <stdexcept>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Scorecard::Scorecard(float x, float y) :score(0) {
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(x, y);
    updateText();
}


void Scorecard::increment(int points) {
    score+=points;
    updateText();
}

void Scorecard::reset() {
    score=0;
    updateText();
}

int Scorecard::getScore() const {
    return score;
}

void Scorecard::draw(sf::RenderWindow& window) const {
    window.draw(text);
}

void Scorecard::updateText() {
    text.setString("Score: "+ std::to_string(score));
}





