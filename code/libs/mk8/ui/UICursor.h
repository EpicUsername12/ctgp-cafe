#ifndef _UI_CURSOR_H
#define _UI_CURSOR_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/nw/lyt/Resource.h>
#include <container/seadBuffer.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UIPage.h>

namespace ui {
typedef class UICursorLink UICursorLink;
typedef class UICursor UICursor;
} // namespace ui

namespace ui {

class UIPlayerCursor {
  public:
    int field_00;
    char field_04;
    int field_08;
    int cursorPosition;
    int field_10;
    int field_14;
    float field_18;
    float field_1C;
    float field_20;
    char field_24;

    UIPlayerCursor();
};

class UICursorLink {
  public:
    UICursor* cursor;
    int field_04;
    int field_08;
    char field_0C;
    char field_0D;
    void* vtbl;

    UICursorLink();

    int next(uint32_t input, int position);
};

class UICursor {
  public:
    UIPlayerCursor playerCursors[4];
    Input_Key inputKey;
    int field_D4;
    int field_D8;
    UIPage* page;
    UICursorLink* cursorLink;
    sead::Buffer<void*> buffer;
    int field_EC;

    UICursor();

    void setLink(ui::UICursorLink* link);

    int next_(int r4, int r5, uint32_t input);

    int selectOn(int, int, unsigned int, bool);

    virtual void doVtable() {
    }
};

class CursorLink_CourseMatrix : public UICursorLink {
  public:
    // sead::Vector2<int>
    int m_SizeX;
    int m_SizeY;

    char field_1C;
    int field_20;

    CursorLink_CourseMatrix();
};
} // namespace ui

static_assert(sizeof(ui::UIPlayerCursor) == 0x28, "Class doesn't match game class size");
static_assert(sizeof(ui::UICursorLink) == 0x14, "Class doesn't match game class size");
static_assert(sizeof(ui::UICursor) == 0xF0, "Class doesn't match game class size");
static_assert(sizeof(ui::CursorLink_CourseMatrix) == 0x24, "Class doesn't match game class size");

#endif