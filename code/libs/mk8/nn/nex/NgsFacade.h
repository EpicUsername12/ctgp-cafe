#ifndef _NN_NEX_NGS_FACADE_H
#define _NN_NEX_NGS_FACADE_H

#include <mk8/nn/nex/Credentials.h>
#include <mk8/nn/nex/Station.h>
#include <mk8/nn/nex/Types.h>

namespace nn {
namespace nex {

class BackEndServices : RootObject {
  public:
    int field_4;
    int field_8;
    int field_C;
    nn::nex::CallContext m_CallContext;
    int field_68;
    int field_6C;
    nn::nex::Credentials* m_Credentials;
    uint16_t m_PortNumber;
    char field_76;
    char field_77;
    int m_StreamFlags;
    int m_NotificationEventManager;
    int m_NintendoNotificationManager;
    char field_84;
    char field_85;
    char field_86;
    char field_87;
    int m_GetStreamMgrFunc;
    int m_LoginJob;
    int field_90;
    int m_TerminateJob;
    int m_EffectiveLoginTimeout;
    int field_9C;
    int field_A0;
    char field_A4;
    char field_A5;
    char field_A6;
    char field_A7;
    nn::nex::StationURL m_StationURL;
    int vtable;
    int field_E4;
};

class RendezVous : public nn::nex::BackEndServices {
  public:
};

class NgsFacade : public nn::nex::RendezVous {
  public:
    int field_E8;
    int m_CurrentJob;
    int m_TerminateJob;
    int m_NASErrorCode;
    int m_HTTPStatusCode;
    nn::nex::qResult m_Result;
    int field_108;
    int field_10C;
    nn::nex::CustomDataHolder m_AuthInfoHolder;
};

} // namespace nex
} // namespace nn

static_assert(sizeof(nn::nex::BackEndServices) == 0xE8, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::RendezVous) == 0xE8, "Class doesn't match game class size");
static_assert(sizeof(nn::nex::NgsFacade) == 0x118, "Class doesn't match game class size");

#endif