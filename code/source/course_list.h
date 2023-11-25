#pragma once

#include <basis/seadTypes.h>
#include <mk8/mush/types.h>

namespace ctgp {

enum CupID {
    MUSHROOM = 0,
    SHELL,
    FLOWER,
    BANANA,
    STAR,
    LEAF,
    SPECIAL,
    THUNDER,
    DLC02,
    DLC03,
    DLC04,
    DLC05,

    WAVE_1_0,
    WAVE_1_1,
    WAVE_2_0,
    WAVE_2_1,
    WAVE_3_0,
    WAVE_3_1,
    WAVE_4_0,
    WAVE_4_1,
    WAVE_5_0,
    WAVE_5_1,
    WAVE_6_0,
    WAVE_6_1,
};

struct CourseEntry {
    const mush::EGrandPrixID m_cup;  // Cup the custom track belongs to
    const int m_course;              // Index of the track in the cup
    const wchar_t* m_trackRetroName; // Retro name of the track (Example: "Wii" or "N64"), can be NULL
    const wchar_t* m_trackName;      // Track name (Example: "Luigi Circuit")
    const wchar_t* m_author;         // Author of the track, can be NULL
    const char* m_path; // Path to the directory (relative to "/content/course", example: "Gu_MarioCircuit")
};

// clang-format off
const CourseEntry g_CustomCourseEntries[] = {
    { mush::EGrandPrixID::MUSHROOM,     0,  L"CTGP",    L"CTGP Test",       L"Rambo6Glaz",      "Gct_Test" },
    { mush::EGrandPrixID::MUSHROOM,     1,  L"CTGP",    L"CTGP Test 2",     L"Rambo6Glaz",      "Gct_Test2" },
};

const size_t g_CustomCourseEntriesCount = sizeof(g_CustomCourseEntries) / sizeof(CourseEntry);
static_assert(g_CustomCourseEntriesCount <= 96, "Custom course size limit reached (96)");

// clang-format on

} // namespace ctgp
