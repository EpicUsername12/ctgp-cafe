#ifndef _MAP_OBJ_PARAMETER_H
#define _MAP_OBJ_PARAMETER_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <mk8/al/Byaml.h>

#include <math/seadVector.h>
#include <container/seadPtrArray.h>
#include <prim/seadSafeString.h>

namespace object {

typedef sead::FixedSafeString<64> ByamlString;

class MapObjParameter {
  public:
    class Parameter {
      public:
        int mMapObjId;
        int mMgrId;
        int mColShape;
        sead::Vector3<float> mColSize;
        float mLod1;
        float mLod2;
        float mLod_NoDisp;
        float mOffset;
        float mColOffsetY;
        float mClipRadius;
        int mOrigin;
        int mLightSetting;
        int mPathType;
        int mModelDraw;
        int mAiReact;
        int mPylonReact;
        uint16_t mModelEffNo;
        char mNotCreate;
        char mVR;
        char field_4C;
        char mMoveBeforeSync;
        char mClip;
        char mPackunEat;
        char mDemoCameraCheck;
        ByamlString mResNameArray[10];
        ByamlString mEffectResNameArray[10];
        ByamlString mLabel;
        ByamlString mModelName;
        char mResNameCount;
        char mEffectResNameCount;
        int field_6E0;
        int field_6E4;
        int field_6E8;
        int field_6EC;
        int field_6F0;
        int field_6F4;
        int field_6F8;
        int field_6FC;

        Parameter() {
        }
        Parameter(al::ByamlIter const&);
    };

    sead::PtrArray<Parameter> mObjParams;
    int mObjCount;

    void initialize();
};

} // namespace object

static_assert(sizeof(object::MapObjParameter::Parameter) == 0x700, "Class doesn't match game class size");
static_assert(sizeof(object::MapObjParameter) == 0x10, "Class doesn't match game class size");

#endif