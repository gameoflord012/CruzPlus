#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <vector>

#include <CruZPlus/GameEntity.h>
#include <CruZPlus/Physic.h>

class b2World;
class sf::Sprite;

namespace CruZ
{
class BlockAllocator;
}
namespace SpaceShooter
{
class Bullet;

class SpaceShip : public CruZ::Entity, public CruZ::PhysicComponent
{
  public:
    SpaceShip();
    void render(sf::RenderWindow &window);
    void update(float elapsedTime);
    void SpawnBullet();
    ~SpaceShip();

  private:
    const float BULLET_OFFSTE_Y = 15;

    CruZ::BlockAllocator *m_allocator = NULL;
    sf::Sprite *m_sprite = NULL;
    std::vector<Bullet *> m_bullets;
};
} // namespace SpaceShooter