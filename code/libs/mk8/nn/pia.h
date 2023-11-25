#ifndef _NN_PIA_H
#define _NN_PIA_H

/* All in one file */

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/enl/Peer.h>

namespace nn {
namespace pia {
namespace common {

struct Time {
    OSTime time;
};

struct ListNode {
    int field_0;
    int field_4;
};

class ListBase {
  public:
    int field_0;
    nn::pia::common::ListNode node;
    int count;
};

class List : public ListBase {
  public:
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
};

class InetAddress {
  public:
    uint32_t host;
    uint16_t port;
};

class StationAddress {
  public:
    int field_00;
    InetAddress inetAddress;
    uint16_t field_0C;
    uint16_t field_0E;
    int vtable;
};
} // namespace common

namespace inet {

class Socket {
  public:
    int fd;
    int field_4;
    nn::pia::common::InetAddress inetAddress;
};

class SocketStreamBase {
  public:
    uint8_t* buffer;
    char field_4;
    char field_5;
    char field_6;
    char field_7;
    Socket* socket;
    int vtable;
};

class OutputStream {
  public:
    int thunktbl;
    char field_14[512];
};

class InputStream {
  public:
    int field_10;
};

class SocketOutputStream : public SocketStreamBase, public OutputStream {
  public:
};

class SocketInputStream : public SocketStreamBase, public InputStream {
  public:
};
} // namespace inet

namespace transport {
class ThreadStreamManager {
  public:
    nn::pia::inet::InputStream* inputStream;
    nn::pia::inet::OutputStream* outputStream;
    int receiveThreadStream;
    int sendThreadStream;
    int vtable;

    static ThreadStreamManager* s_pInstance;

    nn::pia::inet::SocketInputStream* getInputStream() {
        return (nn::pia::inet::SocketInputStream*)((uint32_t)this->inputStream - 16);
    }

    nn::pia::inet::SocketOutputStream* getOutputStream() {
        return (nn::pia::inet::SocketOutputStream*)((uint32_t)this->outputStream - 16);
    }
};

class StationContainer {
  public:
    int count;
    int pointers[32];
    int vtable;
};

class SequenceIdController {
  public:
    uint16_t field_0;
    uint16_t field_2;
    uint16_t field_4;
    uint16_t field_6;
    uint16_t field_8;
    char field_A;
    char field_B;
    int field_C;
    int field_10;
    int vtable;
};

class ReceivedMessageAccessor {
  public:
    uint8_t* data;
    size_t size;
    int sourceStationIdx;
    nn::pia::common::StationAddress stationAddress;
};

class Protocol {
  public:
    int field_0;
    int field_4;
    int field_8;
    int typeAndPort;
    int packetHandler;
    int vtable;
};

class StationLocation {
  public:
    int field_0;
    nn::pia::common::StationAddress stationAddress;
    int principalId;
    int connectionId;
    int rvConnectionId;
    char urlType;
    char streamId;
    char streamType;
    char natMapping;
    char natFiltering;
    char type;
    char probeRequestInitiation;
    char field_2B;
    int vtable;
};

class StationConnectionInfo {
  public:
    int field_0;
    StationLocation publicStationLoc;
    StationLocation localStationLoc;

    virtual ~StationConnectionInfo();
    virtual size_t GetSerializedSize() const;
    virtual int Serialize(uint8_t*, uint32_t*, uint32_t) const;
    virtual int Deserialize(uint8_t const*);
};

class StationConnectionInfoTable {
  public:
    int field_0;
    StationConnectionInfo localConnInfo;
    StationConnectionInfo otherConnInfo;
    nn::pia::common::StationAddress stationAddr;
    int buffer;
    int pointers[32];
    int maxCount;
    char gap170[44];
    int vtable;

    static StationConnectionInfoTable* s_pInstance;
};

class StationProtocol : public Protocol {
    int timeout;

  public:
    size_t GetConnectionRequestDataSize() const;
    int ParseConnectionRequestCommon(ReceivedMessageAccessor const&, bool isRelay);
    int SendDenyingConnectionResponse(nn::pia::common::StationAddress const&, unsigned char);
    int MakeConnectionRequestData(uint8_t* outputData, uint8_t sendingConnId, bool isRelay, bool isInverse) const;
};

class Station {
  public:
    int field_0;
    nn::pia::common::StationAddress stationAddr;
    int stationIndex;
    int stationState;
    int reliableSlidingWindow;
    StationProtocol* stationProtocol;
    int connectStationJob;
    int disconnectStationJob;
    int processConnReqJob;
    nn::pia::transport::SequenceIdController sequenceIdController;
    char sendingConnectionId;
    char field_4D;
    char field_4E;
    char field_4F;
    nn::pia::common::Time time1;
    nn::pia::common::Time lastPacketIn;
    int vtable;
    int field_64;
};

class StationManager {
  public:
    Station* field_0;
    nn::pia::common::List list;
    int field_30;
    StationContainer stationContainer1;
    StationContainer stationContainer2;
    Station* localStation;
    int stationIndex;
    int vtable;

    static StationManager* s_pInstance;

    int GetStationAddress(nn::pia::common::StationAddress* outAddr, int stationId);
};

} // namespace transport
} // namespace pia
} // namespace nn

#endif