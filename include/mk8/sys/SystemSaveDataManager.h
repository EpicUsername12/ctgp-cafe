#ifndef _SYS_SDATA_MGR_H
#define _SYS_SDATA_MGR_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <thread/seadThread.h>
#include <dynamic_libs/nn_act_functions.h>

namespace sys {

class SaveDataManager {

    sead::Thread mManagerThread;
    int mUnk[0x16243];

  public:
    void** getUserSaveDataPtr(SlotNo slotNo = 0xFF); // 0xff for global savedata

    inline void* getRealUserSaveDataPtr(SlotNo slotNo = 0xFF) {
        return *(void**)((uint32_t)getUserSaveDataPtr(slotNo) + 0x158);
    }

    static inline uint8_t* calculateFlagPtrFromOffset(void* pSaveData, size_t offset) {
        return (uint8_t*)((uint32_t)pSaveData + offset);
    }
};

} // namespace sys

static_assert(sizeof(sys::SaveDataManager) == 0x589A4, "Class doesn't match game class size");

#endif