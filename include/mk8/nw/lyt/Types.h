#pragma once

#include <stdint.h>
#include <basis/seadTypes.h>

namespace nw {
namespace lyt {

class Vector2f {
  public:
    float x;
    float y;
};

class Vector3f {
  public:
    float x;
    float y;
    float z;
};

static_assert(sizeof(Vector2f) == 0x8, "Class doesn't match game class size");
static_assert(sizeof(Vector3f) == 0xC, "Class doesn't match game class size");

} // namespace lyt
} // namespace nw