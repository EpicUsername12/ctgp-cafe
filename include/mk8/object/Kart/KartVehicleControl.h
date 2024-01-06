#ifndef KART_VEHICLE_CONTROL_H
#define KART_VEHICLE_CONTROL_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace object {
class KartVehicleControl {
  public:
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
};
} // namespace object

static_assert(sizeof(object::KartVehicleControl) == 0x48, "Class doesn't match game class size");

#endif