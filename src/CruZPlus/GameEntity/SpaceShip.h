#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>

#include "CruZPlus/GameEntity/Entity.h"
#include "CruZPlus/GameEntity/Physic/PhysicComponent.h"

class b2World;
class sf::Sprite;

namespace CruZ
{
class Bullet;
class BlockAllocator;

class SpaceShip : public Entity, public PhysicComponent
{
  public:
    SpaceShip();
    void render(sf::RenderWindow &window);
    void update(float elapsedTime);
    ~SpaceShip();

  private:
    BlockAllocator *m_allocator = NULL;
    sf::Sprite *m_sprite = NULL;
    bool m_lastSpace;
    std::vector<Bullet *> m_bullets;
};
}