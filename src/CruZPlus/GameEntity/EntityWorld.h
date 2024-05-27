#pragma once

#include <unordered_set>
#include <vector>

namespace CruZ
{
class Entity;

class EntityWorld
{
  public:
    void updateAll(float);
    void renderAll(sf::RenderWindow &);
    void addEntity(Entity &);
    void removeEntity(Entity &);

  private:
    std::vector<Entity *> m_entities;
};
} // namespace CruZ