#ifndef _MK8_ENL_MATCHING_MGR_H
#define _MK8_ENL_MATCHING_MGR_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <prim/seadRuntimeTypeInfo.h>

#include <mk8/nn/nex/MatchmakingExtension.h>
#include <mk8/nn/nex/NgsFacade.h>

namespace enl {

class MatchingManager {

    SEAD_RTTI_BASE(MatchingManager)

  public:
    char flags;
    char field_1;
    char field_2;
    char field_3;

    virtual void initialize();
    virtual void unk0() = 0;
    virtual void unk1() = 0;
    virtual void disconnect();
    virtual void finalize();
    virtual void unk2() = 0;
    virtual void unk3() = 0;
    virtual bool getSomeFlags() const;
    virtual bool checkConnectivity() const;
    virtual void onFrameCalc();
    virtual void connectNetwork();
    virtual void unk4() = 0;
    virtual bool login() const;
    virtual void unk5() = 0;
    virtual int getUserPid() const;
};

class PiaInetMatchingManager : public enl::MatchingManager {
  public:
    class CreateArg {
      public:
        uint16_t field_0;
        uint16_t field_2;
    };

  public:
    int m_ProtoMatchSession;
    int m_IsInitialized;
    nn::nex::NgsFacade* m_NgsFacade;
    nn::nex::MatchmakeExtensionClient* m_MatchMakeExtensionClient;
    nn::nex::Credentials* m_Credentials;
    nn::nex::MatchmakeSession* m_ActiveMatchSession;
    nn::nex::qResult nexResult;
    int m_GatheringId;
    uint8_t m_Gap30[84];
    int m_HostPid;
    int m_UserPid;
    int field_8C;
    int flags2;
    enl::PiaInetMatchingManager::CreateArg createArg;
    int field_98;
    int m_PlatformImpl;
    int m_InitMatchmakeFunc; // Search criteria conditions builder
    nn::nex::qVector<uint8_t> m_SignatureKey;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
};

class NinPiaInetMatchingManager : public enl::PiaInetMatchingManager {
  public:
};

} // namespace enl

static_assert(sizeof(enl::MatchingManager) == 0x08, "Class doesn't match game class size");
static_assert(sizeof(enl::PiaInetMatchingManager::CreateArg) == 0x04, "Class doesn't match game class size");
static_assert(sizeof(enl::PiaInetMatchingManager) == 0xC8, "Class doesn't match game class size");
static_assert(sizeof(enl::NinPiaInetMatchingManager) == 0xC8, "Class doesn't match game class size");

#endif