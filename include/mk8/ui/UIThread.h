#ifndef _UI_THREAD_H
#define _UI_THREAD_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace ui {
class UIThread {
  public:
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;

    UIThread();
};

class UILoadThread : public UIThread {
  public:
    UILoadThread();
};

class UIMiiThread : public UIThread {
  public:
    UIMiiThread();
};
} // namespace ui

static_assert(sizeof(ui::UIThread) == 0xF4, "Class doesn't match game class size");
static_assert(sizeof(ui::UILoadThread) == 0xF4, "Class doesn't match game class size");
static_assert(sizeof(ui::UIMiiThread) == 0xF4, "Class doesn't match game class size");

#endif