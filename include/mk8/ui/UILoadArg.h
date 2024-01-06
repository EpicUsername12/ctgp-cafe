#pragma once

#include <heap/seadHeap.h>
#include <prim/seadSafeString.h>

namespace ui {
class UILoadArg {
  public:
    UILoadArg();

    sead::SafeString mFilepath;
    int mLoaderID;
    size_t mAlignement;
    size_t* mOutSize;
    sead::Heap* mHeap;
    char field_18;

    virtual void unk1();
    virtual void unk2();
};

static_assert(sizeof(ui::UILoadArg) == 0x20, "Class doesn't match game class size");

} // namespace ui