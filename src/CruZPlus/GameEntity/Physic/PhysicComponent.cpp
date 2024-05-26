#include "PhysicComponent.h"
#include "CruZPlus/BodyFactory.h"

namespace CruZ
{
    PhysicComponent::PhysicComponent()
    {
    }

    PhysicComponent::~PhysicComponent()
    {
        INS(Physic)->DestroyBody(m_body);
    }
}
