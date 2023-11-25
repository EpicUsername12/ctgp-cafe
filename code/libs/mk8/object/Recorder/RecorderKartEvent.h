#ifndef RECORDER_KART_EVENT_H
#define RECORDER_KART_EVENT_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <MK8/object/Recorder/RecorderKey.h>

namespace object {
class RecorderKartEvent : public RecorderKey {
  public:
    int field_148;
    int field_14C;
};
} // namespace object

static_assert(sizeof(object::RecorderKartEvent) == 0x150, "Class doesn't match game class size");

#endif