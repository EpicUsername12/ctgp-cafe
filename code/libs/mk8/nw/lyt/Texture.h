#ifndef _NW_LYT_TEXTURE_HPP
#define _NW_LYT_TEXTURE_HPP

typedef class TextureInfo TextureInfo;

#include <stdint.h>
#include <basis/seadTypes.h>

typedef struct GX2Surface__ {
    int dimension;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    uint32_t num_mips;
    int format;
    int aa;
    int use;
    uint32_t image_size;
    void* image_data;
    uint32_t mip_size;
    void* mip_data;
    int tile;
    uint32_t swizzle;
    uint32_t align;
    uint32_t pitch;
    uint32_t mip_offset[13];
} GX2Surface__;

typedef struct GX2Texture__ {
    GX2Surface__ surface;
    uint32_t viewFirstMip;
    uint32_t viewNumMips;
    uint32_t viewFirstSlice;
    uint32_t viewNumSlices;
    uint32_t compMap;
    uint32_t regs[5];

} GX2Texture__;

namespace nw {
namespace lyt {

class TextureInfo {
  public:
    uint32_t unk;
    uint16_t width;
    uint16_t height;
    uint8_t format; // special lyt format, use conversion function to get
                    // GX2SurfaceFormat
    GX2Texture__ texture;

    inline TextureInfo() {
        width = 0;
        height = 0;
    }
};

int LoadTexture(TextureInfo* textureInfo, const void* filePtr, uint32_t size);

} // namespace lyt
} // namespace nw

static_assert(sizeof(nw::lyt::TextureInfo) == 0xA8, "Class doesn't match game class size");

#endif