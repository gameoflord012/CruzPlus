#pragma once

#include "SpaceShip.h"

namespace SpaceShooter
{
class PlayerShip : public SpaceShip
{
public:
    PlayerShip();

    void update(float);
};
}