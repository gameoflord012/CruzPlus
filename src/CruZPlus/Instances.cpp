#include "Instances.h"

namespace CruZ
{
    std::unordered_map<std::type_index, void *> Instances::s_intances = {};
}
