#pragma once

#include <cafe.h>
#include <string.h>

#include <vector>
#include <string>

#include <heap/seadExpHeap.h>
#include <mk8/nw/lyt/Texture.h>

#include "utils/Filesystem.h"
#include "MessageRedirection.h"

namespace ctgp {

#define CUP0_MESSAGE_ID_CUP_NAME(fileCupIdx) (13337 + fileCupIdx)
#define CUP0_MESSAGE_ID_TRACK_NAME(fileCupIdx, trackIdx) (15337 + (fileCupIdx * 4) + trackIdx)
#define CUP0_MESSAGE_ID_RETRO_NAME(fileCupIdx, trackIdx) (15937 + (fileCupIdx * 4) + trackIdx)

void InitCourseRedirection();

struct CTDFSection_V1 {

    static const uint32_t SectionMagic = 'CTDF';

    uint32_t magic;
    uint16_t ver_major;
    uint16_t ver_minor;
    uint8_t pad[0x20 - 8];
};

struct CTIFSection_V1 {

    static const uint32_t SectionMagic = 'CTIF';

    uint32_t magic;
    wchar_t name[48];
    wchar_t version[16];
    wchar_t author[96];
    wchar_t description[512];
};

struct CUP0Section_V1 {

    static const uint32_t SectionMagic = 'CUP0';

    uint32_t magic;
    wchar_t name[48];
    wchar_t version[16];
    wchar_t author[96];
    wchar_t description[512];
};

class CustomTrackManager {

    static const uint16_t MaximumMajorVersion = 1;
    static const uint16_t MaximumMinorVersion = 0;

  public:
    CustomTrackManager() {
    }

    bool ParseDefinitionFile_V1(const char* path, bool panicOnFail = true);

    CTDFSection_V1* m_ctdf;
    CTIFSection_V1* m_ctif;
    CUP0Section_V1* m_cup0;

    static CustomTrackManager* s_Instance;
    static CustomTrackManager* GetInstance();
};

extern sead::ExpHeap* g_CTGPHeap;
sead::ExpHeap* GetExtensionHeap();

void InitCourseRedirection();

} // namespace ctgp