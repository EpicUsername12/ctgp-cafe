#ifndef _PAGE_BG_H
#define _PAGE_BG_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/Control_Button.h>
#include <mk8/ui/UICapTexture.h>
#include <mk8/ui/UIFlow.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UIPage.h>
#include <mk8/ui/UICapTexture.h>
#include <mk8/ui/UIEngine.h>

namespace ui {
class Page_Bg : public UIPage {
  public:
    UIControl* mMainControl;
    UICapTexture mBlurCapTexture;
    int field_EC;
    int field_F0;
    nw::lyt::Pane* mSingle_Pane;
    nw::lyt::Pane* mMulti_Pane;
    nw::lyt::Pane* mMulti_Open0;
    nw::lyt::Pane* mMulti_Open1;
    nw::lyt::Pane* mOnline_Pane;
    nw::lyt::Pane* mPOnSingleY_Pane;
    nw::lyt::Pane* mPOnMultiB_Pane;
    nw::lyt::Pane* mMKTV_Pane;
    nw::lyt::Pane* mP_DLC0_0_Pane;
    nw::lyt::Pane* mP_DLC0_1_Pane;
    nw::lyt::Pane* mP_ReDlc_0_Pane;
    nw::lyt::Pane* mP_ReDlc_1_Pane;
    nw::lyt::Pane* mP_DLC2_0_Pane;
    nw::lyt::Pane* mP_DLC2_1_Pane;
    nw::lyt::Pane* mP_DLC3_0_Pane;
    nw::lyt::Pane* mP_DLC3_1_Pane;
    nw::lyt::Pane* mP_DLC3_2_Pane;
    nw::lyt::Pane* mP_DLC3_3_Pane;
    nw::lyt::Pane* mP_DLC3_4_Pane;
    int field_140;
    int m2DLayout_EffectBase;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;

  public:
    static const int ID = 23;

    virtual void onCreate();

    static Page_Bg* getPage() {
        return (Page_Bg*)UIEngine::spInstance->pageManager->getPage(ID);
    }
};
} // namespace ui

static_assert(sizeof(ui::Page_Bg) == 0x158, "Class doesn't match game class size");

#endif