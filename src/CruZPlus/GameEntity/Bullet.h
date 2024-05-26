#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>

#include "CruZPlus/Memory/BlockAllocator.h"
#include "IUpdate.h"
#include "IRender.h"
#include "Entity.h"

namespace CruZ
{
    class Bullet : public Entity
    {
    public:
        Bullet(BlockAllocator &, sf::Texture &tex);
        void update(float deltaTime);
        void render(sf::RenderWindow &);
        ~Bullet();

    private:
        BlockAllocator *m_allocator;
        sf::Sprite *m_sprite;
        b2Body *m_body;
    };
}
