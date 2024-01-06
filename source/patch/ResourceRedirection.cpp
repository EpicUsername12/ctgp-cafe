#include "ResourceRedirection.h"

namespace ctgp {

struct ArchiveRedirectionBlock {
    uint8_t* data;
    nw::lyt::ArcExtractor* arcExtractor;
};

static ArchiveRedirectionBlock* s_ArchiveData = nullptr;

void InitResourceRedirection() {

    if (!s_ArchiveData) {
        uint32_t arcSize = 0;
        uint8_t* arcFile = utils::fs::LoadFileEx(CTGP_RESOURCE_PATH, &arcSize, 32);

        uint32_t decompSize = sead::SZSDecompressor::getDecompSize(arcFile);
        {
            utils::ScopedHeapUsage shu(GetExtensionHeap());

            s_ArchiveData = new ArchiveRedirectionBlock();
            s_ArchiveData->data = static_cast<uint8_t*>(GetExtensionHeap()->alloc(decompSize, 0x2000));
            s_ArchiveData->arcExtractor = new nw::lyt::ArcExtractor();

            sead::SZSDecompressor::decomp(s_ArchiveData->data, decompSize, arcFile, arcSize);

            LOG("CTGP Archive preparation -> %d\n", s_ArchiveData->arcExtractor->PrepareArchive(s_ArchiveData->data));
        }

        MEMFreeToDefaultHeap(arcFile);
    }
}

// ============================================================================
// Game hooks
// ============================================================================

extern "C" uint8_t* hook_nw_lyt_GetResourceSub(nw::lyt::ArcExtractor* pArc, const char* pDir, uint32_t type,
                                               const char* pName, uint32_t* pOutSize) {

    char typeStr[5];
    memcpy(typeStr, &type, 4);
    typeStr[4] = 0;

    char filepath[256];
    if (pDir[0] != '.' || pDir[1]) {
        snprintf(filepath, sizeof(filepath), "%s/%s/%s", pDir, typeStr, pName);
    } else {
        snprintf(filepath, sizeof(filepath), "%s/%s", typeStr, pName);
    }

    nw::lyt::ArcExtractor* extractor = pArc;
    int entryId = s_ArchiveData->arcExtractor->ConvertPathToEntryID(filepath);
    if (entryId == -1) {
        entryId = pArc->ConvertPathToEntryID(filepath);
        if (entryId == -1) {
            return nullptr;
        }
    } else {
        extractor = s_ArchiveData->arcExtractor;
    }

    nw::lyt::ArcFileInfo outInfo;
    uint8_t* filedata = extractor->GetFileFast(entryId, &outInfo);

    if (pOutSize)
        *pOutSize = outInfo.mLength;

    return filedata;
}

extern "C" void hook_ui_UIEngineEx_onSetupHeap(ui::UIEngineEx* _this) {
    _this->onSetupHeap();

    InitResourceRedirection();
}

} // namespace ctgp