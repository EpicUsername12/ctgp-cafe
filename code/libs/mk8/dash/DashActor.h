#ifndef ACTOR_H
#define ACTOR_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace dash {
class Actor {
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
};
} // namespace dash

static_assert(sizeof(dash::Actor) == 0x24, "Class doesn't match game class size");

#endif