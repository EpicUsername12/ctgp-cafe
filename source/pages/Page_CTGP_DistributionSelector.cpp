#include "Page_CTGP_DistributionSelector.h"

// =========================================================
// TODO: Implement the Page_CTGP_DistributionSelector class/page/layout
// =========================================================

namespace ctgp {

Page_CTGP_DistributionSelector::Page_CTGP_DistributionSelector() {
}

void Page_CTGP_DistributionSelector::onCreate() {
    ui::UIControl* mainControl = new ui::UIControl();
    this->loadControl_(mainControl, 5, "mn_Ctgp_DistribSelect_00.bflyt");
}

void Page_CTGP_DistributionSelector::onInit() {
}

} // namespace ctgp