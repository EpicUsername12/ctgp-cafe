#ifndef _UI_EVENT_H
#define _UI_EVENT_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIPage.h>
#include <mk8/ui/UICursor.h>

namespace ui {

class DefaultEvent {
  public:
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
};

class CursorEvent {
  public:
    int field_00;
    int field_04;
    UIControl* sourceControl;
    int controlId;
    UICursor* cursor;
    int unk;
};

class UIEvent {
  public:
    union {
        DefaultEvent default_event;
        CursorEvent cursor_event;
    };

    int playerIdx;
    int m_InputValue;
    int field_20;
};
} // namespace ui

static_assert(sizeof(ui::UIEvent) == 0x24, "Class doesn't match game class size");

#endif