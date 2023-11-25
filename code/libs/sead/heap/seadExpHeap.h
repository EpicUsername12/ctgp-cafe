#pragma once

#include "heap/seadHeap.h"

namespace sead {
class ExpHeap : public Heap {
    SEAD_RTTI_OVERRIDE(ExpHeap, Heap)

    class MemBlock {
      public:
        static MemBlock* FindManageArea(void* ptr);

        static u32 getOffset() {
            return offsetof(MemBlock, mListNode);
        }

      protected:
        ListNode mListNode;
        u16 mHeapCheckTag;
        u16 mOffset;
        size_t mSize;
    };

  public:
    enum AllocMode {
        FirstFit = 0,
        BestFit = 1,
    };

    enum FindFreeBlockMode {
        Auto = 0,
        FromFreeList = 1,
        ByIteratingMemBlock = 2,
    };

    // FIXME: incomplete
    enum FindMode {};

    static ExpHeap* create(size_t size, const SafeString& name, Heap* parent, s32 alignment, HeapDirection direction,
                           bool);
    static ExpHeap* create(void* address, size_t size, const SafeString& name, bool);

    static ExpHeap* tryCreate(size_t size, const SafeString& name, Heap* parent, HeapDirection direction, bool);
    static ExpHeap* tryCreate(void* ptr, size_t size, sead::SafeString const& name, bool);

    static size_t getManagementAreaSize(s32);

    void destroy();
    size_t adjust();
    void* tryAlloc(size_t size, s32 alignment);
    void free(void* ptr);
    void* resizeFront(void* p_void, size_t size);
    void* resizeBack(void* p_void, size_t size);
    void* tryRealloc(void* ptr, size_t size, s32 alignment);
    void freeAll();
    uintptr_t getStartAddress() const;
    uintptr_t getEndAddress() const;
    size_t getSize() const;
    size_t getFreeSize() const;
    size_t getMaxAllocatableSize(int alignment) const;
    bool isInclude(const void* p_void) const;
    bool isEmpty() const;
    bool isFreeable() const;
    bool isResizable() const;
    bool isAdjustable() const;
    void dump() const;

    virtual s32 destroyAndGetAllocatableSize(s32);
    virtual void setFindFreeBlockMode(FindFreeBlockMode mode);

    AllocMode getAllocMode() const {
        return (AllocMode)mAllocMode;
    }
    void setAllocMode(AllocMode mode) {
        mAllocMode = (u8)mode;
    }

    void dumpFreeList() const;
    void dumpUseList() const;

    void checkFreeList() const;
    bool tryCheckFreeList() const;
    void checkUseList() const;
    bool tryCheckUseList() const;

  protected:
    ExpHeap(const SafeString& name, Heap* parent, void* address, size_t size, HeapDirection direction, bool);
    ~ExpHeap();

    static void doCreate(ExpHeap*, Heap*);

    static void createMaxSizeFreeMemBlock_(ExpHeap*);
    MemBlock* findFreeMemBlockFromHead_(size_t, FindMode) const;
    MemBlock* findFreeMemBlockFromHead_(size_t, s32, FindMode) const;
    MemBlock* findFreeMemBlockFromTail_(size_t, FindMode) const;
    MemBlock* findFreeMemBlockFromTail_(size_t, s32, FindMode) const;
    MemBlock* findLastMemBlockIfFree_();
    MemBlock* findFirstMemBlockIfFree_();

    void pushToUseList_(MemBlock*);
    void pushToFreeList_(MemBlock*);

    size_t adjustBack_();
    size_t adjustFront_();

    MemBlock* allocFromHead_(size_t);
    MemBlock* allocFromHead_(size_t, s32);
    MemBlock* allocFromTail_(size_t);
    MemBlock* allocFromTail_(size_t, s32);

    static s32 compareMemBlockAddr_(const MemBlock*, const MemBlock*);

    u8 mAllocMode;
    u8 mFindFreeBlockMode;
    OffsetList<MemBlock> mFreeList;
    OffsetList<MemBlock> mUseList;
};
} // namespace sead

static_assert(sizeof(sead::ExpHeap) == 0xB8, "Class size doesn't match game class size");