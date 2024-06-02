#pragma once

#include <box2d/b2_block_allocator.h>

namespace CruZ
{
class BlockAllocator
{
  public:
    BlockAllocator();
    ~BlockAllocator();

    void *Allocate(int size);

    template <typename FreeType> void Free(FreeType *p)
    {
        p->~FreeType();
        m_allocator->Free(p, sizeof(FreeType));
    }
 
    void Clear();

  private:
    b2BlockAllocator *m_allocator;
};
} // namespace CruZ
