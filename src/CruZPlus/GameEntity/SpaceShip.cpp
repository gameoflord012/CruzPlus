#include "SpaceShip.h"
#include "CruZPlus/Instances.h"
#include "CruZPlus/Game.h"

using namespace sf;

namespace CruZ
{
    SpaceShip::SpaceShip()
    {
        // create body
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        m_world = Instances::get<Game>()->getB2World();
        m_body = m_world->CreateBody(&bodyDef);

        // create fixture
        b2PolygonShape boxShape;
        boxShape.SetAsBox(10, 10);
        m_body->CreateFixture(&boxShape, 0);

        // create sprite
        m_texture = new Texture();
        assert(m_texture->loadFromFile("res\\main_ship.png"));

        m_sprite = new Sprite(*m_texture);
    }

    void SpaceShip::render(RenderWindow &window)
    {
        Vector2f bodyPosition = {m_body->GetPosition().x, m_body->GetPosition().y};
        m_sprite->setPosition({bodyPosition.x, -bodyPosition.y});
        window.draw(*m_sprite);
    }

    void SpaceShip::update(float deltaTime)
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

    SpaceShip::~SpaceShip()
    {
        m_world->DestroyBody(m_body);
        delete m_texture;
    }
}
