#include "BlockAllocator.h"

#include <box2d/b2_block_allocator.h>

namespace CruZ
{
    BlockAllocator::BlockAllocator()
    {
        m_allocator = new b2BlockAllocator;
    }

    BlockAllocator::~BlockAllocator()
    {
        delete m_allocator;
    }

    void *BlockAllocator::Allocate(int size)
    {
        return m_allocator->Allocate(size);
    }

    void BlockAllocator::Clear()
    {
        m_allocator->Clear();
    }
}