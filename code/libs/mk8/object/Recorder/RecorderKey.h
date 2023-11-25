#ifndef RECORDER_KEY_H
#define RECORDER_KEY_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <MK8/object/Recorder/Recorder.h>

namespace object {
class RecorderKey : public Recorder {
  public:
    int field_138;
    int field_13C;
    int field_140;
    int field_144;
};
} // namespace object

static_assert(sizeof(object::RecorderKey) == 0x148, "Class doesn't match game class size");

#endif