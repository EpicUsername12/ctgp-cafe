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
class Page_WiFi_Top : public UIPage {
  public:
    static const EUIPageID ID = UIPage::WiFi_Top;

    UIFlow flow0;
    UIFlow flow1;
    int field_100;

    virtual void onCreate();

    static Page_WiFi_Top* getPage() {
        return (Page_WiFi_Top*)ui::UIEngine::spInstance->pageManager->getPage(ID);
    }
};
} // namespace ui

static_assert(sizeof(ui::Page_WiFi_Top) == 0x104, "Class doesn't match game class size");

#endif