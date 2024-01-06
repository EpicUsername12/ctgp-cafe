#ifndef _UI_UIPAGE_MGR_HPP
#define _UI_UIPAGE_MGR_HPP

namespace ui {
typedef class UIPageManager UIPageManager;
}

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <mk8/ui/UILoader.h>
#include <mk8/ui/UIPage.h>

namespace ui {
class UIPageManager {
  public:
    sead::Buffer<UIPage*> layouts;
    bool unk0;
    sead::PtrArray<void*> array0;
    sead::PtrArrayImpl unk1;
    UIPage* currentFocusedPage;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;

    UIPageManager();

    void set(int pageId, UIPage* page);

    int setFocus(int index, UIPage* page);

    int setFocusOff(int index);

    int attach(UIPage* page, bool unk);

    UIPage* getPage(int id) {
        return *this->layouts.get(id);
    }
};
} // namespace ui

static_assert(sizeof(ui::UIPageManager) == 0x3C, "Class doesn't match game class size");

#endif