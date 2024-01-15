#include "CourseRedirection.h"

namespace ctgp {

static uint8_t s_CTGPHeapBuffer[0x1000000] __attribute__((aligned(0x1000)));
sead::ExpHeap* g_CTGPHeap = nullptr;

CustomTrackManager* CustomTrackManager::s_Instance = nullptr;
CustomTrackManager* CustomTrackManager::GetInstance() {
    if (CustomTrackManager::s_Instance == nullptr) {
        CustomTrackManager::s_Instance = new CustomTrackManager();
    }

    return CustomTrackManager::s_Instance;
}

bool loadTextureInfo(nw::lyt::TextureInfo** textureInfo, const char* path, bool panicOnFail) {
    uint32_t outFileSize = 0;
    uint8_t* fileData = utils::fs::LoadFileEx(path, &outFileSize, 0x1000, panicOnFail);

    *textureInfo = new nw::lyt::TextureInfo();
    if (!nw::lyt::LoadTexture(*textureInfo, fileData, outFileSize)) {
        MEMFreeToDefaultHeap(fileData);
        delete *textureInfo;
        *textureInfo = nullptr;

        return false;
    }

    return true;
}

CustomTrackManager::EParseError CustomTrackManager::ParseCTDFSection_V1(const CTDFSection_V1* data) {
    if (data->magic != CTDFSection_V1::SectionMagic) {
        return CTDF_WRONG_MAGIC;
    }

    if (data->ver_major > CustomTrackManager::MaximumMajorVersion) {
        return CTDF_UNSUPPORTED_MAJOR_VERSION;
    }

    if (data->ver_minor > CustomTrackManager::MaximumMinorVersion) {
        return CTDF_UNSUPPORTED_MINOR_VERSION;
    }

    this->m_ctdf = (CTDFSection_V1*)data;
    return PARSE_OK;
}

CustomTrackManager::EParseError CustomTrackManager::ParseCTIFSection_V1(const CTIFSection_V1* data) {
    if (data->magic != CTIFSection_V1::SectionMagic) {
        return CTIF_WRONG_MAGIC;
    }

    this->m_ctif = (CTIFSection_V1*)data;
    return PARSE_OK;
}

CustomTrackManager::EParseError CustomTrackManager::ParseCUP0Section_V1(const CUP0Section_V1* data) {
    if (data->magic != CUP0Section_V1::SectionMagic) {
        return CUP0_WRONG_MAGIC;
    }

    if (data->num_cups > MaximumCups) {
        return CUP0_TOO_MANY_CUPS;
    }

    this->m_cups.resize(data->num_cups);
    for (uint32_t i = 0; i < data->num_cups; i++) {
        this->m_cups[i].icon_texture = nullptr;
        memcpy(this->m_cups[i].name, data->cups[i].name, sizeof(this->m_cups[i].name));
        memcpy(this->m_cups[i].icon, data->cups[i].icon, sizeof(this->m_cups[i].icon));

        loadTextureInfo(&this->m_cups[i].icon_texture, this->m_cups[i].icon, true);

        MessageRedirector::GetInstance()->addMessage(CUP0_MESSAGE_ID_CUP_NAME(i), this->m_cups[i].name, false);
    }

    this->m_cup0 = (CUP0Section_V1*)data;
    return PARSE_OK;
}

CustomTrackManager::EParseError CustomTrackManager::ParseTRK0Section_V1(const TRK0Section_V1* data) {
    if (data->magic != TRK0Section_V1::SectionMagic) {
        return TRK0_WRONG_MAGIC;
    }

    int currentCup = 0;
    Cup* cup = &this->m_cups[currentCup];
    for (uint32_t i = 0; i < data->num_tracks; i++) {
        if (this->m_cups[currentCup].tracks.size() >= 4) {
            cup = &this->m_cups[++currentCup];
        }

        Track track;

        track.flags = data->tracks[i].flags;
        memcpy(track.retro_name, data->tracks[i].retro_name, sizeof(track.retro_name));
        memcpy(track.name, data->tracks[i].name, sizeof(track.name));
        memcpy(track.author, data->tracks[i].author, sizeof(track.author));
        memcpy(track.directory, data->tracks[i].directory, sizeof(track.directory));
        memcpy(track.track_pic, data->tracks[i].track_pic, sizeof(track.track_pic));

        loadTextureInfo(&track.track_pic_texture, track.track_pic, true);

        cup->tracks.push_back(track);

        MessageRedirector::GetInstance()->addMessage(TRK0_MESSAGE_ID_AUTHOR_NAME(currentCup, i), cup->tracks[i].author, false);
        MessageRedirector::GetInstance()->addMessage(TRK0_MESSAGE_ID_TRACK_NAME(currentCup, i), cup->tracks[i].name, false);
        if (!(cup->tracks[i].flags & Track::TRACK_NO_RETRO_NAME)) {
            MessageRedirector::GetInstance()->addMessage(TRK0_MESSAGE_ID_RETRO_NAME(currentCup, i), cup->tracks[i].retro_name, false);
        }
    }

    this->m_trk0 = (TRK0Section_V1*)data;
    return PARSE_OK;
}

bool CustomTrackManager::ParseDefinitionFile_V1(const char* path) {
    // Load the file
    const uint8_t* filedata = utils::fs::LoadFileEx(path, nullptr, 0x1000);

    CTDFSection_V1* ctdf = (CTDFSection_V1*)(filedata);
    EParseError error = this->ParseCTDFSection_V1(ctdf);
    if (error != PARSE_OK) {
        PANIC("Failed to parse CTDF section! (%s)\nPlease contact the developer of your distribution.\n", ParseErrorToString(error));
    }

    CTIFSection_V1* ctif = (CTIFSection_V1*)(filedata + sizeof(CTDFSection_V1));
    error = this->ParseCTIFSection_V1(ctif);
    if (error != PARSE_OK) {
        PANIC("Failed to parse CTIF section! (%s)\nPlease contact the developer of your distribution.\n", ParseErrorToString(error));
    }

    CUP0Section_V1* cup0 = (CUP0Section_V1*)(filedata + sizeof(CTDFSection_V1) + sizeof(CTIFSection_V1));
    error = this->ParseCUP0Section_V1(cup0);
    if (error != PARSE_OK) {
        PANIC("Failed to parse CUP0 section! (%s)\nPlease contact the developer of your distribution.\n", ParseErrorToString(error));
    }

    TRK0Section_V1* trk0 = (TRK0Section_V1*)((uint8_t*)cup0 + (sizeof(CUP0Section_V1) + sizeof(CUP0Section_V1::CupInfo) * cup0->num_cups));
    error = this->ParseTRK0Section_V1(trk0);
    if (error != PARSE_OK) {
        PANIC("Failed to parse TRK0 section! (%s)\nPlease contact the developer of your distribution.\n", ParseErrorToString(error));
    }

    return true;
}

static bool s_IsCourseRedirectionInitialized = false;

void InitCourseRedirection() {

    // Load the CUP0 file if it exists

    if (s_IsCourseRedirectionInitialized)
        return;

    /* Patch save file */
    sys::SaveDataManager* saveDataMgr = sys::SystemEngine::getEngine()->mSaveDataMgr;
    void* saveDataPtr = saveDataMgr->getRealUserSaveDataPtr(nn_act_GetSlotNo());

    /* Unlock all 8 base cups */
    for (int i = 0; i < 8; i++)
        *saveDataMgr->calculateFlagPtrFromOffset(saveDataPtr, 0x1A28 + i) = 3;

    {
        utils::ScopedHeapUsage heapUsage(GetExtensionHeap());
        CustomTrackManager::GetInstance()->ParseDefinitionFile_V1(CTDEF_BIN_FILEPATH);
        s_IsCourseRedirectionInitialized = true;
    }
}

sead::ExpHeap* GetExtensionHeap() {
    if (!g_CTGPHeap) {
        g_CTGPHeap = sead::ExpHeap::tryCreate(s_CTGPHeapBuffer, sizeof(s_CTGPHeapBuffer), "CTGP Heap", false);
        if (!g_CTGPHeap) {
            PANIC("Failed to create CTGP Heap!\nPlease contact the developer of CTGP-Café (Rambo6Glaz).");
        }
    }

    return g_CTGPHeap;
}

// ============================================================================
// Game hooks
// ============================================================================

struct Page_CourseExtension {
    ui::Control_CupButton* mUpperCupButtons[6];
    ui::Control_NXBtnL* mBtnL;
    ui::Control_NXBtnR* mBtnR;
    int mCupPage;

    Page_CourseExtension() {
        for (int i = 0; i < 6; i++)
            this->mUpperCupButtons[i] = nullptr;

        this->mBtnL = nullptr;
        this->mBtnR = nullptr;
        this->mCupPage = 0;
    }
};

static Page_CourseExtension* s_PageCourseExtensions = nullptr;

Page_CourseExtension* GetPageCourseExtension(ui::UIPage* page) {
    if (s_PageCourseExtensions == nullptr) {
        s_PageCourseExtensions = new Page_CourseExtension[3]();
    }

    if (page->pageID == ui::UIPage::CourseGP) {
        return &s_PageCourseExtensions[0];
    } else if (page->pageID == ui::UIPage::CourseVS) {
        return &s_PageCourseExtensions[1];
    } else if (page->pageID == ui::UIPage::WiFi_Course) {
        return &s_PageCourseExtensions[2];
    }

    return s_PageCourseExtensions;
}

#define BACKGROUND_ANIM_IDX_BgColor 6
#define BACKGROUND_ANIMATOR(idx) (ui::Page_Bg::getPage()->animators[idx])

#define COURSE_ANIM_IDX_CupInOut 6
#define COURSE_ANIM_IDX_IconVisibility 7
#define COURSE_ANIM_IDX_BoardColor 8
#define COURSE_ANIM_IDX_Loop 9
#define COURSE_ANIM_IDX_BtnDown 10

extern "C" void hook_Page_Bg_onCreate(ui::Page_Bg* _this) {
    _this->onCreate();

    ui::UIAnimator* animator = CREATE_ANIMATOR(_this, BACKGROUND_ANIM_IDX_BgColor, 1);
    BIND_ANIM(animator, 0, "BgColor");
}

extern "C" void hook_Page_Course_initialize(ui::Page_CourseBase* _this) {

    _this->initialize();

    utils::ScopedHeapUsage shu(GetExtensionHeap());
    Page_CourseExtension* ext = GetPageCourseExtension(_this);

    bool unk = (_this->pageID == ui::Page_CourseGP::ID);
    for (int i = 0; i < 6; i++) {
        static const char* s_ExtendedCupPaneNames[] = {
            "L_CupIcon_12", "L_CupIcon_13", "L_CupIcon_14", "L_CupIcon_15", "L_CupIcon_16", "L_CupIcon_17"
        };

        ext->mUpperCupButtons[i] = new ui::Control_CupButton(unk);
        _this->createControl_(ext->mUpperCupButtons[i], _this->mainControl, s_ExtendedCupPaneNames[i]);
    }

    ext->mBtnL = new ui::Control_NXBtnL(ui::Control_NXBtnL::TEXTURE_L);
    ext->mBtnR = new ui::Control_NXBtnR(ui::Control_NXBtnR::TEXTURE_R);
    _this->createControl_(ext->mBtnL, _this->mainControl, "L_LBtn_00");
    _this->createControl_(ext->mBtnR, _this->mainControl, "L_RBtn_00");

    ui::UIAnimator* animator = _this->createAnimator(COURSE_ANIM_IDX_CupInOut, _this->mainControl, 2);
    animator->bind(0, "CupIn");
    animator->bind(1, "CupOut");

    animator = _this->createAnimator(COURSE_ANIM_IDX_IconVisibility, _this->mainControl, 1);
    animator->bind(0, "ChangeIconVisible");

    animator = _this->createAnimator(COURSE_ANIM_IDX_BoardColor, _this->mainControl, 2);
    animator->bind(0, "BGBoardChangeWtoB");
    animator->bind(1, "BGBoardChangeBtoW");

    animator = _this->createAnimator(COURSE_ANIM_IDX_Loop, _this->mainControl, 1);
    animator->bind(0, "Loop");

    animator = _this->createAnimator(COURSE_ANIM_IDX_BtnDown, _this->mainControl, 2);
    animator->bind(0, "LBtnDown");
    animator->bind(1, "RBtnDown");

    static const int s_CupRealIDs[12] = {
        0, 1, 2, 3, 8, 10, 4, 5, 6, 7, 9, 11, // Nintendo does it like that, but inlined.
    };

    _this->animators[COURSE_ANIM_IDX_IconVisibility]->stop(0, 1.0f);
    for (int i = 0; i < 12; i++)
        _this->cupIcons[i]->animators[2]->stop(0, s_CupRealIDs[i]); // 2 == IconChange

    for (int i = 0; i < 6; i++)
        ext->mUpperCupButtons[i]->animators[2]->stop(0, i + 12);
}

} // namespace ctgp