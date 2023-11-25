#ifndef _ENL_TRANSPORT_MGR_H
#define _ENL_TRANSPORT_MGR_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadBuffer.h>
#include <mk8/enl/ContentTransporter.h>
#include <thread/seadCriticalSection.h>

namespace enl {
class TransportManager {

    SEAD_RTTI_BASE(TransportManager)

  public:
    uint8_t array1size;
    uint8_t playerNum;
    uint8_t field_2;
    uint8_t field_3;
    int field_4;
    uint32_t incomingMask;
    sead::CriticalSection criticalSection0;
    sead::CriticalSection criticalSection1;
    int field_84;

    struct Weird_S {
        int field_88;
        int field_8C;
        OSTime time;
    };

    Weird_S s;
    sead::PtrArray<ContentTransporterCommon> encoderArray;
    void* systemTransport; // enl::SystemTransport
    enl::SystemRequest* mSystemRequestTransp;
    sead::PtrArray<enl::Buffer> recvBuffers; // 2 * this->playerNum
    void* sendBufferArray;                   //< enl::DoubledSendPacketArray
    int someBuffer;
    enl::Buffer* recvBuffer;
    enl::Buffer* recordStateBuffer;
    int field_C8;
    int field_CC;
    sead::CriticalSection criticalSection2;
    int field_10C;
    int field_110;
    int field_114;
    int encoderFD_id;
    int encoderTracker;
    char recordBuffer[1092];

  public:
    bool isRequest(uint8_t const& contentId) const;
    ContentTransporterCommon* getContentTransporter(uint8_t const&);

    virtual void init();
    virtual void calcSend();
    virtual void calcReceive();
    virtual void receive();
    virtual void receiveFromLib();
    virtual void receiveSet(signed char, uint8_t*, size_t);
    virtual void clearReceiveFlg();
    virtual void readySend();
    virtual void regist(enl::IContentTransporter* transp);
    virtual void readyTransportBuffer();
    virtual void* getSendBufferArray();
    virtual int getPlayerNum();
    virtual int getNeededBufferNum() const;
    virtual void updateSystemTransport();
    virtual int getReceivedAIDBmp() const;

    //! it keeps going on ..
};

class PiaTransportManager : public TransportManager {

    SEAD_RTTI_OVERRIDE(PiaTransportManager, TransportManager)

    int mUnreliableProtocolId;
    int mReliableProtocolId;
};

} // namespace enl

static_assert(sizeof(enl::TransportManager) == 0x568, "Class doesn't match game class size");
static_assert(sizeof(enl::PiaTransportManager) == 0x570, "Class doesn't match game class size");

#endif