
#ifndef _UI_PAGE_PAGE_COURSEBASE_H
#define _UI_PAGE_PAGE_COURSEBASE_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/Control_CourseButton.h>
#include <mk8/ui/Control_CupButton.h>
#include <mk8/ui/UICapTexture.h>
#include <mk8/ui/UIControl.h>
#include <mk8/ui/UIFlow.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UIPage.h>

namespace ui {

extern const int sCupNameIDs[];
extern const int sCupRealIDs[];
extern const char* gCupPaneNames[];

class Page_CourseBase : public UIPage {
  public:
    Flow_Open flowOpen0;
    UIFlow flow0;
    UIFlow flow1;
    Flow_Open flowOpen1;
    Flow_Open flowOpen2;
    Control_CupButton* cupIcons[12];
    Control_CourseButton* courseBtn[4];
    UIControl* bottom_text;
    UIControl* mainControl;
    nw::lyt::Pane* cupNameTextPane;
    int field_290;
    int field_294;
    UICapTexture capTexture;
    float field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    uint8_t field_2C8;
    uint8_t field_2C9;
    uint8_t field_2CA;
    uint8_t field_2CB;

    void LoadPanes(UIControl* mainControl, bool unk);
    void LoadAnimations(UIControl* mainControl);
    void initialize();

    virtual void onCalc();
    virtual void onUpdateComplete();
};
} // namespace ui

static_assert(sizeof(ui::Page_CourseBase) == 0x2CC, "Class doesn't match game class size");

#endif