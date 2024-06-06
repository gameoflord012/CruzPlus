#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include <CruZPlus/GameEntity.h>
#include <CruZPlus/Physic.h>

namespace CruZ
{
class BlockAllocator;
class SpriteSheet;
class AnimatedSprite;
}

namespace SpaceShooter
{
class Bullet : public CruZ::Entity, private CruZ::PhysicComponent
{
  public:
    Bullet();
    ~Bullet();
    
    void setPosition(const sf::Vector2f &position);
    void update(float deltaTime);
    void render(sf::RenderWindow &);

  private:
    const float BULLET_SPEED = 100;

    sf::Sprite *m_sprite{};
    CruZ::SpriteSheet *m_spriteSheet{};
    CruZ::AnimatedSprite *m_animatedSprite{};
};
} // namespace CruZ