#ifndef _UI_PAGE_PAGE_COURSE_WIFI_H
#define _UI_PAGE_PAGE_COURSE_WIFI_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIEngine.h>
#include <mk8/ui/Pages/Page_CourseVS.h>

namespace ui {

class Page_CourseWiFi : public Page_CourseVS {

  public:
    UIFlow flowCrossFade;
    Flow_Open flowOpen2;
    Flow_Reset flowReset2;
    ui::Control_Button* randomBtn;
    bool field_408;

  public:
    static const int ID = 63;

    static Page_CourseWiFi* getPage() {
        return (Page_CourseWiFi*)UIEngine::spInstance->pageManager->getPage(ID);
    }

    virtual void onHandler(ui::UIEvent const& event);
    virtual void onCreate();
};

} // namespace ui

static_assert(sizeof(ui::Page_CourseWiFi) == 0x40C, "Class doesn't match game class size");

#endif