#include "Entity.h"
#include "EntityWorld.h"

namespace CruZ
{
    void Entity::update(float deltaTime)
    {
    }

    void Entity::render(sf::RenderWindow &window)
    {
    }

    EntityWorld *Entity::getEntityWorld()
    {
        return m_world;
    }

    Entity::~Entity()
    {
        m_world->removeEntity(*this);
    }
}
