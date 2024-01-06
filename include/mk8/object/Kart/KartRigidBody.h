#ifndef KART_RIGID_BODY_H
#define KART_RIGID_BODY_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/util/RigidBody.h>

namespace object {
class KartRigidBody : public util::RigidBody {
  public:
    int field_D4;
    int field_D8;
    int field_DC;
};
} // namespace object

static_assert(sizeof(object::KartRigidBody) == 0xE0, "Class doesn't match game class size");

#endif