#pragma once

#include <box2d/box2d.h>

namespace CruZ
{
    class PhysicComponent
    {
    public:
        PhysicComponent();
        ~PhysicComponent();
    protected:
        b2Body *m_body;
    };
}