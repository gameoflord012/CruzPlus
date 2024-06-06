#include "ContactListenerHandler.h"

namespace CruZ
{
void ContactListenerHandler::BeginContact(b2Contact *)
{
    PRINTF("BEGIN CONTACK");
}

void ContactListenerHandler::EndContact(b2Contact *)
{
    PRINTF("END CONTACK");
}
}