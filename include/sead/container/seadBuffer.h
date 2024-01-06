// clang-format off

#ifndef SEAD_BUFFER_H_
#define SEAD_BUFFER_H_

#include <basis/seadTypes.h>

namespace sead {

class Heap;

template <typename T>
class Buffer
{
private:
    typedef s32 (*CompareCallback)(const T*, const T*);

public:
    Buffer()
        : mSize(0)
        , mBuffer(NULL)
    {
    }

    Buffer(s32, T*);

public:
    class iterator
    {
    public:
        explicit iterator(T* buffer, s32 index = 0) : mIndex(index), mBuffer(buffer) {}
        bool operator==(const iterator& rhs) const
        {
            return mIndex == rhs.mIndex && mBuffer == rhs.mBuffer;
        }
        bool operator!=(const iterator& rhs) const { return !operator==(rhs); }
        iterator& operator++()
        {
            ++mIndex;
            return *this;
        }
        T& operator*() const { return mBuffer[mIndex]; }
        T* operator->() const { return &mBuffer[mIndex]; }
        s32 getIndex() const { return mIndex; }

    private:
        s32 mIndex;
        T* mBuffer;
    };

    class constIterator
    {
    public:
        explicit constIterator(const T* buffer, s32 index = 0) : mIndex(index), mBuffer(buffer) {}
        bool operator==(const constIterator& rhs) const
        {
            return mIndex == rhs.mIndex && mBuffer == rhs.mBuffer;
        }
        bool operator!=(const constIterator& rhs) const { return !operator==(rhs); }
        constIterator& operator++()
        {
            ++mIndex;
            return *this;
        }
        const T& operator*() const { return mBuffer[mIndex]; }
        const T* operator->() const { return &mBuffer[mIndex]; }
        s32 getIndex() const { return mIndex; }

    private:
        s32 mIndex;
        const T* mBuffer;
    };

    iterator begin() { return iterator(mBuffer); }
    iterator begin(s32 idx)
    {
        if (u32(size()) < u32(idx))
        {
            //SEAD_ASSERT_MSG(false, "range over [0,%d] : %d", size(), idx);
            return end();
        }
        return iterator(mBuffer, idx);
    }

    constIterator begin() const { return constIterator(mBuffer); }
    constIterator begin(s32 idx) const
    {
        if (u32(size()) < u32(idx))
        {
            //SEAD_ASSERT_MSG(false, "range over [0,%d] : %d", size(), idx);
            return end();
        }
        return constIterator(mBuffer, idx);
    }

    iterator end() { return iterator(mBuffer, mSize); }
    constIterator end() const { return constIterator(mBuffer, mSize); }

    class reverseIterator
    {
    public:
        explicit reverseIterator(T* buffer, s32 index = 0) : mIndex(index), mBuffer(buffer) {}
        bool operator==(const reverseIterator& rhs) const { return mIndex == rhs.mIndex; }
        bool operator!=(const reverseIterator& rhs) const { return !operator==(rhs); }
        reverseIterator& operator++()
        {
            --mIndex;
            return *this;
        }
        T& operator*() const { return mBuffer[mIndex]; }
        T* operator->() const { return &mBuffer[mIndex]; }
        s32 getIndex() const { return mIndex; }

    private:
        s32 mIndex;
        T* mBuffer;
    };

    reverseIterator rbegin() { return reverseIterator(mBuffer, mSize - 1); }
    reverseIterator rbegin(s32 index) { return reverseIterator(mBuffer, index); }
    reverseIterator rend() { return reverseIterator(mBuffer, -1); }

    // TODO
    class reverseConstIterator { };

public:

public:
    void allocBuffer(s32 size, s32 alignment);
    void allocBuffer(s32 size, Heap* heap, s32 alignment);
    bool tryAllocBuffer(s32 size, s32 alignment);
    bool tryAllocBuffer(s32 size, Heap* heap, s32 alignment);
    void freeBuffer();

    void setBuffer(s32 size, T* bufferptr)
    {
        if (size > 0)
        {
            if (bufferptr != NULL)
            {
                mSize = size;
                mBuffer = bufferptr;
            }
            else
            {
                //SEAD_ASSERT_MSG(false, "bufferptr is null");
            }
        }
        else
        {
            //SEAD_ASSERT_MSG(false, "size[%d] must be larger than zero", size);
        }
    }

    bool isBufferReady() const;
    T& operator()(s32);
    const T& operator()(s32) const;

    T& operator[] (s32 x)
    {
        if (x < mSize)
            return mBuffer[x];

        //SEAD_ASSERT_MSG(false, "index exceeded [%d/%d]", x, mSize);
        return mBuffer[0];
    }

    const T& operator[] (s32 x) const
    {
        if (x < mSize)
            return mBuffer[x];

        //SEAD_ASSERT_MSG(false, "index exceeded [%d/%d]", x, mSize);
        return mBuffer[0];
    }

    T* get(s32 x)
    {
        if (x < mSize)
            return &mBuffer[x];

        //SEAD_ASSERT_MSG(false, "index exceeded [%d/%d]", x, mSize);
        return NULL;
    }

    const T* get(s32 x) const
    {
        if (x < mSize)
            return &mBuffer[x];

        //SEAD_ASSERT_MSG(false, "index exceeded [%d/%d]", x, mSize);
        return NULL;
    }

    T* unsafeGet(s32 x)
    {
        //SEAD_ASSERT_MSG(x < mSize, "index exceeded [%d/%d]", x, mSize);
        return &mBuffer[x];
    }

    const T* unsafeGet(s32 x) const
    {
        //SEAD_ASSERT_MSG(x < mSize, "index exceeded [%d/%d]", x, mSize);
        return &mBuffer[x];
    }

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    s32 size() const;
    s32 getSize() const { return mSize; }
    T* getBufferPtr() { return mBuffer; }
    const T* getBufferPtr() const { return mBuffer; }
    u32 getByteSize() const { return mSize*sizeof(T); }
    Buffer<T>& operator=(const Buffer<T>&);
    bool isRangeValid(s32) const;
    void fill(const T&);
    void heapSort(CompareCallback, s32, s32);
    void heapSort(s32, s32);
    s32 binarySearch(const T&) const;

protected:
    static s32 compareT(const T*, const T*);
    static s32 defaultBinarySearchCompare(const T&, const T&);

public:
    template <typename Key>
    s32 binarySearch(const Key&, s32 (*)(const T&, const Key&)) const;

protected:
    s32 mSize;
    T* mBuffer;
};
#ifdef cafe
static_assert(sizeof(Buffer<int>) == 8, "sead::Buffer<T> size mismatch");
#endif // cafe

} // namespace sead

#endif // SEAD_BUFFER_H_
