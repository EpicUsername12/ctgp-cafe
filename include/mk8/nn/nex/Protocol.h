#ifndef _NN_NEX_PROT_H
#define _NN_NEX_PROT_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/nn/nex/Types.h>

namespace nn {
namespace nex {

class Protocol : public nn::nex::SystemComponent {
  public:
    uint16_t field_24;
    uint16_t field_26;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    char field_38;
    char field_39;
    char field_3A;
    char field_3B;
    int field_3C;
    int field_40;

    virtual ~Protocol();
};

class ClientProtocol : public nn::nex::Protocol {
  public:
    int field_44;

    virtual ~ClientProtocol();
};

} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::Protocol) == 0x44, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::ClientProtocol) == 0x48, "Class doesn't match game class size");

#endif