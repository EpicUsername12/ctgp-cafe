#ifndef _UI_UIENGINE_HPP
#define _UI_UIENGINE_HPP

#include <basis/seadTypes.h>
#include <stdint.h>
#include <container/seadPtrArray.h>

#include <mk8/ui/UIEngineArg.h>
#include <mk8/ui/UILoader.h>
#include <mk8/ui/UIPageManager.h>

namespace ui {

class UIEngine {

    SEAD_RTTI_BASE(UIEngine)

  public:
    ui::UIEngineArg* args;

    //! TODO: UIGraphics
    int UIGraphics;

    //! TODO: UIScreenManager
    int UIScreenManager;

    UIHeapManager* heapManager;
    UIPageManager* pageManager;

    //! TODO: UIPlayerManager
    int UIPlayerManager;
    int fontTagProcessor;

    //! TODO: sead::expHeap
    int sysHeap;
    int rootHeap;

    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;

    //! TODO: UICursorSelector
    int UICursorSelector;

    sead::PtrArrayImpl array;
    int arrayBuf[16];

    UIEngine();

    static UIEngine* spInstance;

    static UIEngine* mpInstance;
};
}; // namespace ui

static_assert(sizeof(ui::UIEngine) == 0xA8, "Class doesn't match game class size");

#endif