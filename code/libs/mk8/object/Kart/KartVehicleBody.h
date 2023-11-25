#ifndef KART_VEHICLE_BODY_H
#define KART_VEHICLE_BODY_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <MK8/object/Kart/KartRigidBody.h>

namespace object {
class KartVehicleBody : public KartRigidBody {
  public:
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
};
} // namespace object

static_assert(sizeof(object::KartVehicleBody) == 0x154, "Class doesn't match game class size");

#endif