#ifndef _UI_TEX_LOADER_H
#define _UI_TEX_LOADER_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadBuffer.h>
#include <mk8/ui/UIThread.h>

#include <mk8/mush/types.h>

namespace ui {
class UITexLoader {
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
    void* vtable;

    UITexLoader();
};

// ctor is inlined... cannot call it
class UIPartsTex : public UITexLoader {
  public:
    sead::Buffer<void*> buffer0;
    sead::Buffer<void*> buffer1;
    sead::Buffer<void*> buffer2;
    sead::Buffer<void*> buffer3;
    sead::Buffer<void*> buffer4;
    sead::Buffer<void*> buffer5;
    sead::Buffer<void*> buffer6;
};

// ctor is inlined... cannot call it
class UICharaTex : public UITexLoader {
  public:
    sead::Buffer<void*> buffer0;
    sead::Buffer<void*> buffer1;
};

// ctor is inlined... cannot call it
class UICourseTex : public UITexLoader {
  public:
    sead::Buffer<void*> buffer0;

    nw::lyt::TextureInfo* getTex(mush::ECourseID id) const;
};

class UICompeTex {
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

    UICompeTex();
};

class UIStampTex : public UITexLoader {
  public:
    int field_3C;
};

class UIMiiTex {
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
    UIMiiThread miiThread;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;

    UIMiiTex();
};
} // namespace ui

static_assert(sizeof(ui::UITexLoader) == 0x3C, "Class doesn't match game class size");
static_assert(sizeof(ui::UIPartsTex) == 0x74, "Class doesn't match game class size");
static_assert(sizeof(ui::UICharaTex) == 0x4C, "Class doesn't match game class size");
static_assert(sizeof(ui::UICourseTex) == 0x44, "Class doesn't match game class size");
static_assert(sizeof(ui::UICompeTex) == 0x24, "Class doesn't match game class size");
static_assert(sizeof(ui::UIStampTex) == 0x40, "Class doesn't match game class size");
static_assert(sizeof(ui::UIMiiTex) == 0x13C, "Class doesn't match game class size");

#endif