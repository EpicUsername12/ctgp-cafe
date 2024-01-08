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

    this->cups.resize(data->num_cups);
    for (uint32_t i = 0; i < data->num_cups; i++) {
        this->cups[i].icon_texture = nullptr;
        memcpy(this->cups[i].name, data->cups[i].name, sizeof(this->cups[i].name));
        memcpy(this->cups[i].icon, data->cups[i].icon, sizeof(this->cups[i].icon));

        loadTextureInfo(&this->cups[i].icon_texture, this->cups[i].icon, true);

        MessageRedirector::GetInstance()->addMessage(CUP0_MESSAGE_ID_CUP_NAME(i), this->cups[i].name, false);
    }

    this->m_cup0 = (CUP0Section_V1*)data;
    return PARSE_OK;
}

CustomTrackManager::EParseError CustomTrackManager::ParseTRK0Section_V1(const TRK0Section_V1* data) {
    if (data->magic != TRK0Section_V1::SectionMagic) {
        return TRK0_WRONG_MAGIC;
    }

    int currentCup = 0;
    Cup* cup = &this->cups[currentCup];
    for (uint32_t i = 0; i < data->num_tracks; i++) {
        if (this->cups[currentCup].tracks.size() >= 4) {
            cup = &this->cups[++currentCup];
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

} // namespace ctgp