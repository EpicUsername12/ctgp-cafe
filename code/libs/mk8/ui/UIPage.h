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
    enum EUIPageID {
        DebugMenuSeq = 0,
        DebugMessage = 1,
        Boot = 2,
        Reset = 3,
        Fader = 4,
        FaderPause = 5,
        FaderPlayer = 6,
        Dialog = 7,
        Unlock = 8,
        Keyboard = 9,
        Cursor = 10,
        MenuUnder = 11,
        Lyt_RuleList = 12,
        CatalogLogin = 13,
        CatalogOpen = 14,
        Lyt_Mode = 15,
        Lyt_CharaPartsS = 16,
        Lyt_CharaPartsSW = 17,
        Lyt_CharaPartsM2 = 18,
        Lyt_CharaPartsM4 = 19,
        Lyt_ScrollList = 20,
        Lyt_ScrollList2 = 21,
        Lyt_GhostScrollList = 22,
        Bg = 23,
        TitleTop = 24,
        TitleSelect = 25,
        TitleDemo = 26,
        Record = 27,
        ModeS = 28,
        ModeM = 29,
        Class = 30,
        CharaPresent = 31,
        PartsPresent = 32,
        CharaList0 = 33,
        CharaList1 = 34,
        CharaList2 = 35,
        CharaList3 = 36,
        CharaS = 37,
        CharaM = 38,
        PartsS = 39,
        PartsM = 40,
        Rule = 41,
        Team = 42,
        CourseGP = 43,
        CourseVS = 44,
        CourseBattle = 45,
        Ghost = 46,
        GhostScrollList = 47,
        RaceStart = 48,
        WiFi_Select2P = 49,
        WiFi_Login = 50,
        WiFi_Top = 51,
        WiFi_Mode = 52,
        WiFi_Rule = 53,
        WiFi_Matching = 54,
        WiFi_CharaS = 55,
        WiFi_CharaM = 56,
        WiFi_PartsS = 57,
        WiFi_PartsM = 58,
        WiFi_RaceOrLive = 59,
        WiFi_Mii = 60,
        WiFi_MiiComment = 61,
        WiFi_CourseRandom = 62,
        WiFi_Course = 63,
        WiFi_CourseBattle = 64,
        WiFi_Roulette = 65,
        WiFi_FriendList = 66,
        WiFi_FriendInfo = 67,
        WiFi_CommentList = 68,
        WiFi_FriendReq = 69,
        WiFi_FriendLobby = 70,
        WiFi_FriendRule = 71,
        WiFi_CompeTop = 72,
        WiFi_CompeInfo = 73,
        WiFi_CompeRanking = 74,
        WiFi_CompeConfirm = 75,
        WiFi_CompeMessage = 76,
        WiFi_CompeSearchRule = 77,
        WiFi_CompeSearchResult = 78,
        WiFi_CompeCreateIcon = 79,
        WiFi_CompeCreateName = 80,
        WiFi_CompeCreateRule = 81,
        WiFi_CompeCreateDescription = 82,
        WiFi_CompeCreateTeamA = 83,
        WiFi_CompeCreateTeamB = 84,
        WiFi_CompeCreateConfirm = 85,
        WiFi_CompeCreateFinish = 86,
        Catalog = 87,
        CatalogDialog = 88,
        Amiibo = 89,
        AmiiboDialog = 90,
        Theater_Menu = 91,
        Theater_Race = 92,
        Theater_Next = 93,
        Theater_Remake = 94,
        Theater_Append = 95,
        E3_Boot = 96,
        E3_Bg = 97,
        E3_Title = 98,
        E3_CharaS = 99,
        E3_CharaM = 100,
        E3_RaceStart = 101,
        E3_Thankyou = 102,
        E3_SoftReset = 103,
        Race = 104,
        Race_Intro = 105,
        Race_Pause = 106,
        Race_Result = 107,
        Race_TAResult = 108,
        Race_Next = 109,
        Race_Watch = 110,
        Race_Replay = 111,
        Race_DRC = 112,
        Race_Title = 113,
        Race_Telop = 114,
        Race_Remake = 115,
        Race_Append = 116,
        Award = 117,
        TrialThankYou = 118,
        Credit = 119,
    };

    class StateInfo {
        int field_00;
        int state;
        int field_08;
        int field_0C;
        sead::Delegate<ui::UIPage> mDelegate;
        bool field_20;
    };

    int layerID;
    EUIPageID pageID;
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