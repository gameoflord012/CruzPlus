#pragma once

#include "CruZPlus/DebugUltility.h"
#include <box2d/box2d.h>

namespace CruZ
{
class ContactListenerHandler : public b2ContactListener
{
    virtual void BeginContact(b2Contact *contact);

    /// Called when two fixtures cease to touch.
    virtual void EndContact(b2Contact *contact);
};
} // namespace CruZ