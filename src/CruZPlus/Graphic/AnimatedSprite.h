#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
namespace CruZ
{
class SpriteSheet;

class AnimatedSprite
{
  public:
    AnimatedSprite(SpriteSheet &spriteSheet);
    void update(float);
    void render(sf::RenderWindow &, const sf::Vector2f &);
    void setTotalTime(float);
  private:
    float m_currentTime{};
    float m_totalTime{};
    SpriteSheet *m_spriteSheet{};
};
} // namespace CruZ