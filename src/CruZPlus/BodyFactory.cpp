#include "BodyFactory.h"

namespace CruZ
{
BodyFactory::BodyFactory(b2World &world) : m_world(&world)
{
}

b2Body *BodyFactory::CreateCircle(float r, b2BodyType bodyType)
{
    b2BodyDef bodyDef;
    bodyDef.type = bodyType;
    auto body = m_world->CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = r;
    body->CreateFixture(&shape, 0);

    return body;
}

b2Body *BodyFactory::CreateBody(b2BodyDef &bodyDef)
{
    return m_world->CreateBody(&bodyDef);
}

void BodyFactory::DestroyBody(b2Body &body)
{
    m_world->DestroyBody(&body);
}
} // namespace CruZ