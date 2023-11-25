#ifndef _NW_LYT_ANIMATION_H
#define _NW_LYT_ANIMATION_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/nw/lyt/Texture.h>

namespace nw {
namespace lyt {

class AnimTransform {
  public:
    int field_00;
    int field_04;
    int field_08;
    float frameValue;
    char field_10;
    int vtable;
};

class AnimTransformBasic : public AnimTransform {
  public:
    nw::lyt::TextureInfo** textureArray;
    int field_1C;
    uint16_t field_20;
    uint16_t field_22;
};

class Animator : public AnimTransformBasic {
  public:
    float field_24;
    int field_28;
    int field_2C;
};

class GroupAnimator : public Animator {
  public:
    int field_30;
};

} // namespace lyt
} // namespace nw

static_assert(sizeof(nw::lyt::GroupAnimator) == 0x34, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::Animator) == 0x30, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::AnimTransformBasic) == 0x24, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::AnimTransform) == 0x18, "Class doesn't match game class size");

#endif