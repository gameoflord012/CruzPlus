#include "SpaceShip.h"

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <cstdio>
#include <filesystem>

#include <CruZPlus/BodyFactory.h>
#include <CruZPlus/Conversion.h>
#include <CruZPlus/DebugUltility.h>
#include <CruZPlus/Game.h>
#include <CruZPlus/GameEntity/EntityWorld.h>
#include <CruZPlus/Input.h>
#include <CruZPlus/Memory.h>
#include <CruZPlus/TextureManager.h>
#include <CruzPlus/Memory/BlockAllocator.h>

#include "Bullet.h"

namespace SpaceShooter
{
SpaceShip::SpaceShip()
{
    // create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    m_body = INS(CruZ::BodyFactory)->CreateBody(bodyDef);

    // create fixture
    b2PolygonShape boxShape;
    boxShape.SetAsBox(10, 10);
    m_body->CreateFixture(&boxShape, 0);

    // create sprite
    m_sprite = new sf::Sprite(*INS(CruZ::TextureManager)->get("res/main_ship.png"));
    m_sprite->setOrigin(m_sprite->getGlobalBounds().getSize() / 2.0f);
}

void SpaceShip::render(sf::RenderWindow &window)
{
    sf::Vector2f bodyPosition = {};
    m_sprite->setPosition({m_body->GetPosition().x, -m_body->GetPosition().y});
    window.draw(*m_sprite);
}

void SpaceShip::update(float)
{
    // update velocity inputs
    {
        b2Vec2 veloc(0, 0);
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::A))
            veloc += {-1, 0};
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::D))
            veloc += {1, 0};
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::W))
            veloc += {0, 1};
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::S))
            veloc += {0, -1};

        if (veloc.Length() < 1)
            veloc = {0, 0};
        else
            veloc.Normalize();
        veloc *= SPACESHIP_SPEED;

        m_body->SetLinearVelocity(veloc);
    }

    // PRINTF("Space press: %s\n", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) ? "TRUE" : "FALSE");

    // update spawn bullet
    {
        if (INS(CruZ::Input)->isKeyJustPressed(sf::Keyboard::Key::Space))
        {
            SpawnBullet();
        }
    }
}

void SpaceShip::SpawnBullet()
{
    Bullet *bullet = new Bullet;
    bullet->setPosition({m_body->GetPosition().x, m_body->GetPosition().y + BULLET_OFFSTE_Y});
    m_bullets.push_back(bullet);
    getEntityWorld()->addEntity(*bullet);
}

SpaceShip::~SpaceShip()
{
    for (size_t i = 0; i < m_bullets.size(); i++)
    {
        delete m_bullets[i];
    }

    delete m_sprite;
}
} // namespace CruZ
