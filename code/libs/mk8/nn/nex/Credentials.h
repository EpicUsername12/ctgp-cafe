#ifndef _NN_NEX_AUTH_H
#define _NN_NEX_AUTH_H

#include <mk8/nn/nex/Types.h>

namespace nn {
namespace nex {

class Credentials : public nn::nex::RefCountedObject {
  public:
    int m_PrincipalId;
    int m_RVConnectionId;
    nn::nex::String m_Username;
    nn::nex::String m_Password;
    int streamManager;
    int authConnection;
    int secureConnection;
};
} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::Credentials) == 0x34, "Class doesn't match game class size");

#endif