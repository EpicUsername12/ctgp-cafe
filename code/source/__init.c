#include <cafe.h>

#include <dynamic_libs/os_functions.h>

/* libgcc memcpy */
void* memcpy(void* dest, const void* src, size_t len) {
    return OSBlockMove(dest, src, len, 0);
}

extern uint32_t MK8_OSDynLoad_Acquire;
extern uint32_t MK8_OSDynLoad_FindExport;

typedef void (*InitFunc)();
extern InitFunc MK8_MainConstructors[];

OsSpecifics osSpecifics;

// https://github.com/aboood40091/NSMBU-Haxx-Rewrite/blob/master/haxx/src/ctors.cpp#L22C1-L37C2
static inline uintptr_t AddrExtractFromInst(const u32* p_instruction)
{
    uintptr_t ret = *p_instruction & 0x03FFFFFCu;

    if (!(*p_instruction & 2))
    {
        // sign extend offset
        if (ret & 0x02000000u)
           ret |= 0xFE000000u;

        // make relative
        ret += (uintptr_t)p_instruction;
    }

    return ret;
}

void call_ctors() {

    static bool initialized = false;
    if (initialized)
        return;

    initialized = true;
    // for (int i = 0; MK8_MainConstructors[i]; i++)
    //   (*MK8_MainConstructors[i])();

    OS_SPECIFICS->addr_OSDynLoad_Acquire    = AddrExtractFromInst(&MK8_OSDynLoad_Acquire);
    OS_SPECIFICS->addr_OSDynLoad_FindExport = AddrExtractFromInst(&MK8_OSDynLoad_FindExport);

    InitOSFunctionPointers();

    LOG("Hello from CTGP-Café.\n");
}
