#pragma once

#include <stdint.h>
#include "dynamic_libs/os_functions.h"
#include "dynamic_libs/fs_defs.h"

#include "utils/ErrorManagement.h"

#if PLATFORM_IS_EMULATOR
#define LOG(FMT, ARGS...) OSReport(FMT, ##ARGS);
#elif PLATFORM_IS_CONSOLE_CAFELOADER
#define LOG(FMT, ARGS...) ((void (*)(const char* format, ...))(*(unsigned int*)(DATA_ADDR - 4)))(FMT, ##ARGS);
#else
#error "Unsupported platform"
#endif

#define PANIC_UNIMPLEMENTED() \
    utils::error::PanicNoErreula(__FILE__, __LINE__, "Unimplemented function %s", __FUNCTION__);

#define PANIC(FMT, ARGS...) utils::error::PanicNoErreula(__FILE__, __LINE__, FMT, ##ARGS);
