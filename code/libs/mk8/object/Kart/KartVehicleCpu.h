#ifndef KART_VEHICLE_CPU_H
#define KART_VEHICLE_CPU_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <MK8/object/Kart/KartVehicleControl.h>

namespace object {
class KartVehicleCpu : public KartVehicleControl {
  public:
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
};
} // namespace object

static_assert(sizeof(object::KartVehicleCpu) == 0x70, "Class doesn't match game class size");

#endif