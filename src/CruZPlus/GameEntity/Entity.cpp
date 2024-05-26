#include "Entity.h"

namespace CruZ
{
    void Entity::update(float deltaTime)
    {
    }

    void Entity::render(sf::RenderWindow &window)
    {
    }
    EntityWorld *Entity::getWorld()
    {
        return m_world;
    }
}
