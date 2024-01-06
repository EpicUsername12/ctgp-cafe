#ifndef _UI_HEAP_BOOT_H
#define _UI_HEAP_BOOT_H

namespace ui {
typedef class Heap_Boot Heap_Boot;
}

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadPtrArray.h>
#include <mk8/ui/UICourse.h>
#include <mk8/ui/UIHeap.h>
#include <mk8/ui/UITexLoader.h>
#include <mk8/ui/UIEngine.h>
#include <mk8/ui/UIThread.h>

namespace ui {
class Heap_Boot : public UIHeap {
  public:
    static const int ID = 2;

    static Heap_Boot* getHeap() {
        return (Heap_Boot*)UIEngine::spInstance->heapManager->getHeap(ID);
    }
};

} // namespace ui

#endif