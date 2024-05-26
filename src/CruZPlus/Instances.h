#pragma once

#include <unordered_map>
#include <typeindex>
#include <typeinfo>

namespace CruZ
{
    class Instances
    {
    public:
        template <typename InstanceTy>
        static void set(InstanceTy &instance);

        template <typename InstanceTy>
        static InstanceTy *get();

        static std::unordered_map<std::type_index, void *> s_intances;
    };

    template <typename InstanceTy>
    void Instances::set(InstanceTy &instance)
    {
        std::type_index tyIndex(typeid(InstanceTy));
        assert(s_intances.find(tyIndex) == s_intances.end());
        s_intances[tyIndex] = (void *)&instance;
    }

    template <typename InstanceTy>
    InstanceTy *Instances::get()
    {
        std::type_index tyIndex(typeid(InstanceTy));
        return static_cast<InstanceTy *>(s_intances[tyIndex]);
    }

    #define INS(x) Instances::get<x>()
}

