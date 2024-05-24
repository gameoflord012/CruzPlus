#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CruZPlus/IUpdate.h"
#include "CruZPlus/IRender.h"

class SpaceShip : public IUpdate, public IRender
{
public:
    SpaceShip(b2World * world);
    void render(sf::RenderWindow& window);
    void update(float elapsedTime);
    ~SpaceShip();

private:
    b2Body* m_body;
    b2World* m_world;

    sf::Sprite* m_sprite;
    sf::Texture* m_texture;
};