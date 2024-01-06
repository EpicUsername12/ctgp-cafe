#ifndef _NN_NEX_MM_H
#define _NN_NEX_MM_H

#include <mk8/nn/nex/Protocol.h>
#include <mk8/nn/nex/ServiceClient.h>

namespace nn {
namespace nex {

class Gathering {
  public:
    uint8_t version;
    int m_GatheringId;
    int m_OwnerPid;
    int field_C;
    uint16_t m_PlayerMin;
    uint16_t m_PlayerMax;
    int m_ParticipationPolicy;
    int m_PolicyArgument;
    int m_Flags;
    int field_20;
    nn::nex::String description;
    int vtable;
};

class MatchmakeSessionSearchCriteria {
  public:
    uint8_t m_Version;
    nn::nex::qVector<nn::nex::String> attributes;
    nn::nex::String m_GameMode;
    nn::nex::String m_MinParticipants;
    nn::nex::String m_MaxParticipants;
    nn::nex::String m_MatchmakeSystem;
    bool m_VacantOnly;
    bool m_ExcludeLocked;
    bool m_ExcludeNonHostPid;
    uint32_t m_SelectionMethod;
    uint16_t m_VacantParticipants;
    int vtable;
};

class MatchmakeSession : public nn::nex::Gathering {
  public:
    uint8_t m_Version;
    int m_GameMode;
    nn::nex::qVector<uint32_t> m_Attribs;
    bool m_OpenParticipation;
    int m_MatchmakeSystemType;
    nn::nex::qVector<uint8_t> m_ApplicationBuffer;
    int m_ParticipationCount;
    int m_ProgressScore;
    nn::nex::qVector<uint8_t> piaSignatureKey;
    int m_Option0;
};

class MatchMakingProtocolClient : public nn::nex::ClientProtocol {
  public:
};

class MatchMakingProtocolExtClient : public nn::nex::ClientProtocol {
  public:
};

class MatchMakingClient : public nn::nex::ServiceClient {
  public:
    nn::nex::MatchMakingProtocolClient m_ProtocolClient;
    nn::nex::MatchMakingProtocolExtClient m_ProtocolExtClient;
};

} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::Gathering) == 0x30, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::MatchmakeSession) == 0x7C, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::MatchMakingProtocolExtClient) == 0x48, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::MatchMakingProtocolClient) == 0x48, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::MatchMakingClient) == 0xA0, "Class doesn't match game class size");

#endif