#pragma once

#include <ctime>
#include <vector>

class b2World;

namespace CruZ
{
class EntityWorld;

class Game
{
  public:
    Game();
    b2World *getB2World();
    EntityWorld *getEntityWorld();
    void run();
    ~Game();

  private:
    const float FPS = 60;
    const float UPDATE_INTERVAL = 1.0f / FPS;
    const clock_t CLOCK_PER_FRAME = (clock_t)(UPDATE_INTERVAL * CLOCKS_PER_SEC);

    EntityWorld *m_entityWorld;
    b2World *m_b2World;
};
} // namespace CruZ

#include "Instances.h"