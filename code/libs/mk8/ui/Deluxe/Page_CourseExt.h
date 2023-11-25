#ifndef _UI_PAGE_COURSE_EXT_H
#define _UI_PAGE_COURSE_EXT_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/ui/Deluxe/Control_NXBtnL.h>
#include <mk8/ui/Deluxe/Control_NXBtnR.h>
#include <mk8/ui/Pages/Page_CourseGP.h>
#include <mk8/ui/Pages/Page_CourseVS.h>
#include <mk8/ui/Pages/Page_CourseWiFi.h>

namespace ui {

extern const char* sExtendedCupPaneNames[];

class Page_CourseExt {
  public:
    ui::Control_CupButton* mUpperCupButtons[6];
    ui::Control_NXBtnL* mBtnL;
    ui::Control_NXBtnR* mBtnR;
    int mCupPage;
    bool mIsInChargerPageAnim;

    void Constructor() {
        for (int i = 0; i < 6; i++)
            this->mUpperCupButtons[i] = nullptr;

        this->mBtnL = nullptr;
        this->mBtnR = nullptr;
        this->mIsInChargerPageAnim = false;
        this->mCupPage = 0;
    }

    Page_CourseExt() {
        this->Constructor();
    }
};

class Page_CourseGP_Ext : public Page_CourseGP {
  public:
    Page_CourseExt mExtension;
};

class Page_CourseVS_Ext : public Page_CourseVS {
  public:
    Page_CourseExt mExtension;
};

class Page_CourseWiFi_Ext : public Page_CourseWiFi {
  public:
    Page_CourseExt mExtension;
};

static Page_CourseExt* getPageExtension(ui::Page_CourseBase* _this) {
    ui::Page_CourseExt* ext = nullptr;
    if (_this->pageID == ui::Page_CourseGP::ID) {
        ext = &((ui::Page_CourseGP_Ext*)_this)->mExtension;
    } else if (_this->pageID == ui::Page_CourseVS::ID) {
        ext = &((ui::Page_CourseVS_Ext*)_this)->mExtension;
    } else if (_this->pageID == ui::Page_CourseWiFi::ID) {
        ext = &((ui::Page_CourseWiFi_Ext*)_this)->mExtension;
    }
    return ext;
}

} // namespace ui

#endif