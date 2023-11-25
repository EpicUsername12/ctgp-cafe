// clang-format off

#pragma once

#include <basis/seadTypes.h>
#include <prim/seadSafeString.h>

namespace sead
{
class HashCRC32
{
public:

    static u32 calcHash(const void* ptr, u32 size);
    static u32 calcStringHash(const char* str);
    static u32 calcStringHash(const SafeString& str) { return calcStringHash(str.cstr()); }

    static void initialize();
};
}  // namespace sead