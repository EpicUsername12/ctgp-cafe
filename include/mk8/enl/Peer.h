#ifndef _MK8_ENL_PEER_H
#define _MK8_ENL_PEER_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <prim/seadBitFlag.h>
#include <thread/seadCriticalSection.h>
#include <container/seadObjArray.h>
#include <prim/seadRuntimeTypeInfo.h>

namespace enl {

class UniqueID {
  public:
    int stationId;
    uint8_t playerId;
    uint8_t unk1;

  public:
    inline bool isStationValid() {
        return this->stationId != 253;
    }

    inline bool isFullyEqual(const UniqueID& rhs) const {
        return (this->stationId == rhs.stationId) && (this->playerId == rhs.playerId) && (this->unk1 == rhs.unk1);
    }

    friend bool operator==(const UniqueID& lhs, const UniqueID& rhs) {
        return (lhs.stationId == rhs.stationId) && (lhs.playerId == rhs.playerId);
    }

    UniqueID() {
        stationId = 253;
        playerId = 0;
        unk1 = 0;
    }
};

class SimpleIDInfo {
  public:
    UniqueID mUniqueId;
    char field_8;
    char field_9;
};

class PeerInfo : public UniqueID {

    friend bool operator==(const PeerInfo& lhs, const PeerInfo& rhs) {
        return (lhs.stationId == rhs.stationId) && (lhs.playerId == rhs.playerId);
    }

    PeerInfo() {
        stationId = 253;
        playerId = 0;
    }
};

/* Here temporarily */
struct SessionEventList {
    sead::ListImpl m_List;
    int field_C;
    int field_10;
    int field_14;
};

/* Here temporarily */
struct StationController_s2 {
    enl::UniqueID playerId;
    int field_8;
    int field_C;
    char field_10;
    char field_11;
    char field_12;
    char field_13;
    int vtable;
};

class PeerManager {

    SEAD_RTTI_BASE(PeerManager)

  public:
    uint8_t m_NumStationLimit;
    enl::UniqueID m_SelfPeer;
    char field_C;
    char field_D;
    char field_E;
    char field_F;
    enl::UniqueID m_HostPeer;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;
    int field_1C;
    sead::CriticalSection critSec;
    int field_5C;
    char field_60;
    bool isConnectingState;
    char field_62;
    char field_63;

    virtual void unk00() = 0;
    virtual void calc() = 0;
    virtual void init();
    virtual uint32_t getConnectedAIDBmp() const = 0;
    virtual uint32_t getDisconnectedAIDBmp() const = 0;
    virtual uint32_t getConnectedPlayerBmp() const = 0;
    virtual uint32_t getDisconnectedPlayerBmp() const = 0;
    virtual int getConnectedNum() const;
    virtual void unk06() = 0;
    virtual int getConnectedPlayerNum() const;
    virtual int getDisconnectedPlayerNum() const;
    virtual void unk07() = 0;
    virtual signed char getOldAID() const;
    virtual void unk09() = 0;
    virtual bool isDisconnected(signed char const&) const = 0;
    virtual bool isDisconnectedPlayer(enl::UniqueID const&) const = 0;
    virtual bool isConnected() const = 0;

    virtual bool isSessionMaster() {
        bool ret = false;
        if (this->m_SelfPeer.isStationValid() && this->m_SelfPeer.isFullyEqual(this->m_HostPeer)) {
            ret = true;
        }
        return ret;
    }

    virtual void unk_xd() = 0;
    virtual void updatePlayerIDTable(sead::Buffer<signed char> const&, int) = 0;
    virtual void clearPlayerIDTable() = 0;
    virtual bool isPlayerIDSync() const = 0;
    virtual bool isAlreadyPlayerIDSync() const = 0;
    virtual sead::PtrArray<SimpleIDInfo>* getStationGroupArrayByUniqueID(enl::UniqueID const&) = 0;
    virtual sead::PtrArray<SimpleIDInfo>* getMyStationGroupArray() = 0;
    virtual bool isAIDValid(signed char const&) const = 0;
    virtual bool isBufferIDValid(signed char const&) const = 0;
    virtual bool isUniqueIDValid(enl::UniqueID const&) const = 0;
    virtual signed char getAIDByUniqueID(enl::UniqueID const&) const = 0;
    virtual signed char getAIDByPlayerID(signed char const&) const = 0;
    virtual signed char getAIDByBufferID(signed char const&) const = 0;
    virtual signed char getPlayerIDByAID(signed char const&) const = 0;
    virtual signed char getPlayerIDByUniqueID(enl::UniqueID const&) const = 0;
    virtual enl::UniqueID getUniqueIDByAID(signed char const&) const = 0;
    virtual enl::UniqueID getUniqueIDByBufferID(signed char const&) const = 0;
    virtual enl::UniqueID getUniqueIDByPlayerID(signed char const&) = 0;
    virtual enl::UniqueID getUniqueIDByPrincipalID(unsigned int const&) const = 0;
    virtual uint32_t getPrincipalIDByUniqueID(enl::UniqueID const&) const = 0;
    virtual signed char getBufferIDByAID(signed char const&) const = 0;
    virtual signed char getBufferIDByUniqueID(enl::UniqueID const&) const = 0;
    virtual signed char getBufferIDByPlayerID(signed char const&) const = 0;
    virtual void unk35() = 0;
    virtual void unk34() = 0;
    virtual enl::UniqueID getTransportIDByAID(signed char const&) const = 0;
    virtual int getHideTransportID() const = 0;
    virtual signed char getHideAID() const = 0;
    virtual signed char getHideBufferID() const = 0;
    virtual void unk31() = 0;
    virtual void procOnConnected();
    virtual signed char getNextAID(signed char const&, bool) const = 0;
    virtual void getUniqueIDInfo(enl::UniqueID*, unsigned char) const = 0;
    virtual void report(bool) = 0;
    virtual void getPlayerIDConvertTable() = 0;
    virtual int getRegistTaskNum(void) const = 0;
    virtual void clearRegistTask(enl::UniqueID const&) = 0;
    virtual void registPeerInfoAsConnectedForce(enl::UniqueID const&) = 0;
    virtual void changePeerInfoAsDisconnected(signed char const&) = 0;
    virtual void setRequestDecidePlayer() = 0;
    virtual bool isHideClient() const = 0;
    virtual bool isHideClientByAID(signed char const&) const = 0;
    virtual bool isHideClientByUniqueID(enl::UniqueID const&) const = 0;
    virtual void setHideRealStationID(unsigned long const&) = 0;
    virtual unsigned long getHideRealStationID() const = 0;
    virtual bool checkIsNeedSendAID(signed char const&) = 0;
    virtual bool isIDTableSync(void) const = 0;
    virtual void unk52() = 0;
    virtual bool isOnConnectingState() const {
        return this->isConnectingState;
    }
    virtual bool isLocalConnected_() const = 0;
    virtual int getPlayerNum() const = 0;
    virtual void onConnect() = 0;
    virtual void initPeerConnect_(enl::PeerInfo*) = 0;
    virtual void procPeerConnect_(enl::PeerInfo*);
    virtual void initPeerDisconnect_(enl::PeerInfo*) = 0;
    virtual bool procPeerDisconnect_(enl::PeerInfo*) = 0;
    virtual void initPeerForceDisconnect_(enl::PeerInfo*) = 0;
};

class IDInfoBase {
  public:
    int field_0;
    enl::UniqueID m_Player;
    char field_C;
    char field_D;
    char field_E;
    char field_F;
    uint64_t m_UpdateTime;
    char field_18;
    char field_19;
    char field_1A;
    char field_1B;

    void toSimpleIDInfo(enl::SimpleIDInfo*);

    virtual void init();
    virtual bool isValid() const;
};

class EStationState {
    int val;

    int operator*(const EStationState& lhs) {
        return val;
    }

    EStationState(int v) {
        val = v;
    }
};

class IDManager {
  public:
    sead::PtrArray<enl::IDInfoBase> m_PlayersAll;
    int playerInfoBufPtr;
    int playerInfoBufBase;
    sead::PtrArray<enl::IDInfoBase> activePlayers;
    sead::PtrArray<void*> array3;
    sead::PtrArray<void*> array4;
    sead::PtrArray<void*> array5;
    sead::PtrArray<void*> array6;
    enl::IDInfoBase hostInfo;
    int field_70;
    int field_74;
    sead::PtrArray<void*> array7;
    int field_84;
    int field_88;
    int field_8C;
    sead::PtrArray<void*> array8;
    sead::PtrArray<void*> playerArray;
    sead::PtrArray<void*> array10;
    sead::Buffer<uint32_t> playerFlags1;
    sead::Buffer<uint32_t> playerFlags2;
    int connectedAIDBmp;
    int disconnectedAIDBmp;
    int connectedPlayerBmp;
    int disconnectedPlayerBmp;
    int field_D4;
    int field_D8;
    int stationLimit;
    char field_E0;
    char field_E1;
    char field_E2;
    char field_E3;
    int someIndex;
    int someBuffer;
    char field_EC;
    char field_ED;
    char field_EE;
    char field_EF;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int vtable;
    int field_104;
};

class PeerManagerCommon : public enl::PeerManager {
    enl::IDManager* m_IDManager;
    SessionEventList m_EventList0;
    SessionEventList m_EventList1;
    SessionEventList m_EventList2;
    StationController_s2 s2;
    uint8_t gapCC[60];
    int field_108;
    char field_10C;
    char field_10D;
    char field_10E;
    char field_10F;
    uint64_t time;
    int registTaskNum;
    char field_11C;
    char field_11D;
    char field_11E;
    char field_11F;

  public:
    virtual void calc();
    virtual void init();
    virtual uint32_t getConnectedAIDBmp() const;
    virtual uint32_t getDisconnectedAIDBmp() const;
    virtual uint32_t getConnectedPlayerBmp() const;
    virtual uint32_t getDisconnectedPlayerBmp() const;
    virtual int getConnectedNum() const;

    virtual int getConnectedPlayerNum() const;
    virtual int getDisconnectedPlayerNum() const;

    virtual signed char getOldAID() const;

    virtual bool isDisconnected(signed char const&) const;
    virtual bool isDisconnectedPlayer(enl::UniqueID const&) const;
    virtual bool isConnected() const;
    // isSessionMaster() and unk_xd()
    virtual void updatePlayerIDTable(sead::Buffer<signed char> const&, int);
    virtual void clearPlayerIDTable();
    virtual bool isPlayerIDSync() const;
    virtual bool isAlreadyPlayerIDSync() const;
    virtual sead::PtrArray<SimpleIDInfo>* getStationGroupArrayByUniqueID(enl::UniqueID const&);
    virtual sead::PtrArray<SimpleIDInfo>* getMyStationGroupArray();
    virtual bool isAIDValid(signed char const&) const;
    virtual bool isBufferIDValid(signed char const&) const;
    virtual bool isUniqueIDValid(enl::UniqueID const&) const;
    virtual signed char getAIDByUniqueID(enl::UniqueID const&) const;
    virtual signed char getAIDByPlayerID(signed char const&) const;
    virtual signed char getAIDByBufferID(signed char const&) const;
    virtual signed char getPlayerIDByAID(signed char const&) const;
    virtual signed char getPlayerIDByUniqueID(enl::UniqueID const&) const;
    virtual enl::UniqueID getUniqueIDByAID(signed char const&) const;
    virtual enl::UniqueID getUniqueIDByBufferID(signed char const&) const;
    virtual enl::UniqueID getUniqueIDByPlayerID(signed char const&);
    virtual enl::UniqueID getUniqueIDByPrincipalID(unsigned int const&) const;
    virtual uint32_t getPrincipalIDByUniqueID(enl::UniqueID const&) const;
    virtual signed char getBufferIDByAID(signed char const&) const;
    virtual signed char getBufferIDByUniqueID(enl::UniqueID const&) const;
    virtual signed char getBufferIDByPlayerID(signed char const&) const;

    virtual signed char getHideAID() const;
    virtual signed char getHideBufferID() const;

    virtual void procOnConnected();
    virtual signed char getNextAID(signed char const&, bool) const;
    virtual void getUniqueIDInfo(enl::UniqueID*, unsigned char) const;
    virtual void report(bool);
    virtual void getPlayerIDConvertTable();
    virtual int getRegistTaskNum(void) const;
    virtual void clearRegistTask(enl::UniqueID const&);
    virtual void registPeerInfoAsConnectedForce(enl::UniqueID const&);
    virtual void changePeerInfoAsDisconnected(signed char const&);
    virtual void setRequestDecidePlayer();
    virtual bool isHideClient() const;
    virtual bool isHideClientByAID(signed char const&) const;
    virtual bool isHideClientByUniqueID(enl::UniqueID const&) const;
    virtual void setHideRealStationID(unsigned long const&);
    virtual unsigned long getHideRealStationID() const;
    virtual bool checkIsNeedSendAID(signed char const&);
    virtual bool isIDTableSync(void) const;

    virtual bool isOnConnectingState() const {
        return this->isConnectingState;
    }
    virtual bool isLocalConnected_() const;
    virtual int getPlayerNum() const;
    virtual void onConnect();
    virtual void initPeerConnect_(enl::PeerInfo*);
    virtual void procPeerConnect_(enl::PeerInfo*);
    virtual void initPeerDisconnect_(enl::PeerInfo*);
    virtual bool procPeerDisconnect_(enl::PeerInfo*);
    virtual void initPeerForceDisconnect_(enl::PeerInfo*);
    virtual bool procPeerLocalSync_(enl::PeerInfo*);
    virtual void initPeerLocalSync_(enl::PeerInfo*);
    virtual void initPeerForceConnect_(enl::PeerInfo*);
    virtual void registPeerInfoAsLocal(enl::UniqueID const&, int);
    virtual void registPeerInfoAsDisconnect(enl::UniqueID const&, int);
    virtual void registPeerInfoAsDisconnectSP(enl::UniqueID const&, int);
    virtual void unk80();
    virtual void unk81();
    virtual void unk82();
};

class PiaPeerManager : public enl::PeerManagerCommon {
  public:
    int field_120;
    int field_124;
};

} // namespace enl

static_assert(sizeof(enl::UniqueID) == 0x8, "Class doesn't match game class size");
static_assert(sizeof(enl::IDManager) == 0x108, "Class doesn't match game class size");
static_assert(sizeof(enl::IDInfoBase) == 0x20, "Class doesn't match game class size");
static_assert(sizeof(enl::PeerManager) == 0x68, "Class doesn't match game class size");
static_assert(sizeof(enl::PeerManagerCommon) == 0x120, "Class doesn't match game class size");
static_assert(sizeof(enl::PiaPeerManager) == 0x128, "Class doesn't match game class size");

#endif