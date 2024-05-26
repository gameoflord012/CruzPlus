#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "IUpdate.h"
#include "IRender.h"
#include "CruZPlus/Memory/BlockAllocator.h"

namespace CruZ
{
    class SpaceShip : public IUpdate, public IRender
    {
    public:
        SpaceShip();
        void render(sf::RenderWindow &window);
        void update(float elapsedTime);
        ~SpaceShip();

    private:
        BlockAllocator m_allocator;

        b2Body *m_body;
        b2World *m_world;
        sf::Sprite *m_sprite;
        sf::Texture *m_texture;
    };
}