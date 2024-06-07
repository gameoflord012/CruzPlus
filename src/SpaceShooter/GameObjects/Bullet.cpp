#include "Bullet.h"

#include <SFML/Graphics.hpp>

#include <CruZPlus/BodyFactory.h>
#include <CruZPlus/Graphic/AnimatedSprite.h>
#include <CruZPlus/Graphic/SpriteSheet.h>
#include <CruZPlus/Memory.h>
#include <CruZPlus/TextureManager.h>

namespace SpaceShooter
{
Bullet::Bullet()
{
    m_body = INS(CruZ::BodyFactory)->CreateCircle(5, b2_dynamicBody);
    m_body->GetFixtureList()[0].SetSensor(true);
    m_body->SetLinearVelocity({0, BULLET_SPEED});

    sf::Texture *texture = INS(CruZ::TextureManager)->get("res/main_ship_bullet.png");
    m_sprite = new sf::Sprite(*texture);
    m_spriteSheet = new CruZ::SpriteSheet(*m_sprite, 4, 1);
    m_animatedSprite = new CruZ::AnimatedSprite(*m_spriteSheet);
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
    delete m_sprite;
    delete m_spriteSheet;
    delete m_animatedSprite;
}
} // namespace SpaceShooter
