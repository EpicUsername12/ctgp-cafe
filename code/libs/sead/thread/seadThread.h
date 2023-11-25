#ifndef SEAD_THREAD_H_
#define SEAD_THREAD_H_

#include <heap/seadDisposer.h>
#include <prim/seadNamable.h>
#include <container/seadTList.h>

namespace sead {
class Thread : public IDisposer, public INamable {
  public:
    virtual ~Thread();

    virtual void destroy();
    virtual bool sendMessage(s32, u32); // sendMessage(MessageQueue::Element, MessageQueue::BlockType)
    virtual s32 recvMessage(u32);       // MessageQueue::Element recvMessage(MessageQueue::BlockType)
    virtual bool start();
    virtual void quit(bool);
    virtual void waitDone();
    virtual void quitAndDestroySingleThread(bool is_jam);
    //...

    int unk1;
    int unk2;

    int mMessageQueue[16]; // one sead::MessageQueue
    size_t mStackSize;
    TListNode<Thread*> mListNode;
    int mFindContainHeapCache;
    int mQueueBlockType;
    int mQuitMsg;
    int mId;
    int mState;
    int mAffinity;
    void* mStackTop;
    void* mStackTopForCheck;
    int mPriority;
};

static_assert(sizeof(Thread) == 0x98, "sead::Thread size mismatch");

} // namespace sead

#endif // SEAD_THREAD_H_
