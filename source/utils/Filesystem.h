#pragma once

#include <filedevice/seadFileDeviceMgr.h>
#include <heap/seadHeapMgr.h>

#include <cafe.h>

#include "ErrorManagement.h"

namespace utils {
namespace fs {

/**
 * @brief Loads a file with the given path and alignment. (open/read/close is done by the game's code)
 * @param path File path
 * @param outSize Size output pointer
 * @param align Load alignement
 * @param heap Heap to allocate the file in
 * @param crashOnError Crash on error (file not found, etc...)
 * @return
 */
uint8_t* LoadFile(const char* path, size_t* outSize, size_t align, sead::Heap* heap = nullptr, bool crashOnError = true);

/**
 * @brief Loads a file with the given path and alignment. (open/read/close is done seperately by this function)
 * @param path File path
 * @param outSize Size output pointer
 * @param align Load alignement
 * @param crashOnError Crash on error (file not found, etc...)
 * @return
 */
uint8_t* LoadFileEx(const char* path, size_t* outSize, size_t align, bool crashOnError = true);

} // namespace fs
} // namespace utils
