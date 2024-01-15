#ifndef _NW_LYT_ANIMATION_H
#define _NW_LYT_ANIMATION_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/nw/lyt/Pane.h>
#include <mk8/nw/lyt/Texture.h>
#include <mk8/nw/lyt/Resource.h>

namespace nw {
namespace lyt {

namespace res {
typedef class AnimationBlock AnimationBlock;
typedef class AnimationContent AnimationContent;
} // namespace res

typedef class Group Group;

class AnimTransform {
  public:
    AnimTransform* next;
    AnimTransform* prev;
    void* pointerToAnim;
    float frameValue;
    bool isEnabled;

    virtual void unk0();
    virtual ~AnimTransform();

    virtual void UpdateFrame(float frame);
    virtual void SetEnable(bool enabled);
    virtual void Animate();

    virtual void unk1(); // Never called / deleted
    virtual void unk2(); // Never called / deleted

    virtual void SetResource(res::AnimationBlock const* res, ResourceAccessor* pResAccessor);
    virtual void SetResource(res::AnimationBlock const* res, ResourceAccessor* pResAccessor, uint16_t num);

    virtual void unk3(); // Never called / deleted

    virtual void BindGroup(Group* group);

    virtual void unk4(); // Never called / deleted
    virtual void unk5(); // Never called / deleted
    virtual void unk6(); // Never called / deleted
    virtual void unk7(); // Never called / deleted
    virtual void unk8(); // Never called / deleted
    virtual void unk9(); // Never called / deleted
};

class AnimTransformBasic : public AnimTransform {
  public:
    nw::lyt::TextureInfo** textureArray;
    int field_1C;
    uint16_t field_20;
    uint16_t field_22;

    virtual ~AnimTransformBasic();
    virtual void AnimatePaneImpl(Pane* pane, res::AnimationContent const* pRes);
    virtual void AnimateMaterialImpl(Material* material, res::AnimationContent const* pRes);
};

class Animator : public AnimTransformBasic {
  public:
    enum PlayType {
        PLAY_ONCE,
    };

    float speed;
    PlayType playType;
    int field_2C;

    virtual ~Animator();
    virtual void Play(PlayType playType, float speed);
    virtual void PlayAuto(float speed);
    virtual void PlayFromCurrent(PlayType playType, float speed);
    virtual void Stop(float frame);
    virtual void StopCurrent();

    virtual void unk10(); // Never called / deleted
    virtual void unk11(); // Never called / deleted
    virtual void unk12(); // Never called / deleted
};

class GroupAnimator : public Animator {
  public:
    Pane* pane;

    virtual ~GroupAnimator();
};

} // namespace lyt
} // namespace nw

static_assert(sizeof(nw::lyt::GroupAnimator) == 0x34, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::Animator) == 0x30, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::AnimTransformBasic) == 0x24, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::AnimTransform) == 0x18, "Class doesn't match game class size");

#endif