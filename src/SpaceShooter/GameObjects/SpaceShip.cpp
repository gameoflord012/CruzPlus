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
SpaceShip::SpaceShip(const char *texture)
{
    // create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    m_body = INS(CruZ::BodyFactory)->CreateBody(bodyDef);

    // create fixture
    b2PolygonShape boxShape;
    boxShape.SetAsBox(10, 10);
    m_body->CreateFixture(&boxShape, 0);

    // create sprite
    m_sprite = new sf::Sprite(*INS(CruZ::TextureManager)->get(texture));
    m_sprite->setOrigin(m_sprite->getGlobalBounds().getSize() / 2.0f);
}

void SpaceShip::render(sf::RenderWindow &window)
{
    sf::Vector2f bodyPosition = {};
    m_sprite->setPosition({m_body->GetPosition().x, -m_body->GetPosition().y});
    window.draw(*m_sprite);
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
