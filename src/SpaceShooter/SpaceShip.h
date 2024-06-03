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
    ~SpaceShip();

    void render(sf::RenderWindow &window);
    void update(float elapsedTime);
    void SpawnBullet();

  private:
    const float BULLET_OFFSTE_Y = 15;
    const float SPACESHIP_SPEED = 300.0f;

    sf::Sprite *m_sprite{};
    std::vector<Bullet *> m_bullets;
};
} // namespace SpaceShooter