#include "patch_MessageRedirection.h"

namespace ctgp {

MessageRedirector* MessageRedirector::sInstance = nullptr;

void MessageRedirector::addMessage(int id, const wchar_t* message) {
    this->m_messages.push_back(Message(id, message));
}

void MessageRedirector::modifiyMessage(int id, const wchar_t* message) {
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
    if (MessageRedirector::sInstance == nullptr) {
        MessageRedirector::sInstance = new MessageRedirector();
    }

    return MessageRedirector::sInstance;
}

const wchar_t* hook_ui_UILoader_findMessage_(ui::UILoader* _this, int id) {
    const wchar_t* message = MessageRedirector::GetInstance()->findMessage(id);
    if (!message) {
        message = _this->findMessage_(id);
    }

    return message;
}

} // namespace ctgp
