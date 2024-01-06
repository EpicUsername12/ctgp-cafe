#include "Filesystem.h"

uint8_t* utils::fs::LoadFile(const char* path, size_t* outSize, size_t align, sead::Heap* heap, bool crashOnError) {

    sead::FileDevice::LoadArg loadArg;
    loadArg.path = path;
    loadArg.alignment = align;
    loadArg.heap = heap;

    uint8_t* mem = sead::FileDeviceMgr::instance()->tryLoad(loadArg);
    if (!mem && crashOnError) {
        PANIC("utils::fs::LoadFile(%s) failed!\n"
              "Couldn't load the file.. Please check your files.",
              path);
        return nullptr;
    }

    if (outSize) {
        *outSize = loadArg.read_size;
    }

    return mem;
}

uint8_t* utils::fs::LoadFileEx(const char* path, size_t* outSize, size_t align, bool crashOnError) {

    sead::FileHandle handle;
    sead::MainFileDevice* fileDevice = sead::FileDeviceMgr::instance()->getMainFileDevice();

    if (!fileDevice->tryOpen(&handle, path, sead::FileDevice::cFileOpenFlag_ReadOnly, 0)) {
        PANIC("utils::fs::LoadFileEx:open(%s) failed!\n"
              "Couldn't load the file.. Please check your files.",
              path);
        return nullptr;
    }

    size_t fsize, rsize;
    if (!fileDevice->tryGetFileSize(&fsize, &handle)) {
        PANIC("utils::fs::LoadFileEx:size(%s) failed!\n"
              "Couldn't load the file.. Please check your files.",
              path);
        return nullptr;
    }

    uint8_t* mem = (uint8_t*)MEMAllocFromDefaultHeapEx(fsize, align);
    if (!fileDevice->tryRead(&rsize, &handle, mem, fsize)) {
        PANIC("utils::fs::LoadFileEx:read(%s) failed!\n"
              "Couldn't load the file.. Please check your files.",
              path);
        MEMFreeToDefaultHeap(mem);
        return nullptr;
    }

    if (!fileDevice->tryClose(&handle)) {
        PANIC("utils::fs::LoadFileEx:close(%s) failed!\n"
              "Couldn't load the file.. Please check your files.",
              path);
        MEMFreeToDefaultHeap(mem);
        return nullptr;
    }

    if (outSize) {
        *outSize = rsize;
    }

    return mem;
}