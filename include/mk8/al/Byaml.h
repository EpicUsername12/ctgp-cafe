#ifndef _AL_BYAML_H
#define _AL_BYAML_H

#include <basis/seadTypes.h>
#include <stdint.h>

#include <math/seadVector.h>

namespace al {

struct ByamlNodeBase {
    uint8_t mValue;
};

struct ByamlNodeArray : public ByamlNodeBase {
    uint32_t mNumEntries : 24;
    ByamlNodeBase mEntries[];
};

struct ByamlNodeValue : ByamlNodeBase {
    uint32_t mData;
};

struct ByamlDictionaryEnt {
    uint32_t mNameOffset : 24;
    uint8_t mNodeType;
    union {
        uint32_t mValue;
        uint32_t mOffset;
    };
};

struct ByamlNodeDictionary : public ByamlNodeBase {
    uint32_t mNumEntries : 24;
    ByamlDictionaryEnt mEntries[];
};

struct ByamlNodeStringTable : public ByamlNodeBase {
    uint32_t mCount : 24;
    uint32_t mOffsets[];
};

struct ByamlNodePathTable : public ByamlNodeBase {
    uint32_t mCount : 24;
    uint32_t mOffsets[];
};

struct ByamlPathTableEnt {
    sead::Vector3<float> mPosition;
    sead::Vector3<float> mNormal;
    float unk;
};

class ByamlIter {
    uint8_t* mFiledata;
    ByamlNodeArray* mRootNode;

  public:
    ByamlIter();
    ByamlIter(uint8_t const* filePtr);
    ByamlIter(ByamlIter const&);

    size_t getSize() const;
    bool tryGetIterByIndex(ByamlIter*, int) const;
};

} // namespace al

#endif