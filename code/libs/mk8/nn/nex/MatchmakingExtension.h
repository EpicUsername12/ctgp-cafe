#ifndef _NN_NEX_MM_EXT_H
#define _NN_NEX_MM_EXT_H

#include <mk8/nn/nex/Matchmaking.h>
#include <mk8/nn/nex/Protocol.h>
#include <mk8/nn/nex/Types.h>

namespace nn {
namespace nex {

class MatchmakeExtensionProtocolClient : public nn::nex::ClientProtocol {
  public:
};

class MatchmakeExtensionClient : public nn::nex::MatchMakingClient {
    int field_A0;
    char field_A4;
    char field_A5;
    char field_A6;
    char field_A7;
    nn::nex::MatchmakeExtensionProtocolClient m_ClientProtocol;
    int field_F0;
    int field_F4;
};

} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::MatchmakeExtensionProtocolClient) == 0x48, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::MatchmakeExtensionClient) == 0xF8, "Class doesn't match game class size");

#endif