#include "SpaceShip.h"
#include "CruZPlus/Instances.h"
#include "CruZPlus/Game.h"
#include "CruZPlus/Instances.h"
#include "CruZPlus/Memory/TexutureManager.h"

using namespace sf;

namespace CruZ
{
    SpaceShip::SpaceShip()
    {
        // create body
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        m_b2world = Instances::get<Game>()->getB2World();
        m_body = m_b2world->CreateBody(&bodyDef);

        // create fixture
        b2PolygonShape boxShape;
        boxShape.SetAsBox(10, 10);
        m_body->CreateFixture(&boxShape, 0);

        // create sprite
        m_sprite = new Sprite(*INS(TextureManager)->get("res/main_ship.png"));
    }

    void SpaceShip::render(RenderWindow &window)
    {
        Vector2f bodyPosition = {m_body->GetPosition().x, m_body->GetPosition().y};
        m_sprite->setPosition({bodyPosition.x, -bodyPosition.y});
        window.draw(*m_sprite);
    }

    void SpaceShip::update(float deltaTime)
    {
        // update velocity inputs
        {
            float speed = 100;

            b2Vec2 veloc(0, 0);
            if (Keyboard::isKeyPressed(Keyboard::Key::Left))
                veloc += {-1, 0};
            if (Keyboard::isKeyPressed(Keyboard::Key::Right))
                veloc += {1, 0};
            if (Keyboard::isKeyPressed(Keyboard::Key::Up))
                veloc += {0, 1};
            if (Keyboard::isKeyPressed(Keyboard::Key::Down))
                veloc += {0, -1};

            if (veloc.Length() < 1)
                veloc = {0, 0};
            else
                veloc.Normalize();
            veloc *= speed;

            m_body->SetLinearVelocity(veloc);
        }

        // update fire bullet
        {
            if(m_lastSpace == false && Keyboard::isKeyPressed(Keyboard::Key::Space))
            {
                void* mem = m_allocator.Allocate(sizeof(Bullet));
                Bullet *bullet = new (mem) Bullet(
                    m_allocator,
                    *INS(TextureManager)->get("res/main_ship_bullet.png"));
                m_bullets.push_back(bullet);
                getEntityWorld()->addEntity(*bullet);
            }
        }

        // update last key states
        {
            m_lastSpace = Keyboard::isKeyPressed(Keyboard::Key::Space);
        }
    }

    SpaceShip::~SpaceShip()
    {
        m_b2world->DestroyBody(m_body);
        for(size_t i = 0; i < m_bullets.size(); i++)
        {
            getEntityWorld()->removeEntity(*m_bullets[i]);
            m_bullets[i]->~Bullet();
            m_allocator.Free(m_bullets[i]);
        }
    }
}
