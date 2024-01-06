#ifndef _UI_HEAP_COMMON_H
#define _UI_HEAP_COMMON_H

namespace ui {
typedef class Heap_Common Heap_Common;
}

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadPtrArray.h>
#include <mk8/ui/UICourse.h>
#include <mk8/ui/UIHeap.h>
#include <mk8/ui/UITexLoader.h>
#include <mk8/ui/UIEngine.h>
#include <mk8/ui/UIThread.h>

#define MK8_HEAP_COMMON_CTOR 0x0254AA1C

struct UnkStruct {
    sead::PtrArrayImpl array;
    int field_0C;
    int field_10;
};

namespace ui {
class Heap_Common : public UIHeap {
  public:
    static const int ID = 3;

    CourseData* courseData;
    UILoadThread loadThread;
    int field_120;
    UIPartsTex partsTex;
    UICharaTex charaTex;
    sead::Buffer<void*> buffer0;
    sead::Buffer<void*> buffer1;
    UICourseTex courseTex;
    UICompeTex compeTex;
    int field_25C;
    UIStampTex stampTex;
    UIMiiTex miiTex;
    int field_3DC;
    int field_3E0;
    int field_3E4;
    UnkStruct s_1;
    UnkStruct s_2;
    UnkStruct s_3;
    int field_424;
    int field_428;
    int field_42C;
    int field_430;

    Heap_Common();

    static Heap_Common* getHeap() {
        return (Heap_Common*)UIEngine::spInstance->heapManager->getHeap(ID);
    }
};

} // namespace ui

#endif