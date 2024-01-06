#pragma once

#include <heap/seadHeapMgr.h>
#include <heap/seadExpHeap.h>

namespace utils {

class ScopedHeapUsage {

  public:
    ScopedHeapUsage(sead::Heap* heap) {
        m_backupHeap = sead::HeapMgr::instance()->getCurrentHeap();
        sead::HeapMgr::instance()->setCurrentHeap_(heap);
    }

    ~ScopedHeapUsage() {
        sead::HeapMgr::instance()->setCurrentHeap_(m_backupHeap);
    }

  private:
    sead::Heap* m_backupHeap;
};

} // namespace utils