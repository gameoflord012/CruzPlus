#pragma once

#include <SFML/Graphics.hpp>
namespace CruZ
{
class IRender
{
  public:
    virtual void render(sf::RenderWindow &) = 0;
};
}