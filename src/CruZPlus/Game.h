#pragma once

#include <chrono>
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
    static constexpr int FPS{60};
    static constexpr float UPDATE_DURATION{1.0f / 60};

    EntityWorld *m_entityWorld;
    b2World *m_b2World;
};
} // namespace CruZ

#include "Instances.h"