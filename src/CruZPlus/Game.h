#pragma once

#include "CruZPlus/IUpdate.h"
#include "IRender.h"

#include <box2d/box2d.h>
#include <ctime>
#include <vector>

class Game
{
public:
    Game();
    b2World *getWorld();
    void run();
    bool addUpdate(IUpdate &);
    bool addRender(IRender &);
    void updateAll(float);
    void renderAll(sf::RenderWindow &);
    ~Game();

private:
    const float FPS = 60;
    const float UPDATE_INTERVAL = 1.0f / FPS;
    const clock_t CLOCK_PER_FRAME = (clock_t)(UPDATE_INTERVAL * CLOCKS_PER_SEC);

    b2World *m_b2World { NULL };
    std::vector<IUpdate *> m_updates;
    std::vector<IRender *> m_renders;
};