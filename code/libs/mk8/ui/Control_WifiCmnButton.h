#ifndef _UI_CONTROL_WIFI_CMN_BUTTON_HPP
#define _UI_CONTROL_WIFI_CMN_BUTTON_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIFlow.h>
#include <mk8/ui/Control_Button.h>
#include <mk8/ui/UICapTexture.h>
#include <mk8/ui/UIInput.h>

#include <mk8/ui/Pages/Page_WifiTop.h>

namespace ui {
class Control_WifiCmnButton : public Control_Button {

    SEAD_RTTI_OVERRIDE_DECL(Control_WifiCmnButton, Control_Button)

  public:
    UICapTexture field_F4;
    Control_WifiCmnButton(Page_WifiTop* page) {
        this->flow = (UIFlow*)&page->flow0;
    }

    Control_WifiCmnButton(UIPage* page) {
        this->flow = page->flow;
    }
};

} // namespace ui

static_assert(sizeof(ui::Control_WifiCmnButton) == 0x114, "Class doesn't match game class size");

#endif