#include "Bullet.h"

#include <SFML/Graphics.hpp>

#include <CruZPlus/BodyFactory.h>
#include <CruZPlus/Graphic/AnimatedSprite.h>
#include <CruZPlus/Graphic/SpriteSheet.h>
#include <CruZPlus/Memory.h>
#include <CruZPlus/TextureManager.h>

namespace SpaceShooter
{
Bullet::Bullet(CruZ::BlockAllocator &allocator) : m_allocator(&allocator)
{
    m_body = INS(CruZ::BodyFactory)->CreateCircle(5, b2_kinematicBody);
    m_body->SetLinearVelocity({0, BULLET_SPEED});

    sf::Texture *texture = INS(CruZ::TextureManager)->get("res/main_ship_bullet.png");
    void *mem = allocator.Allocate(sizeof(sf::Sprite));
    m_sprite = new (mem) sf::Sprite(*texture);

    mem = allocator.Allocate(sizeof(CruZ::SpriteSheet));
    m_spriteSheet = new (mem) CruZ::SpriteSheet(*m_sprite, 4, 1);

    mem = allocator.Allocate(sizeof(CruZ::AnimatedSprite));
    m_animatedSprite = new (mem) CruZ::AnimatedSprite(*m_spriteSheet);
    m_animatedSprite->setTotalTime(0.5f);
}

void Bullet::setPosition(const sf::Vector2f &position)
{
    m_body->SetTransform({position.x, position.y}, 0);
}

void Bullet::update(float delta)
{
    m_animatedSprite->update(delta);
}

void Bullet::render(sf::RenderWindow &window)
{
    m_animatedSprite->render(window, {m_body->GetPosition().x, m_body->GetPosition().y});
}

Bullet::~Bullet()
{
    m_allocator->Free(m_sprite);
    m_allocator->Free(m_spriteSheet);
    m_allocator->Free(m_animatedSprite);
}
} // namespace CruZ
