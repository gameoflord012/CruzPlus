#include "BodyFactory.h"

namespace CruZ
{
    Physic::Physic(b2World &world) : m_world(&world)
    {
    }

    b2Body *Physic::CreateCircle(float r, b2BodyType bodyType)
    {
        b2BodyDef bodyDef;
        bodyDef.type = bodyType;
        auto body = m_world->CreateBody(&bodyDef);

        b2CircleShape shape;
        shape.m_radius = r;
        body->CreateFixture(&shape, 0);

        return body;
    }

    void Physic::DestroyBody(b2Body *body)
    {
        m_world->DestroyBody(body);
    }
}