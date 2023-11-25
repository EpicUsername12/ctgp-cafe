#ifndef _SYS_RES_LDR_H
#define _SYS_RES_LDR_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <thread/seadCriticalSection.h>
#include <prim/seadSafeString.h>
#include <filedevice/seadFileDevice.h>
#include <filedevice/seadMainFileDevice.h>
#include <filedevice/cafe/seadCafeFSAFileDeviceCafe.h>

namespace sys {

class ResourceLoader {
  public:
    class LoadArg {
      public:
        int field_00;
        int field_04;
        int field_08;
        char field_0C;
        int field_10;
        char field_14;
    };

    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    sead::CriticalSection criticalSection;
    sead::FixedSafeString<256> fixedString;
    sead::MainFileDevice* mainFileDevice;
    sead::FileDevice* anyFileDevice;
    sead::CafeFSAFileDevice* cafeFileDevice;
    int field_17C;
    int field_180;
    int field_184;
    int field_188;

    virtual void __do_vtbl() {
    }

    uint8_t const* loadDirect(sead::SafeString const& filepath, LoadArg const& loadArgs);
};

} // namespace sys

static_assert(sizeof(sys::ResourceLoader) == 0x190, "Class doesn't match game class size");

#endif