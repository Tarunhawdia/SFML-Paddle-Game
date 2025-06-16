//
// Created by admin on 16/06/25.
//

#ifndef SCORECARD_H
#define SCORECARD_H
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>


namespace sf {
    class RenderWindow;
}

class Scorecard{
public:
    Scorecard(float x=0,float y=0);

    void increment(int point=1);
    void reset();
    void draw(sf::RenderWindow &window) const;

private:
    int score;
    sf::Font font;
    sf::Text text;

    void updateText();
};



#endif //SCORECARD_H
