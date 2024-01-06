#ifndef _UI_UIFLOW_HPP
#define _UI_UIFLOW_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

#include <prim/seadRuntimeTypeInfo.h>
#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>

// ctor -> .text:02539828
// vtable -> .rodata:100D0260
namespace ui {

class UIFlow {

    SEAD_RTTI_BASE(UIFlow)

  public:
    int prevPageIdx;
    int nextPageIdx;
    int field_8;
    int field_C;
    int field_10;
    int field_14;

    UIFlow();
};

class Flow_Reset : UIFlow {

    SEAD_RTTI_OVERRIDE(Flow_Reset, UIFlow)

  public:
    int field_20;

    Flow_Reset();
};

class Flow_Open : UIFlow {

    SEAD_RTTI_OVERRIDE(Flow_Open, UIFlow)

  public:
    //! TODO: UIDialogReq
    // 0x1c -> 0x60 = UIDialogReq
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

    Flow_Open();
};

class UISceneFlow : public UIFlow {

    SEAD_RTTI_OVERRIDE(UISceneFlow, UIFlow)

  public:
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

    UISceneFlow();
};

class Flow_Scene : public UISceneFlow {

    SEAD_RTTI_OVERRIDE(Flow_Scene, UISceneFlow)

  public:
    int field_94;

    Flow_Scene();
};
} // namespace ui

static_assert(sizeof(ui::UIFlow) == 0x1C, "Class doesn't match game class size");
static_assert(sizeof(ui::Flow_Reset) == 0x20, "Class doesn't match game class size");
static_assert(sizeof(ui::Flow_Open) == 0x6C, "Class doesn't match game class size");
static_assert(sizeof(ui::UISceneFlow) == 0x94, "Class doesn't match game class size");
static_assert(sizeof(ui::Flow_Scene) == 0x98, "Class doesn't match game class size");

#endif