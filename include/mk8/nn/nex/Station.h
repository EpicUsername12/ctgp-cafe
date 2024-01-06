#ifndef _NN_NEX_STATION_H
#define _NN_NEX_STATION_H

#include <mk8/nn/nex/Types.h>

namespace nn {
namespace nex {

class InetAddress {
  public:
    uint16_t field_0;
    uint16_t m_Port;
    uint32_t m_Address;
    int field_8;
    int field_C;
    int vtable;
};

class StationURL {
    nn::nex::InetAddress* m_InetAddress;
    int m_UrlType;
    nn::nex::qMap<nn::nex::String, uint32_t> intParams;
    nn::nex::qMap<nn::nex::String, nn::nex::String> stringParams;
    nn::nex::qMap<nn::nex::String, nn::nex::String> stringParams2;
    nn::nex::String* m_StringURL;
    char field_30;
    char field_31;
    char field_32;
    char field_33;
    int vtable;
};

} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::InetAddress) == 0x14, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::StationURL) == 0x38, "Class doesn't match game class size");

#endif