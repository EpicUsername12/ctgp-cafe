#pragma once

#include "basis/seadTypes.h"
#include "prim/seadEndian.h"
#include "prim/seadSafeString.h"

namespace sead {

class StreamSrc {
  public:
    virtual u32 read(void* data, u32 size) {
        return 0;
    }
    virtual u32 write(const void* data, u32 size) {
        return 0;
    }
    virtual u32 skip(s32 offset) {
        return 0;
    }
    virtual void rewind() {
    }
    virtual bool isEOF() {
        return true;
    }
    virtual bool flush() {
        return true;
    }
    virtual ~StreamSrc();
};

class RamStreamSrc : public StreamSrc {

    void* mPtr;
    size_t mSize;
    size_t unk;

  public:
    RamStreamSrc() {
    }
    RamStreamSrc(void* ptr, size_t size);

    virtual ~RamStreamSrc();
    virtual u32 read(void* data, u32 size);
    virtual u32 write(const void* data, u32 size);
    virtual u32 skip(s32 offset);
    virtual void rewind();
    virtual bool isEOF();
    virtual bool flush() {
        return true;
    }
};

class Stream {

    /* StreamFormat* */ void* mFormat;
    RamStreamSrc* mSrc;
    Endian::Types mEndian;

  public:
    Stream();

    virtual void unk0() {
    }
    virtual void unk1() {
    }
    virtual ~Stream();
    virtual void unk2() {
    }

    void setUserFormat(/* StreamFormat* */ void* format);
    void setMode(int mode);
    void skip(u32);
    void rewind();
};

class WriteStream : public Stream {
    sead::RamStreamSrc mWriteSrc;

  public:
    size_t writeMemBlock(void const*, unsigned int);
};

class ReadStream : public Stream {
    sead::RamStreamSrc mReadSrc;

  public:
    size_t readMemBlock(void*, unsigned int);
};

class RamWriteStream : public WriteStream {};
class RamReadStream : public ReadStream {};

} // namespace sead

static_assert(sizeof(sead::StreamSrc) == 4, "Class doesn't match game class size");
static_assert(sizeof(sead::RamStreamSrc) == 0x10, "Class doesn't match game class size");
static_assert(sizeof(sead::Stream) == 0x10, "Class doesn't match game class size");
static_assert(sizeof(sead::RamWriteStream) == 0x20, "Class doesn't match game class size");
static_assert(sizeof(sead::RamReadStream) == 0x20, "Class doesn't match game class size");