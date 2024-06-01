#pragma once

#include <cassert>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

namespace CruZ
{
class Instances
{
  public:
    template <typename InstanceTy>
        requires(!std::is_pointer_v<InstanceTy>)
    static void set(const InstanceTy &instance)
    {
        std::type_index tyIndex(typeid(InstanceTy));
        assert(s_intances.find(tyIndex) == s_intances.end());
        s_intances[tyIndex] = (void *)&instance;
    }

    template <typename InstancePtrTy>
        requires(std::is_pointer_v<InstancePtrTy>)
    static void set(const InstancePtrTy instance)
    {
        std::type_index tyIndex(typeid(std::remove_pointer_t<InstancePtrTy>));
        assert(s_intances.find(tyIndex) == s_intances.end());
        s_intances[tyIndex] = (void *)instance;
    }

    template <typename InstanceTy> static InstanceTy *get();

  private:
    static std::unordered_map<std::type_index, void *> s_intances;
};

template <typename InstanceTy> InstanceTy *Instances::get()
{
    std::type_index tyIndex(typeid(InstanceTy));
    auto ins = (InstanceTy *)s_intances[tyIndex];
    return assert(ins), ins;
}

#define INS(x) Instances::get<x>()
} // namespace CruZ
