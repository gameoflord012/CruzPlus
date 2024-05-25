#include "BlockAllocator.h"

namespace CruZ
{
    BlockAllocator::BlockAllocator()
    {
    }

    BlockAllocator::~BlockAllocator()
    {
    }

    void *BlockAllocator::Allocate(int32 size)
    {
        return m_allocator.Allocate(size);
    }

    void BlockAllocator::Clear()
    {
        m_allocator.Clear();
    }
}