#ifndef _UI_PAGE_TITLETOP_H
#define _UI_PAGE_TITLETOP_H

#include <mk8/ui/UIControl.h>
#include <mk8/ui/UIFlow.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UIPage.h>
#include <mk8/ui/UIEngine.h>

namespace ui {

class Page_TitleTop : public UIPage {
  public:
    static const int ID = 24;

    UIFlow flow;
    Flow_Scene flowScene;
    Flow_Open flowOpen;
    Input_Key inputKey;
    Input_Timer inputTimer;
    UIControl* mainControl;
    int TitleEffect;
    int field_258;
    int field_25C;
    int field_260;
    int field_264;
    int field_268;
    int field_26C;
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;
    nw::lyt::Pane* logoPane;
    nw::lyt::Pane* pressABtnPane;

    virtual void onCreate();

    static Page_TitleTop* getPage() {
        return (Page_TitleTop*)ui::UIEngine::spInstance->pageManager->getPage(ID);
    }
};

} // namespace ui

static_assert(sizeof(ui::Page_TitleTop) == 0x28C, "Class doesn't match game class size");

#endif // _UI_PAGE_TITLETOP_H