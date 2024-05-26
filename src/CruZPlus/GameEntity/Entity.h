#pragma once

#include <SFML/Graphics.hpp>

#include "IUpdate.h"
#include "IRender.h"

namespace CruZ
{
    class EntityWorld;
    
    class Entity : public IUpdate, public IRender
    {
        friend class EntityWorld;

    public:
        virtual void update(float deltaTime);
        virtual void render(sf::RenderWindow &);
        EntityWorld *getEntityWorld();
        ~Entity();
        
    private:
        EntityWorld *m_world;
    };
}