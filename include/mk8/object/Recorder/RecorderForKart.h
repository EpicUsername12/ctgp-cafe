#ifndef RECORDER_FOR_KART_H
#define RECORDER_FOR_KART_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace object {
class RecorderForKart {
  public:
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
};
} // namespace object

static_assert(sizeof(object::RecorderForKart) == 0x14, "Class doesn't match game class size");

#endif