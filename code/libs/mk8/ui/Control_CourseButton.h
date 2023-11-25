#ifndef _UI_CONTROL_COURSE_BUTTON_HPP
#define _UI_CONTROL_COURSE_BUTTON_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

#include <heap/seadDisposer.h>
#include <mk8/ui/Control_Button.h>
#include <mk8/ui/UICourse.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UICapTexture.h>

namespace ui {
class Control_CourseButton : public Control_Button {
  public:
    int courseId;
    nw::lyt::TextBox* classicNameTextPane;
    nw::lyt::TextBox* courseNameTextPane;
    nw::lyt::Pane* courseMoviePane;
    nw::lyt::Pane* coursePictPane;
    char boolean;
    char field_109;
    char field_10A;
    char field_10B;

    Control_CourseButton(bool unk);

    void setCourse(CourseInfo const& courseInfo, UICapTexture* texture);
};
} // namespace ui

static_assert(sizeof(ui::Control_CourseButton) == 0x10c, "Class doesn't match game class size");

#endif