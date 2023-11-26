#pragma once

#include <mk8/ui/UILoader.h>
#include <vector>
#include <algorithm>

namespace ctgp {
class MessageRedirector {

  public:
    void addMessage(int id, const wchar_t* message);
    void modifiyMessage(int id, const wchar_t* message);
    void removeMessage(int id);

    const wchar_t* findMessage(int id) const;

    static MessageRedirector* GetInstance();

  private:
    class Message {
      public:
        bool operator==(const Message& other) const {
            return m_id == other.m_id;
        }

        explicit Message(int id, const wchar_t* message) : m_id(id), m_message(const_cast<wchar_t*>(message)) {
        }

        int m_id;
        const wchar_t* m_message;
    };

    typedef std::vector<Message> MessageList;
    typedef MessageList::iterator MessageListIterator;
    typedef MessageList::const_iterator MessageListConstIterator;

    MessageList m_messages;

    static MessageRedirector* sInstance;
};

extern "C" const wchar_t* hook_ui_UILoader_findMessage_(ui::UILoader* _this, int id);

} // namespace ctgp