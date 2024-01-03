#ifndef _UI_PAGE_PAGE_COURSE_WIFI_H
#define _UI_PAGE_PAGE_COURSE_WIFI_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/UIEngine.h>
#include <mk8/ui/Pages/Page_CourseVS.h>

namespace ui {

class Page_WiFi_Course : public Page_CourseVS {

  public:
    UIFlow flowCrossFade;
    Flow_Open flowOpen2;
    Flow_Reset flowReset2;
    ui::Control_Button* randomBtn;
    bool field_408;

  public:
    static const EUIPageID ID = UIPage::WiFi_Course;

    static Page_WiFi_Course* getPage() {
        return (Page_WiFi_Course*)UIEngine::spInstance->pageManager->getPage(ID);
    }

    virtual void onHandler(ui::UIEvent const& event);
    virtual void onCreate();
};

} // namespace ui

static_assert(sizeof(ui::Page_WiFi_Course) == 0x40C, "Class doesn't match game class size");

#endif