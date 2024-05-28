#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CruZPlus/Memory.h"
#include "CruZPlus/Physic.h"
#include "Entity.h"

class CruZ::BlockAllocator;

namespace CruZ
{
class Bullet : public Entity, private PhysicComponent
{
  public:
    Bullet(BlockAllocator &);
    void setPosition(const sf::Vector2f &position);
    void update(float deltaTime);
    void render(sf::RenderWindow &);
    ~Bullet();

  private:
    BlockAllocator *m_allocator;
    sf::Sprite *m_sprite;
};
} // namespace CruZ