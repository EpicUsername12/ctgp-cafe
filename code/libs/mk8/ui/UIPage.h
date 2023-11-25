#ifndef _UI_UIPAGE_HPP
#define _UI_UIPAGE_HPP

namespace ui {
typedef class UIPage UIPage;
}

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <prim/seadSafeString.h>
#include <prim/seadDelegate.h>

namespace ui {
typedef class UIHeap UIHeap;
typedef class UIEvent UIEvent;
} // namespace ui

#include <mk8/ui/UIAnimator.h>
#include <mk8/ui/UIControl.h>
#include <mk8/ui/UICursor.h>
#include <mk8/ui/UIFlow.h>
#include <mk8/ui/UIHeap.h>
#include <mk8/ui/UIEvent.h>
#include <mk8/ui/UILoader.h>
#include <mk8/ui/UIInput.h>

namespace ui {

class UIPage {

    SEAD_RTTI_BASE(UIPage)

  public:
    class StateInfo {
        int field_00;
        int state;
        int field_08;
        int field_0C;
        sead::Delegate<ui::UIPage> mDelegate;
        bool field_20;
    };

    int layerID;
    int pageID;
    UIHeap* heap;
    UILoader* loader;
    int field_10;
    int field_14;
    int field_18;
    bool hasControls;
    sead::PtrArray<UIControl> controls;
    bool hasControls2;
    sead::PtrArray<UIControl> controls2;
    int field_3C;
    sead::Buffer<UIAnimator*> animators;
    int animatorCount;
    StateInfo stateInfo;
    int field_70;
    UISceneFlow* flow;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int m_pUIControlSlider;
    int field_90;
    sead::PtrArray<UIInput*> pushedInputs;
    int field_A0;
    int input; // binary value
    int field_A8;
    UICursor* cursor;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;

    UIPage();

    virtual void createCursor();
    virtual void onCreate() {
    }
    virtual void onInit() {
    }
    virtual void onDraw(int flags);
    virtual void onUpdate() {
    }
    virtual void onUpdateIn() {
        this->toRun();
    }
    virtual void onUpdateRun() {
    }
    virtual void onUpdateComplete() {
        this->toOut();
    }
    virtual void onUpdateOut() {
        this->toExit();
    }
    virtual void onCalc() {
    }
    virtual void onCalcAfter() {
    }
    virtual void onPrepare() {
    }
    virtual void onIn() {
    }
    virtual void onRun() {
    }
    virtual void onComplete() {
    }
    virtual void onOut() {
    }
    virtual void onExit() {
    }
    virtual void onDetach() {
    }
    virtual void onStateSub() {
    }
    virtual void somethingToIn(UIFlow* pFlow) {
        this->toIn(flow);
    }
    virtual void onInput() {
    }
    virtual void onHandler(ui::UIEvent const& event) {
    }
    // virtual void onDialogUpdateRun(Page_Dialog &);
    // virtual void onDialogComplete(Page_Dialog &);
    // virtual void onDialogEnd(Page_Dialog &);
    // virtual void onDialogSeq(Page_Dialog &);
    // virtual void onDialogSeqEnd(Page_Dialog &);

    void toExit();
    void toRun();
    void toIn(UIFlow* flow);
    void toOut();

    void loadControl_(UIControl* pOutControl, int unk_5, sead::SafeString const& str);
    void createControl_(UIControl* pOutControl, UIControl* mainControl, sead::SafeString const& str);
    UIAnimator* createAnimator(int idx, UIControl* control, int numAnims);

    void pushInput(ui::UIInput& input);

    void toPage(ui::UIFlow* pFlow);
    void toPrepare(UIFlow* flow);
};
} // namespace ui

static_assert(sizeof(ui::UIPage) == 0xC8, "Class doesn't match game class size");
static_assert(sizeof(ui::UIPage::StateInfo) == 0x24, "Class doesn't match game class size");

#endif