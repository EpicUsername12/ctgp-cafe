#pragma once

#include <cafe.h>
#include <string.h>

#include <vector>
#include <string>

#include <heap/seadExpHeap.h>
#include <mk8/nw/lyt/Texture.h>

#include "utils/ScopedHeapUsage.h"
#include "utils/Filesystem.h"
#include "MessageRedirection.h"

namespace ctgp {

#define CTDEF_BIN_FILEPATH "ctdef.bin"
#define CUP0_MESSAGE_ID_CUP_NAME(fileCupIdx) (13337 + fileCupIdx)
#define TRK0_MESSAGE_ID_TRACK_NAME(fileCupIdx, trackIdx) (15337 + (fileCupIdx * 4) + trackIdx)
#define TRK0_MESSAGE_ID_RETRO_NAME(fileCupIdx, trackIdx) (15937 + (fileCupIdx * 4) + trackIdx)
#define TRK0_MESSAGE_ID_AUTHOR_NAME(fileCupIdx, trackIdx) (16937 + (fileCupIdx * 4) + trackIdx)

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
    uint32_t num_cups;

    struct CupInfo {
        wchar_t name[16];
        char icon[128];
    };

    CupInfo cups[];
};

struct TRK0Section_V1 {

    static const uint32_t SectionMagic = 'TRK0';

    uint32_t magic;
    uint32_t num_tracks;

    struct TrackInfo {

        enum EFlags {
            TRACK_NO_RETRO_NAME = 1 << 0,
        };

        EFlags flags;
        wchar_t retro_name[6];
        wchar_t name[20];
        wchar_t author[20];
        char directory[32];
        char track_pic[128];
    } __attribute__((aligned(4)));

    TrackInfo tracks[];
};

class CustomTrackManager {

    static const uint16_t MaximumMajorVersion = 1;
    static const uint16_t MaximumMinorVersion = 0;
    static const uint32_t MaximumCups = 24;
    static const uint32_t MaximumTracks = 4 * MaximumCups;

    enum EParseError {
        PARSE_OK = 0,
        CTDF_WRONG_MAGIC,
        CTDF_UNSUPPORTED_MAJOR_VERSION,
        CTDF_UNSUPPORTED_MINOR_VERSION,
        CTIF_WRONG_MAGIC,
        CUP0_WRONG_MAGIC,
        CUP0_TOO_MANY_CUPS,
        TRK0_WRONG_MAGIC,
    };

    EParseError ParseCTDFSection_V1(const CTDFSection_V1* data);
    EParseError ParseCTIFSection_V1(const CTIFSection_V1* data);
    EParseError ParseCUP0Section_V1(const CUP0Section_V1* data);
    EParseError ParseTRK0Section_V1(const TRK0Section_V1* data);

  public:
    CustomTrackManager() : m_ctdf(nullptr), m_ctif(nullptr), m_cup0(nullptr), m_trk0(nullptr) {
    }

    bool ParseDefinitionFile_V1(const char* path);

    CTDFSection_V1* m_ctdf;
    CTIFSection_V1* m_ctif;
    CUP0Section_V1* m_cup0;
    TRK0Section_V1* m_trk0;

    struct Track : public TRK0Section_V1::TrackInfo {
        nw::lyt::TextureInfo* track_pic_texture;
    };

    struct Cup : public CUP0Section_V1::CupInfo {
        nw::lyt::TextureInfo* icon_texture;
        std::vector<Track> tracks;
    };

    std::vector<Cup> cups;

    static CustomTrackManager* s_Instance;
    static CustomTrackManager* GetInstance();

    static const char* ParseErrorToString(EParseError error) {
        switch (error) {
            case PARSE_OK:
                return "No error";
            case CTDF_WRONG_MAGIC:
                return "CTDF wrong magic";
            case CTDF_UNSUPPORTED_MAJOR_VERSION:
                return "CTDF unsupported major version";
            case CTDF_UNSUPPORTED_MINOR_VERSION:
                return "CTDF unsupported minor version";
            case CTIF_WRONG_MAGIC:
                return "CTIF wrong magic";
            case CUP0_WRONG_MAGIC:
                return "CUP0 wrong magic";
            case CUP0_TOO_MANY_CUPS:
                return "CUP0 too many cups";
            case TRK0_WRONG_MAGIC:
                return "TRK0 wrong magic";
            default:
                return "Unknown error";
        }
    }
};

extern sead::ExpHeap* g_CTGPHeap;
sead::ExpHeap* GetExtensionHeap();

void InitCourseRedirection();

} // namespace ctgp