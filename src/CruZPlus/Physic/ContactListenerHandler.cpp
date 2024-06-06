#include "ContactListenerHandler.h"

namespace CruZ
{
void ContactListenerHandler::BeginContact(b2Contact *)
{
    PRINTF("BEGIN CONTACK\n");
}

void ContactListenerHandler::EndContact(b2Contact *)
{
    PRINTF("END CONTACK\n");
}
}