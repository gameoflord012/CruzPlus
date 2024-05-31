#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace sf
{
class Sprite;
class RenderWindow;
}

namespace CruZ
{
class SpriteSheet
{
  public:
    SpriteSheet(sf::Sprite &sprite, int sliceW, int sliceH);
    void slice(int index);
    void render(sf::RenderWindow &window, const sf::Vector2f &coord);
    sf::Sprite *getSprite();

  private:
    friend class AnimatedSprite;
    
    int m_sliceW{};
    int m_sliceH{};
    sf::IntRect m_rect;
    sf::Sprite *m_sprite;
};
}
