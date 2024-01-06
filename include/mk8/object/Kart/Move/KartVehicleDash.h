#ifndef KART_VEHICLE_DASH_H
#define KART_VEHICLE_DASH_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/object/Kart/KartVehicle.h>

namespace object {
class KartVehicleDash {
  public:
    int field_00;
    KartVehicle* vehicle;
    uint8_t dashing;
    uint8_t field_09;
    uint8_t field_0A;         // execute dash ?
    uint8_t playingDashSound; // not sure
    int dashRemainingFrames;
    float currentDashSpeed;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int dashRemainingFrames2; // same as dashRemainingFrames
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int dashLevel;
    /* -1 not dashing
        1 drift dash
        2 start mini turbo
        7 ground ramp
        8 mushroom */
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;

    /*ids:
        0x00000001 : mushroom dash
        0x00000004 : drift 1 dash
        0x00000008 : drift 2 dash
        0x00000010 : ramp dash
        0x00000020 : aspiration
        0x00000080 : stunt dash
        0x00001000 : start mini boost
        0x00002000 : ??
        0x00004000 : ??
        0x00008000 : ??
        0x00010000 : coin dash
    */
    void executeOne(unsigned int id);
};
} // namespace object

static_assert(sizeof(object::KartVehicleDash) == 0x80, "Class doesn't match game class size");

#endif