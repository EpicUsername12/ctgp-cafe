#ifndef _NW_LYT_RESOURCE_ACC_HPP
#define _NW_LYT_RESOURCE_ACC_HPP

namespace nw {
namespace lyt {
typedef class MultiArcResourceAccessor MultiArcResourceAccessor;
typedef class ResourceAccessor ResourceAccessor;
} // namespace lyt
} // namespace nw

#include <mk8/ui/UILoader.h>
#include <container/seadBuffer.h>

struct NewLinkedList {
    int size;
    void* mPrev;
    void* mNext;
};

struct SARC_Header {
    uint32_t magic; // 'SARC'
    uint16_t header_len;
    uint16_t bom;
    uint32_t file_size;
    uint32_t data_offset;
    uint16_t version;
    uint16_t reserved;
};

struct SFAT_Entry {
    uint32_t hash;
    uint32_t flags : 8, name_offset : 24;
    uint32_t file_start;
    uint32_t file_end;
};

struct SFAT_Header {
    uint32_t magic; // 'SFAT'
    uint16_t header_len;
    uint16_t node_count;
    uint32_t hash_key;
    SFAT_Entry entries[];
};

struct Yaz0_Header {
    uint32_t magic; // 'Yaz0'
    uint32_t uncompressed_size;
    uint32_t reserved[2];
};

namespace nw {
namespace lyt {

class MultiArcResourceAccessor {
  public:
    void* vtable;
    NewLinkedList array1;
    NewLinkedList array2;
    NewLinkedList array3;

    void* GetResource(uint32_t resType, char const* resName, size_t* pSize);
};

//! TODO: Move UIResourceAccessor back to <mk8/ui>

class ResourceAccessor {
  public:
    nw::lyt::MultiArcResourceAccessor mArcRA;
    ui::UILoader* loader; // wtf
};

class ArcExtractor {

  public:
    SARC_Header* mArchiveHeader;
    SFAT_Header* mSFATHeader;
    const char* mFNTData;
    sead::Buffer<SFAT_Entry> mEntries;
    uint8_t* mDataBlock;
    bool mIsLittleEndian;

    ArcExtractor();

    uint32_t ConvertPathToEntryID(const char* path);

    static void* GetResourceSub(nw::lyt::ArcExtractor*, char const*, uint32_t, char const*, size_t*);
};

} // namespace lyt
} // namespace nw

#endif