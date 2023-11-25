#ifndef _SERVICE_CL_H
#define _SERVICE_CL_H

#include <mk8/nn/nex/Credentials.h>

namespace nn {
namespace nex {

class ServiceClient {
  public:
    int field_0;
    Credentials* m_Credentials;
    int field_8;

    ServiceClient();

    virtual ~ServiceClient();
    virtual void unk0() = 0;
    virtual void Bind(Credentials* creds);
    virtual void Unbind();
    virtual bool IsConnected() const;
    virtual bool IsFaulty() const;
    virtual bool ConnectionStateHasChanged() const;
};

} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::ServiceClient) == 0x10, "Class doesn't match game class size");

#endif