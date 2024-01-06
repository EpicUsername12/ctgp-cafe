#ifndef _MK8_ENL_CONFIG_H
#define _MK8_ENL_CONFIG_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <prim/seadSafeString.h>
#include <mk8/enl/MatchingManager.h>
#include <mk8/enl/Manager.h>

namespace enl {

class NetworkThreadConfig {
  public:
    int m_ParentHeap;
    int m_ThreadHeap;
    int field_8;
    size_t m_ThreadHeapSize;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int vtbl;
};

class NetworkConfig {
  public:
    uint8_t m_NumMaxStations;
    uint8_t m_Default10;
    int m_Flags;
    int m_GameServerId;
    sead::BufferedSafeString m_SandboxKey;
    uint16_t m_SandboxKeyBuffer[16];
    int field_38;
    enl::NetworkThreadConfig taskThreadArgs;
    char field_68;
    char field_69;
    char field_6A;
    char field_6B;
    sead::BufferedSafeString m_MiiName;
    uint16_t m_MiiNameBuffer[16];
    char field_98;
    char someNumber;
    char field_9A;
    char field_9B;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    void* HTTPInitializationFunction;
    char field_B0;
    char field_B1;
    char field_B2;
    char field_B3;
    int vtbl;
};

class NexNetworkConfig : public enl::NetworkConfig {
  public:
    int field_B8;
    char field_BC;
    char field_BD;
    uint16_t field_BE;
    uint16_t field_C0;
    char field_C2;
    char field_C3;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
};

class PiaNetworkConfig : public enl::NexNetworkConfig {
  public:
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    uint16_t field_E8;
    uint16_t field_EA;
    int chatInitFunc;
};

class NinPiaNetworkConfig : public enl::PiaNetworkConfig {
  public:
    enl::NinPiaMemoryManager::CreateArg m_MemoryManagerCreateArg;
    enl::PiaInetMatchingManager::CreateArg m_MatchingManagerCreateArg;
    int field_178;
    int field_17C;
};

class P2PConfig {
  public:
    int m_MaxSilenceTime;
    int field_4;
    int m_KeepAliveInterval;
    uint8_t m_NumPlayers;
    int m_FirstIdNumber;
    char m_SyncClockPulseInterval;
    char field_15;
    uint16_t m_RTTMax;
    int vtable;
};
} // namespace enl

static_assert(sizeof(enl::NetworkThreadConfig) == 0x2C, "Class doesn't match game class size");
static_assert(sizeof(enl::NetworkConfig) == 0xB8, "Class doesn't match game class size");
static_assert(sizeof(enl::NexNetworkConfig) == 0xD8, "Class doesn't match game class size");
static_assert(sizeof(enl::PiaNetworkConfig) == 0xF0, "Class doesn't match game class size");
static_assert(sizeof(enl::NinPiaNetworkConfig) == 0x180, "Class doesn't match game class size");

#endif