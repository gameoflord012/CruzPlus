#include "SpaceShip.h"

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CruZPlus/BodyFactory.h"
#include "CruZPlus/GameEntity/EntityWorld.h"
#include "Bullet.h"
#include "CruZPlus/Game.h"
#include "CruZPlus/TextureManager.h"
#include "CruzPlus/Memory/BlockAllocator.h"

namespace CruZ
{
SpaceShip::SpaceShip()
{
    m_allocator = new BlockAllocator;

    // create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    m_body = INS(BodyFactory)->CreateBody(bodyDef);

    // create fixture
    b2PolygonShape boxShape;
    boxShape.SetAsBox(10, 10);
    m_body->CreateFixture(&boxShape, 0);

    // create sprite
    m_sprite = new sf::Sprite(*INS(TextureManager)->get("res/main_ship.png"));
}

void SpaceShip::render(sf::RenderWindow &window)
{
    sf::Vector2f bodyPosition = {m_body->GetPosition().x, m_body->GetPosition().y};
    m_sprite->setPosition({bodyPosition.x, -bodyPosition.y});
    window.draw(*m_sprite);
}

void SpaceShip::update(float deltaTime)
{
    // update velocity inputs
    {
        float speed = 100;

        b2Vec2 veloc(0, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            veloc += {-1, 0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            veloc += {1, 0};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            veloc += {0, 1};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            veloc += {0, -1};

        if (veloc.Length() < 1)
            veloc = {0, 0};
        else
            veloc.Normalize();
        veloc *= speed;

        m_body->SetLinearVelocity(veloc);
    }

    // update spawn bullet
    {
        if (m_lastSpace == false && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            void *mem = m_allocator->Allocate(sizeof(Bullet));
            Bullet *bullet = new (mem) Bullet(*m_allocator);
            bullet->setPosition({m_body->GetPosition().x, m_body->GetPosition().y});
            m_bullets.push_back(bullet);
            getEntityWorld()->addEntity(*bullet);
        }
    }

    // update last key states
    {
        m_lastSpace = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
    }
}

SpaceShip::~SpaceShip()
{
    for (size_t i = 0; i < m_bullets.size(); i++)
    {
        m_bullets[i]->~Bullet();
        m_allocator->Free(m_bullets[i]);
    }

    delete m_allocator;
}
} // namespace CruZ
