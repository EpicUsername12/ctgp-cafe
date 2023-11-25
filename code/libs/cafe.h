#pragma once

#include <stdint.h>

#if PLATFORM_IS_EMULATOR
#include "dynamic_libs/os_functions.h"
#define LOG(FMT, ARGS...) OSReport(FMT, ##ARGS);
#elif PLATFORM_IS_CONSOLE_CAFELOADER
#define LOG(FMT, ARGS...) ((void (*)(const char* format, ...))(*(unsigned int*)(DATA_ADDR - 4)))(FMT, ##ARGS);
#else
#error "Unsupported platform"
#endif

#if PLATFORM_IS_EMULATOR || PLATFORM_IS_CONSOLE_CAFELOADER
#include "dynamic_libs/os_functions.h"
#define PANIC(FMT, ARGS...) OSPanic(__FILE__, __LINE__, FMT, ##ARGS);
#else
#error "Unsupported platform"
#endif

#define PANIC_UNIMPLEMENTED() PANIC("Unimplemented function %s", __PRETTY_FUNCTION__);
