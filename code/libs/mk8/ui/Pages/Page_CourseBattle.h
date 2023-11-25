#ifndef _UI_PAGE_PAGE_COURSE_BT_H
#define _UI_PAGE_PAGE_COURSE_BT_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/Control_CourseButton.h>
#include <mk8/ui/Control_CupButton.h>
#include <mk8/ui/UICapTexture.h>
#include <mk8/ui/UIControl.h>
#include <mk8/ui/UIFlow.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UIPage.h>
#include <mk8/ui/UIEngine.h>

namespace ui {
class Page_CourseBattle : public UIPage {
  public:
    static const int ID = 45;

    Flow_Open m_FlowOpen0;
    UIFlow m_FlowCrossFade;
    Flow_Open m_FlowOpen1;
    Flow_Reset m_FlowReset;

    char field_1BC;
    UIControl* m_BattleCourseBflyt;
    Control_CourseButton* m_CourseButtons[8];
    CursorLink_CourseMatrix* m_CourseMatrix;
    UICapTexture m_CapTexture;

    static Page_CourseBattle* getPage() {
        return (Page_CourseBattle*)UIEngine::spInstance->pageManager->getPage(ID);
    }

    virtual void onCreate();
    virtual void onHandler(ui::UIEvent const& event);
};
} // namespace ui

static_assert(sizeof(ui::Page_CourseBattle) == 0x228, "Class doesn't match game class size");

#endif