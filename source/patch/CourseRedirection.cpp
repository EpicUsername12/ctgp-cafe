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

bool CustomTrackManager::ParseDefinitionFile_V1(const char* path, bool panicOnFail) {
    // Load the file
    const uint8_t* filedata = utils::fs::LoadFileEx(path, nullptr, 0x1000);

    PANIC_UNIMPLEMENTED();
    return true;
}

void InitCourseRedirection() {

    // Load the CUP0 file if it exists
    { PANIC_UNIMPLEMENTED(); }
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