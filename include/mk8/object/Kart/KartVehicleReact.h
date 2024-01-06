#ifndef KART_VEHICLE_REACT_H
#define KART_VEHICLE_REACT_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace object {
class KartVehicleReact {
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
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
};
} // namespace object

static_assert(sizeof(object::KartVehicleReact) == 0x64, "Class doesn't match game class size");

#endif