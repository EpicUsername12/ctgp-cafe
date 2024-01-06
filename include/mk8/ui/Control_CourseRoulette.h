#ifndef _UI_CONTROL_COURSE_ROULETTE_H
#define _UI_CONTROL_COURSE_ROULETTE_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <heap/seadDisposer.h>
#include <mk8/ui/Control_Button.h>
#include <mk8/ui/UICourse.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UICapTexture.h>

namespace ui {
class Control_CourseRoulette : public UIControl {
  public:
    nw::lyt::Pane* pCourseRoulettePane;
    nw::lyt::Pane* nMiiIconPane;
    nw::lyt::Pane* pMiiDummyPane;
    int courseId;
    char field_68;
};
} // namespace ui

static_assert(sizeof(ui::Control_CourseRoulette) == 0x6C, "Class doesn't match game class size");

#endif