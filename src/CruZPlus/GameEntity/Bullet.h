#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CruZPlus/Physic.h"
#include "Entity.h"

namespace CruZ
{
class BlockAllocator;
class SpriteSheet;
class AnimatedSprite;

class Bullet : public Entity, private PhysicComponent
{
  public:
    Bullet(BlockAllocator &);
    void setPosition(const sf::Vector2f &position);
    void update(float deltaTime);
    void render(sf::RenderWindow &);
    ~Bullet();

  private:
    const float BULLET_SPEED = 100;

    BlockAllocator *m_allocator;
    SpriteSheet *m_spriteSheet;
    AnimatedSprite *m_animatedSprite;
    sf::Sprite *m_sprite;
};
} // namespace CruZ