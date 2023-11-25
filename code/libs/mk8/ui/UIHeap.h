#ifndef _UI_UIHEAP_HPP
#define _UI_UIHEAP_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

#include <heap/seadHeap.h>

#include <prim/seadRuntimeTypeInfo.h>
#include <container/seadPtrArray.h>
#include <mk8/ui/UILoader.h>
#include <mk8/ui/UIPageManager.h>

namespace ui {

class UIHeapManager {

  public:
    sead::Buffer<UIHeap*> heaps;

    UIHeapManager();

    UIHeap* getHeap(int id) {
        return *this->heaps.get(id);
    }
};

// ctor -> .text:0253B4A8
// vtable -> .rodata:100D0870
class UIHeap {

    SEAD_RTTI_BASE(UIHeap)

  public:
    sead::Heap* heap;
    UILoader* loader;
    int smallestLytId;
    int highestLytId;
    char adjustHeap;
    char initializePending;
    char field_12;
    char field_13;
    int drawer;
    UIPageManager* pageManager;
    char isInitialized;
    char field_1D;
    char field_1E;
    char field_1F;
    int heapIdx;

    UIHeap();
};
} // namespace ui

static_assert(sizeof(ui::UIHeapManager) == 0x8, "Class doesn't match game class size");
static_assert(sizeof(ui::UIHeap) == 0x28, "Class doesn't match game class size");

#endif