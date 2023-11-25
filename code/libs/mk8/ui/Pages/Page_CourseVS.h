#ifndef _UI_PAGE_PAGE_COURSE_VS_H
#define _UI_PAGE_PAGE_COURSE_VS_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIEngine.h>
#include <mk8/ui/Pages/Page_CourseBase.h>

namespace ui {
class Page_CourseVS : public Page_CourseBase {

    SEAD_RTTI_OVERRIDE(Page_CourseVS, UIPage)

    Flow_Open flowOpen;
    Flow_Reset flowReset;
    UICursorLink* cursorLink; //< Custom cursor link derived class

  public:
    static const int ID = 44;

    static Page_CourseVS* getPage() {
        return (Page_CourseVS*)UIEngine::spInstance->pageManager->getPage(ID);
    }

    virtual void onHandler(ui::UIEvent const& event);
    virtual void onCreate();
};
} // namespace ui

// sub_25BB058
// sub_2537F38

static_assert(sizeof(ui::Page_CourseVS) == 0x35C, "Class doesn't match game class size");

#endif