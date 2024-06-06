#include "PlayerShip.h"

#include <CruZPlus/Input.h>

namespace SpaceShooter
{
PlayerShip::PlayerShip() : SpaceShip("res/main_ship.png")
{
}

void PlayerShip::update(float)
{
    // update velocity inputs
    {
        b2Vec2 veloc(0, 0);
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::A))
            veloc += {-1, 0};
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::D))
            veloc += {1, 0};
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::W))
            veloc += {0, 1};
        if (INS(CruZ::Input)->isKeyPressed(sf::Keyboard::Key::S))
            veloc += {0, -1};

        if (veloc.Length() < 1)
            veloc = {0, 0};
        else
            veloc.Normalize();
        veloc *= SPACESHIP_SPEED;

        m_body->SetLinearVelocity(veloc);
    }

    // update spawn bullet
    {
        if (INS(CruZ::Input)->isKeyJustPressed(sf::Keyboard::Key::Space))
        {
            SpawnBullet();
        }
    }
}
}