#ifndef _UI_PAGE_COURSE_ROULETTE_WIFI_H
#define _UI_PAGE_COURSE_ROULETTE_WIFI_H

#include <mk8/ui/UIControl.h>
#include <mk8/ui/UIFlow.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UIPage.h>
#include <mk8/ui/UIEngine.h>

#include <mk8/ui/Control_CourseRoulette.h>

namespace ui {

class Page_CourseRouletteWiFi : public UIPage {

  public:
    class SpinnerInfo {
        int numPlayers;
        int resultPlayerIdx;
        int minimumSpins;
        int slowSpins;
        int mediumSpins;
        int fastDelay;
        int delayAdder;
        int mediumDelay;
        int finalDelay;

      public:
        SpinnerInfo() {
            this->numPlayers = 12;
            this->minimumSpins = 38;
            this->resultPlayerIdx = 6;
            this->slowSpins = 2;
            this->delayAdder = 1;
            this->mediumSpins = 8;
            this->mediumDelay = 20;
            this->finalDelay = 45;
            this->fastDelay = 5;
        }
    };

    class Spinner : public SpinnerInfo {
        int totalSpins;
        int currentPlayer;
        int currentSpin;
        int spinDelay;
        int timer;

      public:
        Spinner() {
            this->timer = 0;
            this->totalSpins = 0;
            this->spinDelay = 0;
            this->currentPlayer = 0;
            this->currentSpin = 0;
        }
    };

    static const int ID = 65;

    Flow_Scene flowScene0;
    UIFlow flowIn0; // ui::Flow_In
    Flow_Open flowOpen0;
    Flow_Reset flowReset0;
    UIControl* mainControl;
    int lobbyListWin;
    nw::lyt::Pane* tMessagePane;
    sead::FixedPtrArray<Control_CourseRoulette, 12> rouletteBtns;
    Spinner spinner;
    int indices[12];
    int indexNum;
    int field_2BC;
    int rouletteSoundId;

    virtual void onCreate();

    static Page_CourseRouletteWiFi* getPage() {
        return (Page_CourseRouletteWiFi*)ui::UIEngine::spInstance->pageManager->getPage(ID);
    }
};

} // namespace ui

static_assert(sizeof(ui::Page_CourseRouletteWiFi::SpinnerInfo) == 0x24, "Class doesn't match game class size");
static_assert(sizeof(ui::Page_CourseRouletteWiFi::Spinner) == 0x38, "Class doesn't match game class size");
static_assert(sizeof(ui::Page_CourseRouletteWiFi) == 0x2C4, "Class doesn't match game class size");

#endif // _UI_PAGE_TITLETOP_H