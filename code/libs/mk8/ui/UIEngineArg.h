#ifndef _UI_UIENGINEARG_HPP
#define _UI_UIENGINEARG_HPP

typedef class UIEngineArg UIEngineArg;

#include <basis/seadTypes.h>
#include <stdint.h>

namespace ui {

class UIEngineArg {
    //! TODO: sead::ExpHeap
    /* sead::ExpHeap* */ int sysHeap;
    /* sead::ExpHeap* */ int rootHeap;
    int numDrawers;
    int numGroups;
    int numLayouts;
    int numAltLayouts;
    int numLytRefs;
    const char* shader_lyt_path;  // "shaders/lyt_BuildinShader.gsh" @ 0x100A46FC
    const char* shader_font_path; // "shaders/font_BuildinShader.gsh" @ 0x100A471C
    int field24;

    UIEngineArg();
};

} // namespace ui

static_assert(sizeof(ui::UIEngineArg) == 0x28, "Class doesn't match game class size");

#endif