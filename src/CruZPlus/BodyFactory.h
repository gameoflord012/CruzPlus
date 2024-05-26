#include <box2d/box2d.h>

namespace CruZ
{
    class Physic
    {
    public:
        Physic(b2World &world);
        b2Body *CreateCircle(float r, b2BodyType bodyType);
        void DestroyBody(b2Body *body);

    private:
        b2World *m_world;
    };
}

#include "Instances.h"