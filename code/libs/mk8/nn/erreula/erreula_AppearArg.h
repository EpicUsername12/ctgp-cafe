#ifndef NN_ERREULA_APPEAR_ARG_H_
#define NN_ERREULA_APPEAR_ARG_H_

#include <basis/seadTypes.h>
#include <stdint.h>

namespace nn {
namespace erreula {

enum ErrorType {
    ERROR_NINTENDO_ERROR = 0, // Nintendo Error
    ERROR_NO_BTN,             // Custom with no button
    ERROR_1_BTN,              // Custom with 1 button
    ERROR_2_BTN,              // Custom with 2 button
};

enum RenderTarget {
    RENDER_TV = 0, // Render only to TV
    RENDER_DRC,    // Render only to DRC
    RENDER_TV_DRC, // Render to TV and DRC
};

class AppearArg {
  public:
    ErrorType errorType;
    RenderTarget screenRender;
    int wiimoteIndex; // Wiimote that will control the Error screen, 4+ = None
    int unk;
    int errorCode;
    int swapInterval; // Number of vsyncs before each new frame
    const wchar_t* errorText;
    const wchar_t* btn1Text;
    const wchar_t* btn2Text;
    const wchar_t* titleText;
    bool drawWiiRemoteCursor;

    AppearArg()
        : errorType(ERROR_NINTENDO_ERROR),
          screenRender(RENDER_TV_DRC),
          wiimoteIndex(0),
          unk(0),
          errorCode(0),
          swapInterval(1),
          errorText(nullptr),
          btn1Text(nullptr),
          btn2Text(nullptr),
          titleText(nullptr),
          drawWiiRemoteCursor(true) {
    }
};

} // namespace erreula
} // namespace nn

#endif