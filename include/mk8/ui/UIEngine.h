#ifndef _UI_UIENGINE_HPP
#define _UI_UIENGINE_HPP

#include <basis/seadTypes.h>
#include <stdint.h>
#include <container/seadPtrArray.h>
#include <heap/seadExpHeap.h>

#include <mk8/ui/UIEngineArg.h>
#include <mk8/ui/UILoader.h>
#include <mk8/ui/UIPageManager.h>
#include <mk8/ui/UILoadArg.h>

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
    sead::ExpHeap* sysHeap;
    sead::ExpHeap* rootHeap;

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

    virtual void onLoad(ui::UILoadArg& loadArg) {
    }
    virtual void calcImpl() {
    }
    virtual void onDraw_() {
    }

    virtual void onCreateManager() = 0;
    virtual void onSetupPlayer() = 0;
    virtual void onSetupHeap() = 0;
    virtual void onSetupScreen() {
    }

    void onSetupMultiFilter();
    void setupHeap_(ui::UIHeap* heap, int id);

    UIEngine();

    static UIEngine* spInstance;
    static UIEngine* mpInstance;
};

class UIEngineEx : public UIEngine {

    SEAD_RTTI_OVERRIDE(UIEngineEx, UIEngine)
  private:
    int field_A8;
    int field_AC;
    int field_B0;
    char field_B4;
    char field_B5;

  public:
    virtual void onLoad(ui::UILoadArg& loadArg);
    virtual void calcImpl();
    virtual void onDraw_();
    virtual void onCreateManager();
    virtual void onSetupPlayer();
    virtual void onSetupHeap();
    virtual void onSetupScreen();
    virtual void onSetupMultiFilter();
};

}; // namespace ui

static_assert(sizeof(ui::UIEngine) == 0xA8, "Class doesn't match game class size");
static_assert(sizeof(ui::UIEngineEx) == 0xB8, "Class doesn't match game class size");

#endif