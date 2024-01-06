#ifndef _UI_UIINPUT_HPP
#define _UI_UIINPUT_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/nw/lyt/Resource.h>
#include <container/seadListImpl.h>
#include <container/seadPtrArray.h>

namespace ui {
typedef class UIPage UIPage;
} // namespace ui

#include <mk8/ui/UIControl.h>
#include <mk8/ui/UIPage.h>

namespace ui {

class UIInput {

  public:
    UIPage* boundedPage1;
    UIControl* boundedControl;
    UIPage* boundedPage2;
    int field_0C;
    int field_10;
    int requiredInput;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;

    UIInput();

    virtual void vtbl() {
    }
};

class Input_Key : public UIInput {
  public:
    int field_2C;

    Input_Key();
};

class Input_Timer : public UIInput {
  public:
    int field_2C;
    int field_30;
    int field_34;

    Input_Timer();
};

class Input_Touch : public UIInput {
  public:
    int array[4];
    int field_3C;

    Input_Touch();
};

} // namespace ui

#define MK8_INPUT_A (1 << 0)
#define MK8_INPUT_B (1 << 1)
#define MK8_INPUT_X (1 << 3)
#define MK8_INPUT_Y (1 << 4)

#define MK8_INPUT_L (1 << 11)
#define MK8_INPUT_R (1 << 12)

#define MK8_INPUT_PLUS (1 << 3)
#define MK8_INPUT_MINUS (1 << 4)

#define MK8_INPUT_UP (1 << 5)
#define MK8_INPUT_BOTTOM (1 << 6)
#define MK8_INPUT_LEFT (1 << 7)
#define MK8_INPUT_RIGHT (1 << 8)

static_assert(sizeof(ui::UIInput) == 0x2C, "Class doesn't match game class size");
static_assert(sizeof(ui::Input_Key) == 0x30, "Class doesn't match game class size");
static_assert(sizeof(ui::Input_Timer) == 0x38, "Class doesn't match game class size");
static_assert(sizeof(ui::Input_Touch) == 0x40, "Class doesn't match game class size");

#endif