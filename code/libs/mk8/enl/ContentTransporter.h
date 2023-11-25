#ifndef _ENL_CONTENT_TRANSPORTER_H
#define _ENL_CONTENT_TRANSPORTER_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadPtrArray.h>

#include <mk8/enl/Buffer.h>
#include <mk8/enl/Stream.h>
#include <mk8/enl/Peer.h>

namespace enl {

class IContentTransporter {

  public:
    virtual void init() = 0;
    virtual void* getSendBuffer() const = 0;
    virtual size_t getSendBufferSize() const = 0;
    virtual bool isNeedSend() = 0;
    virtual uint8_t getContentID(void) const = 0;
    virtual int getPacketNo() const = 0;
};

class ContentTransporterCommon : public IContentTransporter {

  protected:
    uint8_t contentId;
    int packetNo;
    sead::PtrArray<enl::DoubleBuffer> messageBuffers;
    bool needsUpdate;
    bool isIdleState;
    char field_1A;
    char field_1B;
    uint32_t mask;
    char field_20;
    char field_21;
    char field_22;
    char field_23;
    int flagCount;
    char* flagBuffer;

    virtual void setPacketNo(int packetNo) {
        this->packetNo = packetNo;
    }

    virtual void send(bool needsUpdate) {
        this->needsUpdate = needsUpdate;
    }

    virtual void unk1() {
    }

    virtual void endIdling() {
        this->isIdleState = false;
    }

    virtual bool isIdling() const {
        return this->isIdleState;
    }

    virtual void sendCommit() {
    }

    virtual void receiveCommit(signed char const&) = 0;
    virtual bool onCheckReceive(signed char const&, uint8_t*, size_t) const = 0;
    virtual void onReceived(signed char const&, uint8_t*, size_t) = 0;

    virtual void onDisconnect(signed char const& id1, signed char const& id2) {
    }

    virtual void onDisconnectGone(signed char const&, signed char const&) = 0;
    virtual size_t readySendStream(enl::RamWriteStream&) = 0;
    virtual size_t readyReceiveStream(enl::RamReadStream&, enl::Buffer*, size_t) = 0;

    virtual void unk2() {
    }

    virtual void unk3() {
    }

    virtual void resetReceive() = 0;
    virtual void unk4() {
    }

    virtual bool checkReceive(signed char const&) const = 0;
    virtual void unk5() {
    }

    virtual void onConnectInitialize() = 0; // stubbed ?
    virtual bool isNeedCheckTwiceReceive() const = 0;
    virtual void unk6() {
    }

    virtual void unk7(signed char const&) = 0;
    virtual void unk8() {
    }

    virtual void unk9() {
    }

    virtual void unk10() {
    }

    virtual uint8_t* unk11() const = 0;
    virtual uint8_t* getBufferDataPtrByAID(signed char const& id) const = 0;
    virtual void unk13() {
    }

    virtual uint8_t* getBufferDataPtrByUniqueID(enl::UniqueID const&) const = 0;
    virtual void clearAllReceivedData() = 0;
    virtual void unk15() {
    }

    virtual void postInit_() = 0;
    virtual void onReceivedCore_(signed char const&, void*, size_t) = 0; // ptr = custom data for transporter
    virtual bool onCheckReceiveCore_(signed char const&, void*, size_t) const = 0;
    virtual void* getSendData() const = 0;
    virtual void* getSendData2() const = 0;
};

class SystemRequest : public ContentTransporterCommon {

    static const uint8_t ContentID = 253;

    class Flags {
        int val;

        friend int operator*(const Flags& rhs) {
            return rhs.val;
        }

        inline bool isSet(uint8_t id) {
            return (this->val & (1 << id)) != 0;
        }

        Flags(int v) {
            val = v;
        }
    };

  public:
    Flags contentIDRecordBitFlag;
};

} // namespace enl

static_assert(sizeof(enl::IContentTransporter) == 0x4, "Class doesn't match game class size");
static_assert(sizeof(enl::ContentTransporterCommon) == 0x2C, "Class doesn't match game class size");
static_assert(sizeof(enl::SystemRequest) == 0x30, "Class doesn't match game class size");

#endif