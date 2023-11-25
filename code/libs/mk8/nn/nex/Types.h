#ifndef _NN_NEX_TYPES_H
#define _NN_NEX_TYPES_H

#include <list>
#include <map>
#include <vector>

#include <basis/seadTypes.h>
#include <stdint.h>

namespace nn {
namespace nex {

class AtomicValue {
  public:
    int m_Value;
};

typedef uint64_t Time;

class RefCountedObject {
  public:
    int field_0;
    nn::nex::AtomicValue refCount;
    char field_8;
    char field_9;
    char field_A;
    char field_B;

    virtual ~RefCountedObject();
};

class qResult {
  public:
    int field_0;
    int field_4;
    int field_8;
};

// RootObject for allocation
class RootObject {
  public:
    // For RTTI purpose only.
    virtual void ret_() {
    }
};

template <typename T> class qVector : public std::vector<T> {};

template <typename Key, typename T> class qMap : public std::map<Key, T> {};

class CustomDataHolder {
  public:
    int field_0;
    int field_4;
};

class String {
  public:
    wchar_t* m_Str;

    virtual ~String();
};

class CallContext : nn::nex::RefCountedObject {
  public:
    int field_10;
    int field_14;
    std::list<void*> m_InternalDataList;
    nn::nex::qVector<int> m_UserContextVector;
    nn::nex::qResult m_Result;
    int m_Id;
    int field_44;
    int field_48;
    int field_4C;
    nn::nex::Time m_Deadline;
};

class SystemComponent : public nn::nex::RefCountedObject {
  public:
    nn::nex::String m_String;
    int field_18;
    int field_1C;
    int field_20;

    virtual ~SystemComponent();
};

} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::SystemComponent) == 0x24, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::String) == 0x8, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::CustomDataHolder) == 0x8, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::Time) == 0x8, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::qResult) == 0x0C, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::RootObject) == 4, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::qVector<int>) == 16, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::AtomicValue) == 4, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::RefCountedObject) == 0x10, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::CallContext) == 0x58, "Class doesn't match game class size");

#endif