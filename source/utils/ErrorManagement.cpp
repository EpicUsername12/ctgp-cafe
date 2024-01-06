#include "ErrorManagement.h"

#include <mk8/nn/erreula/erreula_AppearArg.h>
#include <mk8/sys/SystemEngine.h>

namespace utils {
namespace error {

void __attribute__((noreturn)) Panic(const char* format, ...) {
    char buffer[0x400];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    wchar_t buffer2[0x400];
    mbtowc(buffer2, buffer, sizeof(buffer2));

    OSReport("%s", buffer);

    nn::erreula::AppearArg arg;
    arg.errorType = nn::erreula::ERROR_NO_BTN;
    arg.screenRender = nn::erreula::RENDER_TV_DRC;
    arg.titleText = L"Fatal error";
    arg.swapInterval = 1;
    arg.errorText = buffer2;

    sys::SystemEngine::getEngine()->moduleManager->launchErrorViewer(&arg);

    while (1) {
        OSSleepTicks(MICROSECS_TO_TICKS(1000));
    }
}

void __attribute__((noreturn)) PanicNoErreula(const char* file, u32 line, const char* format, ...) {
    char buffer[0x400];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

#if PLATFORM_IS_EMULATOR
    OSReport("\n");
    OSReport("\n");
    OSReport("\n");
    OSReport("=======================================\n");
    OSReport("=======================================\n");
    OSReport("\n");

    OSReport("Panic in CTGP-Café!\n");
    OSReport("File: %s | Line %d\n", file, line);
    OSReport("Message:\n\n%s\n", buffer);
    OSReport("\n");
    OSReport("=======================================\n");
    OSReport("=======================================\n");
    OSReport("\n");
    OSReport("\n");
    OSReport("\n");

    *((u32*)0xffffffff) = 0xffffffff;
#elif PLATFORM_IS_CONSOLE_CAFELOADER
    OSPanic(file, line, "%s", buffer);
#else
#error "Unsupported platform"
#endif
}

} // namespace error
} // namespace utils