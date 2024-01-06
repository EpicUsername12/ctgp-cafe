#pragma once

#include <ui/UIPage.h>

namespace ctgp {

class Page_CTGP_DistributionSelector : public ui::UIPage {

    SEAD_RTTI_OVERRIDE(Page_CTGP_DistributionSelector, ui::UIPage)

  public:
    static const ui::UIPage::EUIPageID ID = (ui::UIPage::EUIPageID)(ui::UIPage::Credit + 1);

    static Page_CTGP_DistributionSelector* s_Instance;
    static Page_CTGP_DistributionSelector* getPage() {
        if (!s_Instance) {}

        return s_Instance;
    }

    Page_CTGP_DistributionSelector();

  private:
    virtual void onCreate() override;
    virtual void onInit() override;
};

} // namespace ctgp