#ifndef KART_VEHICLE_GLIDE_H
#define KART_VEHICLE_GLIDE_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <MK8/object/Kart/KartVehicle.h>
#include <MK8/object/Kart/Move/KartWingPath.h>

namespace object {
class KartVehicleGlide {
  public:
    void* vtable;
    KartVehicle* vehicle;
    KartWingPath* wingPath1;
    KartWingPath* wingPath2;
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
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
};
} // namespace object

static_assert(sizeof(object::KartVehicleGlide) == 0x8C, "Class doesn't match game class size");

#endif