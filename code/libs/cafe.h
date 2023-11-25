#pragma once

#include <stdint.h>

#if PLATFORM_IS_EMULATOR
    #include "dynamic_libs/os_functions.h"
    #define LOG(FMT, ARGS...) OSReport(FMT, ## ARGS);
#elif PLATFORM_IS_CONSOLE_CAFELOADER
    #define LOG(FMT, ARGS...)  ((void (*)(const char *format, ...))(*(unsigned int *)(DATA_ADDR - 4)))(FMT, ## ARGS);
#else
    #error "Unsupported platform"
#endif
