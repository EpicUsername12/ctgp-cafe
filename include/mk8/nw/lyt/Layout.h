#ifndef _NW_LYT_MEM_HPP
#define _NW_LYT_MEM_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

namespace nw {
namespace lyt {

class Layout {
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;

  public:
    static int* s_pAllocator;
    static void* AllocMemory(size_t size, size_t align);
    static void FreeMemory(void*);
};

} // namespace lyt
} // namespace nw

static_assert(sizeof(nw::lyt::Layout) == 0x34, "Class doesn't match game class size");
#endif