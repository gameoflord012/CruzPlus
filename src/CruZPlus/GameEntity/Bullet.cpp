#include "Bullet.h"

#include "CruZPlus/Instances.h"
#include "CruZPlus/Physic.h"

namespace CruZ
{
    Bullet::Bullet(BlockAllocator &allocator, sf::Texture &tex) : m_allocator(&allocator)
    {
        m_body = INS(Physic)->CreateCircle(5, b2_kinematicBody);
        m_body->SetLinearVelocity({0, 20});

        auto mem = allocator.Allocate(sizeof(sf::Sprite));
        m_sprite = new (mem) sf::Sprite(tex);
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
        INS(Physic)->DestroyBody(m_body);
        m_allocator->Free(m_sprite);
    }
}
