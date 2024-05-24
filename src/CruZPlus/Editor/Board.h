#pragma once

#include <SFML/Graphics.hpp>

namespace CruZ
{
    class Board
    {
    public:
        Board(/* args */);
        void render(sf::RenderWindow &window);
        ~Board();
    };
}
