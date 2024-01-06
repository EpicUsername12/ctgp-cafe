#ifndef _UI_CONTROL_CUP_BUTTON_HPP
#define _UI_CONTROL_CUP_BUTTON_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

#include <heap/seadDisposer.h>
#include <mk8/ui/Control_Button.h>
#include <mk8/ui/UIInput.h>

namespace ui {
class Control_CupButton : public Control_Button {
  public:
    char field_F4;
    char field_F5;
    int cupId;
    nw::lyt::Pane* cupIconPane;
    nw::lyt::Pane* tktIconPane;
    nw::lyt::Pane* dlcReservationPane;
    nw::lyt::Pane* dlcShopPane;
    nw::lyt::Pane* dlcNewIconPane;

    Control_CupButton(bool unk);
};
} // namespace ui

static_assert(sizeof(ui::Control_CupButton) == 0x110, "Class doesn't match game class size");

#endif