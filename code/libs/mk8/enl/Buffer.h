#ifndef _ENL_CONTENT_BUFFER_H
#define _ENL_CONTENT_BUFFER_H

#include <basis/seadTypes.h>
#include <stdint.h>

namespace enl {

class Buffer {

  public:
    uint8_t* data;
    size_t capacity;
    size_t size;
    bool isAllocated;

    Buffer(uint8_t* data, size_t sz);
    void clear();
    void set(uint8_t const* data, size_t size);
};

class DoubleBuffer {
  public:
    sead::PtrArray<enl::Buffer> array;
    uint8_t* ptrs[2];
    int currentIndex;
    char field_18;

    DoubleBuffer(int numBuf, size_t sizeBuf) {
        this->array.setBuffer(numBuf, this->ptrs);
        for (int i = 0; i < numBuf; i++) {
            enl::Buffer* buf = new enl::Buffer(nullptr, sizeBuf);
            this->array.pushBack(buf);
        }
        this->currentIndex = 0;
    }
};

} // namespace enl

static_assert(sizeof(enl::Buffer) == 0x10, "Class doesn't match game class size");
static_assert(sizeof(enl::DoubleBuffer) == 0x1C, "Class doesn't match game class size");

#endif