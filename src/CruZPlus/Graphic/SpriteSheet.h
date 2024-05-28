#pragma once

namespace sf
{
    class Sprite;
}

namespace CruZ
{
class SpriteSheet
{
  public:
    SpriteSheet(const char *);

  private:
    sf::Sprite *m_sprite;
};
}
