#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <wchar.h>

namespace utils {
namespace error {

void __attribute__((noreturn)) Panic(const char* format, ...);
void __attribute__((noreturn)) PanicNoErreula(const char* file, uint32_t line, const char* format, ...);

} // namespace error
} // namespace utils
