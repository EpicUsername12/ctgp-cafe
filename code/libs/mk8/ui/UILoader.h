#ifndef _UI_UILOADER_HPP
#define _UI_UILOADER_HPP

namespace ui {
typedef class UILoader UILoader;
typedef class UIHeap UIHeap;
} // namespace ui

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/nw/lyt/Resource.h>
#include <container/seadListImpl.h>
#include <container/seadPtrArray.h>
#include <mk8/ui/UIHeap.h>

#define MK8_UI_LOADER_CTOR 0x0253C9C0
#define MK8_UI_LOADER_GET_HEAP 0x0253CC78
#define MK8_UI_LOADER_GET_MESSAGE 0x0253D30C
#define MK8_UI_LOADER_FIND_MESSAGE 0x0253D194

struct LoaderStruct1 {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
};

namespace ui {
// ctor -> .text:0253C9C0
// vtable -> .rodata:100D0A94
class UILoader {

  public:
    UIHeap* heap;
    UIHeap* dependentHeaps[5];
    int numDependentHeaps;
    LoaderStruct1 s1;
    LoaderStruct1 s2;
    sead::ListImpl list1;
    sead::ListImpl list2;
    int field_5C;
    int field_60;
    nw::lyt::ResourceAccessor* resourceAccessor;

    UILoader();

    UIHeap* getHeap_(int heapIdx);

    wchar_t* findMessage_(int messageId);

    /* If you want to get a message, use this function, it will try to find with
     * all 5 heaps */
    wchar_t* getMessage(int messageId);

    virtual void doRTTI() {
    }
};
} // namespace ui

static_assert(sizeof(ui::UILoader) == 0x6C, "Class doesn't match game class size");

#endif