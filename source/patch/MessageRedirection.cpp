#include "MessageRedirection.h"

namespace ctgp {

MessageRedirector* MessageRedirector::s_Instance = nullptr;

const wchar_t* convertToWchar(const char* str) {
    size_t len = strlen(str) + 1;
    wchar_t* buffer = new wchar_t[len];
    memset(buffer, 0, len * sizeof(wchar_t));
    for (int i = 0; i < len; i++) {
        buffer[i] = str[i] & 0xff;
    }

    return buffer;
}

const wchar_t* copyWchar(const wchar_t* str) {
    size_t len = wcslen(str) + 1;
    wchar_t* buffer = new wchar_t[len];
    OSBlockSet(buffer, 0, len);
    memcpy(buffer, str, len);
    return buffer;
}

void MessageRedirector::addMessage(int id, const char* message) {
    this->m_messages.push_back(Message(id, convertToWchar(message)));
}

void MessageRedirector::addMessage(int id, const wchar_t* message, bool copyOnInsert) {
    if (copyOnInsert)
        message = copyWchar(message);

    this->m_messages.push_back(Message(id, message));
}

void MessageRedirector::modifiyMessage(int id, const char* message) {
    const MessageListIterator& end = this->m_messages.end();
    for (MessageListIterator it = this->m_messages.begin(); it != end; ++it) {
        if (it->m_id == id) {
            it->m_message = (wchar_t*)convertToWchar(message);
            return;
        }
    }
}

void MessageRedirector::modifiyMessage(int id, const wchar_t* message, bool copyOnInsert) {
    if (copyOnInsert)
        message = copyWchar(message);

    const MessageListIterator& end = this->m_messages.end();
    for (MessageListIterator it = this->m_messages.begin(); it != end; ++it) {
        if (it->m_id == id) {
            it->m_message = (wchar_t*)message;
            return;
        }
    }
}

void MessageRedirector::removeMessage(int id) {
    PANIC_UNIMPLEMENTED();
}

const wchar_t* MessageRedirector::findMessage(int id) const {
    const MessageListConstIterator& end = this->m_messages.end();
    for (MessageListConstIterator it = this->m_messages.begin(); it != end; ++it) {
        if (it->m_id == id) {
            return it->m_message;
        }
    }

    return nullptr;
}

MessageRedirector* MessageRedirector::GetInstance() {
    if (MessageRedirector::s_Instance == nullptr) {
        MessageRedirector::s_Instance = new MessageRedirector();
    }

    return MessageRedirector::s_Instance;
}

// ============================================================================
// Game hooks
// ============================================================================

const wchar_t* hook_ui_UILoader_findMessage_(ui::UILoader* _this, int id) {
    const wchar_t* message = MessageRedirector::GetInstance()->findMessage(id);
    if (!message) {
        message = _this->findMessage_(id);
    }

    return message;
}

} // namespace ctgp
