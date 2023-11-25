#ifndef RIGID_BODY_H
#define RIGID_BODY_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace util {
class RigidBody {
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
    float x;
    float y;
    float z;
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
    float mass;
    float massRes; // == 1/mass using method util::RigidBody::setMass(float mass)
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8; // time scale?
    int field_CC;
    int field_D0;
};
} // namespace util

static_assert(sizeof(util::RigidBody) == 0xD4, "Class doesn't match game class size");

#endif