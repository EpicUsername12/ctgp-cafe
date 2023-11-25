#ifndef _UI_PAGE_PAGE_WIFI_TOP_H
#define _UI_PAGE_PAGE_WIFI_TOP_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIControl.h>
#include <mk8/ui/UIEngine.h>
#include <mk8/ui/UIFlow.h>
#include <mk8/ui/UIInput.h>
#include <mk8/ui/UIPage.h>

namespace ui {
class Page_WifiTop : public UIPage {
  public:
    static const int ID = 51;

    UIFlow flow0;
    UIFlow flow1;
    int field_100;

    virtual void onCreate();

    static Page_WifiTop* getPage() {
        return (Page_WifiTop*)ui::UIEngine::spInstance->pageManager->getPage(ID);
    }
};
} // namespace ui

static_assert(sizeof(ui::Page_WifiTop) == 0x104, "Class doesn't match game class size");

#endif