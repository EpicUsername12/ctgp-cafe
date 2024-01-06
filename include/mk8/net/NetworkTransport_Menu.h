#ifndef _NET_NET_TRANSPORT_MENU_H
#define _NET_NET_TRANSPORT_MENU_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/enl/Framework.h>

namespace net {

class NetworkData_MenuPlayer {
  public:
    enl::UniqueID m_UniqueID;
    uint8_t m_CourseId; // (courseId << 1) | (*(uint32_t*)(&this->m_CourseId) & 0x01000000 != 0)
};

class NetworkData_Menu {
  public:
    NetworkData_MenuPlayer m_Players[12];
    NetworkData_MenuPlayer m_CourseChoice; // It's a copy of one of the above, but it's the one that
                                           // the random track selection choose
};

class NetworkTransporter_Menu : public enl::ContentTransporterCommon {

    struct LobbyPlayer {
        int field_0;
        enl::UniqueID playerId;
        int field_C;
        int field_10;
        char field_14;
        char field_15;
        char field_16;
        char field_17;
        char field_18;
    };

    NetworkData_Menu staticData;
    char field_C8;
    char field_C9;
    char field_CA;
    char field_CB;
    int field_CC;
    int bufferPlayerIDTable;
    int field_D4;
    LobbyPlayer players[12];
    int field_228;
    char field_22C[148];
    int field_2C0;
    int field_2C4;
    enl::PeerInfo playerIds[28];
    char field_3A8[40];
    char field_3D0;
    char field_3D1;
    char field_3D2;
    char field_3D3;
    int field_3D4;
    int field_3D8;
    int field_3DC;
    int field_3E0;
    int field_3E4;
    int field_3E8;
    int field_3EC;
    int field_3F0;
    int field_3F4;
    int field_3F8;
    int field_3FC;
    int field_400;
    int field_404;
    int field_408;
    int field_40C;
    int field_410;
    int field_414;
    int field_418;
    int field_41C;
    int field_420;
    int field_424;
    int field_428;
    int field_42C;
    int field_430;
    int field_434;
    int field_438;
    int field_43C;
    int field_440;
    int field_444;
    int field_448;
    int field_44C;
    int field_450;
    int field_454;
    int field_458;
    int field_45C;
    int field_460;
    int field_464;
    int field_468;
    int field_46C;
    int field_470;
    int field_474;
    int field_478;
    int field_47C;
    int field_480;
    int field_484;
    int field_488;
    int field_48C;
    int field_490;
    int field_494;
    int field_498;
    int field_49C;
    int field_4A0;
    int field_4A4;
    int field_4A8;
    int field_4AC;
    int field_4B0;
    int field_4B4;
    int field_4B8;
    int field_4BC;
    int field_4C0;
    int field_4C4;
    int field_4C8;
    int field_4CC;
    int field_4D0;
    int field_4D4;
    int field_4D8;
    int field_4DC;
    char field_4E0;
    char field_4E1;
    char field_4E2;
    char field_4E3;
    int field_4E4;
    int field_4E8;
    int field_4EC;

  public:
    int getVoteResultIndex() const;
    virtual void* getSendData2() const;

    inline NetworkData_Menu* getMenuData() {
        return (NetworkData_Menu*)this->getSendData2();
    }

    static NetworkTransporter_Menu* getTransporter() {
        return (NetworkTransporter_Menu*)enl::Framework::sFrameworkInstance->transportManager->getContentTransporter(0);
    }
};

} // namespace net

static_assert(sizeof(net::NetworkData_MenuPlayer) == 0x0C, "Class doesn't match game class size");
static_assert(sizeof(net::NetworkData_Menu) == 0x9C, "Class doesn't match game class size");
static_assert(sizeof(net::NetworkTransporter_Menu) == 0x4F0, "Class doesn't match game class size");

#endif