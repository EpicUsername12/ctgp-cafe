#ifndef _MK8_ENL_FRMWRK_H
#define _MK8_ENL_FRMWRK_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/enl/Config.h>
#include <mk8/enl/Peer.h>
#include <mk8/enl/MatchingManager.h>
#include <mk8/enl/NetworkInfo.h>
#include <mk8/enl/TransportManager.h>

#include <heap/seadDisposer.h>
#include <thread/seadCriticalSection.h>

#include <dynamic_libs/os_types.h>

namespace enl {

class IFramework {
    virtual void _do_vtbl() {
    }
};

class Framework : IFramework {
  public:
    int memoryManager;
    void* m_NgsFacade;
    enl::PiaInetMatchingManager* inetMatchingManager;
    enl::PeerManagerCommon* m_PeerManager; // PiaPeerManager
    int errorManager;
    enl::TransportManager* transportManager;
    int sendManager;
    int p2pManager;
    enl::NetworkInfoManager* networkInfoManager;
    OSTime systemTime1;
    OSTime systemTime2;
    OSTime systemTime3;
    int m_TaskThread;
    int field_44;
    char field_48;
    char field_49;
    char field_4A;
    char field_4B;
    uint32_t flags;

    static Framework* sFrameworkInstance;
};

class PiaFramework : public enl::Framework {
  public:
};

class CafePiaFramework : public enl::PiaFramework {

  public:
    sead::CriticalSection m_CriticalSection0;
    sead::CriticalSection m_CriticalSection1;
    SEAD_SINGLETON_DISPOSER(CafePiaFramework)
    enl::NinPiaNetworkConfig m_NetConfig;
    enl::P2PConfig m_P2PConfig;
    int field_274;
};

} // namespace enl

static_assert(sizeof(enl::Framework) == 0x50, "Class doesn't match game class size");
static_assert(sizeof(enl::CafePiaFramework) == 0x278, "Class doesn't match game class size");
#endif