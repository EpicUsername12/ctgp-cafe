#ifndef _MK8_ENL_MGR_H
#define _MK8_ENL_MGR_H

#include <basis/seadTypes.h>
#include <stdint.h>
#include <prim/seadSafeString.h>

namespace enl {

class ParamBase {

    struct ENLNetworkConfig {
        int field_0;
        int field_4;
        int field_8;
        int field_C;
        int field_10;
        int field_14;
        int field_18;
        int field_1C;
        int field_20;
        int field_24;
    };

  public:
    int field_0;
    char field_4;
    char field_5;
    char field_6;
    char field_7;
    ENLNetworkConfig m_Config0;
    ENLNetworkConfig m_Config1;
    int field_58;
    char field_5C;
    char field_5D;
    char field_5E;
    char field_5F;
};

class MemoryManager {
  public:
    int field_0;
    int field_4;
    int vtable;
};

class PiaMemoryManager {
  public:
    int buffer;
    int size;
    int field_8;
};

class NinNexMemoryManager : public enl::MemoryManager {
  public:
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
};

class NinMemorySetting {
  public:
    char field_0;
    char field_1;
    char field_2;
    char field_3;
    int field_4;
    int field_8;
    int field_C;
    int transportMemory;
    int field_14;
};

class PiaMemorySetting : public enl::PiaMemoryManager {
  public:
};

class NinPiaMemoryManager : public enl::MemoryManager {
  public:
    class CreateArg : public enl::ParamBase {
      public:
        enl::NinMemorySetting m_NinMemorySetting;
        enl::PiaMemorySetting m_PiaMemorySetting;
    };

  public:
    enl::NinNexMemoryManager m_NexMemoryManager;
    enl::PiaMemoryManager m_PiaMemoryManager;
};

} // namespace enl

static_assert(sizeof(enl::PiaMemorySetting) == 0x0c, "Class doesn't match game class size");
static_assert(sizeof(enl::NinMemorySetting) == 0x18, "Class doesn't match game class size");
static_assert(sizeof(enl::ParamBase) == 0x60, "Class doesn't match game class size");
static_assert(sizeof(enl::NinPiaMemoryManager::CreateArg) == 0x84, "Class doesn't match game class size");
static_assert(sizeof(enl::NinPiaMemoryManager) == 0x50, "Class doesn't match game class size");
static_assert(sizeof(enl::NinNexMemoryManager) == 0x38, "Class doesn't match game class size");
static_assert(sizeof(enl::PiaMemoryManager) == 0x0C, "Class doesn't match game class size");
static_assert(sizeof(enl::MemoryManager) == 0x0C, "Class doesn't match game class size");

#endif