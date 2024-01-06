#ifndef RECORDER_KART_VEHICLE_H
#define RECORDER_KART_VEHICLE_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <MK8/object/Recorder/Recorder.h>

namespace object {
class RecorderKartVehicle : public Recorder {
  public:
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
};
} // namespace object

static_assert(sizeof(object::RecorderKartVehicle) == 0x15C, "Class doesn't match game class size");

#endif