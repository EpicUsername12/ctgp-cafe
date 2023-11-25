#ifndef SEAD_TYPES_H_
#define SEAD_TYPES_H_

#ifdef cafe

#include <types.h>

typedef u32 uintptr_t;
typedef s32 intptr_t;

#undef static_assert
#ifndef static_assert

// https://stackoverflow.com/a/1597129
#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)

#ifndef __VS_CODE__
#define static_assert(condition, ...) typedef int TOKENPASTE2(static_assert_, __LINE__)[(condition) ? 1 : -1]
#else
#define static_assert(condition, ...) ;
#endif

#endif // static_assert

#else
#error "Unknown platform"
#endif // cafe

#endif // SEAD_TYPES_H_
