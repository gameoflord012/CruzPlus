#pragma once

class b2BlockAllocator;

namespace CruZ
{
class BlockAllocator
{
  public:
    BlockAllocator();
    ~BlockAllocator();

    void *Allocate(int size);
    template <typename FreeType> void Free(FreeType *);
    void Clear();

  private:
    b2BlockAllocator *m_allocator;
};

template <typename FreeType> void BlockAllocator::Free(FreeType *p)
{
    p->~FreeType();
    m_allocator->Free(p, sizeof(FreeType));
}
} // namespace CruZ
