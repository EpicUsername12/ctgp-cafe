#ifndef _UI_PAGE_PAGE_COURSE_GP_H
#define _UI_PAGE_PAGE_COURSE_GP_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIEngine.h>
#include <mk8/ui/Pages/Page_CourseBase.h>

namespace ui {
class Page_CourseGP : public Page_CourseBase {

    SEAD_RTTI_OVERRIDE(Page_CourseGP, UIPage)

  public:
    static const int ID = 43;

    static Page_CourseGP* getPage() {
        return (Page_CourseGP*)UIEngine::spInstance->pageManager->getPage(ID);
    }

    virtual void onHandler(ui::UIEvent const& event);
    virtual void onCreate();
};
} // namespace ui

// sub_25BB058
// sub_2537F38

static_assert(sizeof(ui::Page_CourseGP) == 0x2CC, "Class doesn't match game class size");

#endif