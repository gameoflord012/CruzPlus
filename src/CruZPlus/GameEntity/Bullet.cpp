#include "Bullet.h"

#include <SFML/Graphics.hpp>

#include "CruZPlus/Memory/TextureManager.h"
#include "CruZPlus/BodyFactory.h"

namespace CruZ
{
    Bullet::Bullet(BlockAllocator &allocator) : m_allocator(&allocator)
    {
        m_body = INS(BodyFactory)->CreateCircle(5, b2_kinematicBody);
        m_body->SetLinearVelocity({0, 20});
        auto mem = allocator.Allocate(sizeof(sf::Sprite));
        sf::Texture *texture = INS(TextureManager)->get("res/main_ship_bullet.png");
        m_sprite = new (mem) sf::Sprite(*texture);
    }

    void Bullet::setPosition(const sf::Vector2f &position)
    {
        m_body->SetTransform({position.x, position.y}, 0);
    }

    void Bullet::update(float deltaTime)
    {
    }

    void Bullet::render(sf::RenderWindow &window)
    {
        m_sprite->setPosition({m_body->GetPosition().x, -m_body->GetPosition().y});
        window.draw(*m_sprite);
    }

    Bullet::~Bullet()
    {
        m_allocator->Free(m_sprite);
    }
}
