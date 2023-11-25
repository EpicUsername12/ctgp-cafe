
#ifndef _UI_PAGE_PAGE_RACE_H
#define _UI_PAGE_PAGE_RACE_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIPage.h>
#include <mk8/ui/UIEngine.h>

namespace ui {

class Page_Race;

class IWindow {
    virtual void __do_vtbl() {
    }
};

class RaceWindow : public IWindow {
    int mWindowIdx;
    int mSysWindow;
    Page_Race* mPageRace;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    sead::FixedPtrArray<int, 2> fixedPtrArray;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
};

class Page_Race : public UIPage {
  public:
    UIFlow flowIn0;
    UIFlow flowIn1;
    UIFlow flowIn2;
    UIFlow flowIn3;
    UIFlow flowIn4;
    Flow_Scene flowScene0;
    Flow_Scene flowScene1;
    Input_Key inputKey0;
    int field_2B4;
    int field_2B8;
    int field_2BC;
    int field_2C0;
    int field_2C4;
    int field_2C8;
    sead::FixedPtrArray<RaceWindow, 5> fixedPtrControls; // RaceWindow
    char field_2EC;
    char field_2ED;
    char field_2EE;
    char field_2EF;
    char field_2F0;
    char field_2F1;
    char field_2F2;

    virtual void onCreate();
    virtual void onCalc();

    void bindWindowLayout_(ui::UIControl*, ui::RaceWindow*);
    void loadTimeControl_(int id);

  public:
    static const int ID = 104;

    static Page_Race* getPage() {
        return (Page_Race*)UIEngine::spInstance->pageManager->getPage(ID);
    }
};

} // namespace ui

static_assert(sizeof(ui::RaceWindow) == 0x84, "Class doesn't match game class size");
static_assert(sizeof(ui::Page_Race) == 0x2F4, "Class doesn't match game class size");

#endif