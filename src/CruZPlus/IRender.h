#pragma once

#include <SFML/Graphics.hpp>

class IRender
{
public:
    virtual void render(sf::RenderWindow&) = 0;
};