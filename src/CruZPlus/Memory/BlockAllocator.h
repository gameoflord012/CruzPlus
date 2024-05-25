#pragma once

#include <box2d/b2_block_allocator.h>

namespace CruZ
{
    class BlockAllocator
    {
    public:
        BlockAllocator(/* args */);
        ~BlockAllocator();

        void *Allocate(int32 size);
        template <typename FreeType>
        void Free(FreeType *);
        void Clear();

    private:
        b2BlockAllocator m_allocator;
    };

    template <typename FreeType>
    void BlockAllocator::Free(FreeType *p)
    {
        m_allocator.Free(p, sizeof(FreeType));
    }
}
