#ifndef _MK8_ENL_NET_INFO_H
#define _MK8_ENL_NET_INFO_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace enl {

class NetworkInfoManager {
  public:
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    uint8_t gap1C[60];
    char field_58[496];
    char field_248[20];
    int vtable;
};

} // namespace enl

static_assert(sizeof(enl::NetworkInfoManager) == 0x260, "Class doesn't match game class size");

#endif
