#pragma once

namespace CruZ
{
    class IUpdate
    {
    public:
        virtual void update(float deltaTime) = 0;
    };
}
