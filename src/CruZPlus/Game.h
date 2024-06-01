#pragma once

#include <chrono>
#include <vector>

namespace sf
{
class View;
}

class b2World;

namespace CruZ
{
class EntityWorld;
class Input;

class Game
{
  public:
    Game();
    b2World *getB2World();
    EntityWorld *getEntityWorld();
    sf::View *getView();
    void run();
    ~Game();

  private:
    static constexpr int FPS{60};
    static constexpr float UPDATE_DURATION{1.0f / 60};

    EntityWorld *m_entityWorld{};
    b2World *m_b2World{};
    Input *m_input{};
    sf::View *m_view{};
};
} // namespace CruZ

#include "Instances.h"