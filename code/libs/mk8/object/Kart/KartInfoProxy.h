#ifndef KART_INFO_PROXY_H
#define KART_INFO_PROXY_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/object/Driver/DriverKart.h>
#include <mk8/object/Kart/KartVehicle.h>
#include <mk8/object/Kart/KartVehicleMove.h>
#include <heap/seadDisposer.h>

namespace object {
class KartInfoProxy : public sead::IDisposer {
  public:
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    KartVehicle* vehicle;
    KartVehicleMove* vehicleMove;
    DriverKart* driver;

    void startPackun();
    bool isPackunItemActive();
    int getPlayerID();
    int getDriverID();
    int getBodyID();
};
} // namespace object

static_assert(sizeof(object::KartInfoProxy) == 0x2C, "Class doesn't match game class size");

#endif