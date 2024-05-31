#include "Bullet.h"

#include <SFML/Graphics.hpp>

#include "CruZPlus/Memory.h"
#include "CruZPlus/BodyFactory.h"
#include "CruZPlus/TextureManager.h"
#include "CruZPlus/Graphic/SpriteSheet.h"

namespace CruZ
{
Bullet::Bullet(BlockAllocator &allocator) : m_allocator(&allocator)
{
    m_body = INS(BodyFactory)->CreateCircle(5, b2_kinematicBody);
    m_body->SetLinearVelocity({0, 20});
    
    sf::Texture *texture = INS(TextureManager)->get("res/main_ship_bullet.png");
    void* mem = allocator.Allocate(sizeof(sf::Sprite));
    m_sprite = new (mem) sf::Sprite(*texture);

    mem = allocator.Allocate(sizeof(SpriteSheet));
    m_spriteSheet = new (mem) SpriteSheet(*m_sprite, 4, 1);
}

void Bullet::setPosition(const sf::Vector2f &position)
{
    m_body->SetTransform({position.x, position.y}, 0);
}

void Bullet::update(float)
{
}

void Bullet::render(sf::RenderWindow &window)
{
    m_spriteSheet->slice(2);
    m_spriteSheet->render(window, {m_body->GetPosition().x, m_body->GetPosition().y});
}

Bullet::~Bullet()
{
    m_allocator->Free(m_sprite);
    m_allocator->Free(m_spriteSheet);
}
} // namespace CruZ
