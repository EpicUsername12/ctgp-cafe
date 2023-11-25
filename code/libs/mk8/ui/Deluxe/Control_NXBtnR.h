#ifndef _UI_CONTROL_NXBTN_R_H
#define _UI_CONTROL_NXBTN_R_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <heap/seadDisposer.h>
#include <mk8/ui/Control_Button.h>
#include <mk8/ui/UICourse.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UICapTexture.h>

namespace ui {
class Control_NXBtnR : public UIControl {

    SEAD_RTTI_OVERRIDE(Control_NXBtnR, UIControl)

  public:
    enum Type {
        TEXTURE_R = 0,
        TEXTURE_SR = 1,
        TEXTURE_ZR = 2,
    };

    Type mType;
    Input_Key mInputKey;

    Control_NXBtnR(Type type) {
        mType = type;
    }

    virtual void onCreate() {

        this->mInputKey.requiredInput = MK8_INPUT_R;
        this->ownerPage->pushInput(this->mInputKey);

        UIAnimator* BtnIconAnimator = this->createAnimator(0, 1);
        BtnIconAnimator->bind(0, "BtnIconPtn");

        this->animators[0]->stop(0, (float)this->mType);
    }

    virtual void onIn() {
    }

    virtual void onCalc() {
    }
};
} // namespace ui

#endif