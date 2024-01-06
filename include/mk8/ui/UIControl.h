#ifndef _UI_UI_CONTROL_HPP
#define _UI_UI_CONTROL_HPP

namespace ui {
typedef class UIControl UIControl;
}

#include <mk8/nw/lyt/Pane.h>
#include <mk8/nw/lyt/Texture.h>
#include <container/seadBuffer.h>
#include <prim/seadSafeString.h>
#include <mk8/ui/UIAnimator.h>
#include <mk8/ui/UILoader.h>
#include <mk8/ui/UIInput.h>

namespace ui {
typedef class UIPage UIPage;
} // namespace ui

#include <mk8/ui/UIEvent.h>
#include <prim/seadRuntimeTypeInfo.h>

namespace ui {
class UIControl {

    SEAD_RTTI_BASE(UIControl)

  public:
    int field_00;
    UIPage* ownerPage;
    UILoader* loader;
    UIControl* parentControl;
    int flags; // bit 0x100 = is parent layout
    int field_14;
    int field_18;
    sead::Buffer<UIAnimator*> animators;
    int field_24;
    sead::PtrArrayImpl array;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    nw::lyt::Pane* pane;

    UIControl();

    nw::lyt::Pane* findPane(sead::SafeStringBase<char> const& str) const;

    void setMessage(sead::SafeStringBase<char> const& str, int messageId);

    void setMessage(sead::SafeStringBase<char> const& str, wchar_t const* messageTxt);

    void setMessage(nw::lyt::Pane* pane, int messageId);

    void setMessage(int messageId);

    void setTexture(nw::lyt::Pane* pane, nw::lyt::TextureInfo const* textureInfo, unsigned int unk);

    void setVisible(nw::lyt::Pane* pane, bool isVisible);

    void pushInput(UIInput&);

    UIAnimator* createAnimator(int index, int numAnims);

    virtual void onCreate() {
    }
    virtual void onInit() {
    }
    virtual void onIn() {
    }
    virtual void onCalc() {
    }
    virtual void onInput() {
    }
    virtual void onFollowCursor(void* Page_Cursor, int);
    virtual bool onVisibleCursor() const {
        return 1;
    }
    virtual void onDrawDummy(void* UIDrawInfo) {
    }
    virtual void onHandler(ui::UIEvent const& event) {
    }
};
} // namespace ui

static_assert(sizeof(ui::UIControl) == 0x58, "Class doesn't match game class size");

#endif