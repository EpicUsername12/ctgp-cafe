#ifndef _ENL_STREAM_H
#define _ENL_STREAM_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <stream/seadStream.h>

namespace enl {

class RamWriteStream : public sead::RamWriteStream {};
class RamReadStream : public sead::RamReadStream {};

} // namespace enl

static_assert(sizeof(enl::RamWriteStream) == 0x20, "Class doesn't match game class size");
static_assert(sizeof(enl::RamReadStream) == 0x20, "Class doesn't match game class size");
#endif