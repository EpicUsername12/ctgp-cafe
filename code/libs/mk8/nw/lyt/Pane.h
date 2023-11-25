#ifndef _NW_LYT_PANE_H
#define _NW_LYT_PANE_H

typedef class PaneBase PaneBase;
typedef class Pane Pane;

#include <stdint.h>
#include <basis/seadTypes.h>

namespace nw {
namespace lyt {

namespace res {
/* http://mk8.tockdom.com/wiki/BFLYT_(File_Format)#pan1 */
class Pane {
    uint32_t magic; // 'pan1'
    uint32_t sectionSize;
    uint8_t flag;
    uint8_t originFlag;
    uint8_t alpha;
    uint8_t panelFlag;
    char paneName[24];
    char userData[8];
    float paneTranslation[3];
    float paneRotation[3];
    float paneScale[2];
    float paneSize[2];
};

/* http://mk8.tockdom.com/wiki/BFLYT_(File_Format)#txt1 */
class TextBox : public nw::lyt::res::Pane {
    uint16_t textBufBytes;
    uint16_t textStrBytes;
    uint16_t materialIdx;
    uint16_t fontIdx;
    uint8_t textPosition;
    uint8_t textAlignment;
    uint8_t textBoxFlag;
    uint8_t padding[1];
    float italicTilt;
    uint32_t textStrOffset;
    uint8_t textCols[8];
    float fontSize[2];
    float charSpace;
    float lineSpace;
    float textIDOffset;
    float shadow[2];
    float shadowScale[2];
    uint8_t shadowCols[8];
    float shadowItalicRatio;
    uint32_t perCharacterTransformOffset;
};

} // namespace res

namespace internal {

class PaneBase {
  public:
    void* mNext;
    void* mPrev;
    void* vtable;

    PaneBase();
};
} // namespace internal

class Pane : public internal::PaneBase {
  public:
    float unkF;
    Pane* parentPane;
    Pane* nextPane;
    Pane* prevPane;
    float vec3_Translation[3];
    float vec3_Rotate[3];
    float vec2_Scale[2];
    float width;
    float height;
    uint8_t flag;
    uint8_t alpha;
    uint8_t globalAlpha;
    uint8_t unk;
    float globalMatrix[3][4];
    float* userMatrix; // 3x4 matrix
    void* userDataList;
    char name[25];
    char userData[9];

    Pane();
    void setVisible(bool visible) {
        this->flag = (this->flag & 0xFE) | visible;
    }
};

class TextBox : public Pane {
  public:
    wchar_t* textBuffer;
    const char* textId;
    uint8_t textColor[2][4];
    void* font;
    float fontWidth;
    float fontHeight;
    float lineSpace;
    float charSpace;
    void* fontTagProc;
    uint16_t textBufferLen;
    uint16_t textLen;
    uint32_t bits;
    uint8_t textPos;
    float italicRatio;
    float shadow[2];
    float shadowSize[2];
    uint8_t shadowTopColor[4];
    uint8_t shadowBotColor[4];
    float shadowItalicRatio;
    void* material;
    void* fontBuf;
    void* perChar;

    uint16_t SetStringImpl(const wchar_t* str, uint16_t dstIdx, uint16_t strLen);

    uint16_t GetStringBufferLength();
};

} // namespace lyt
} // namespace nw

static_assert(sizeof(nw::lyt::res::Pane) == 0x54, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::Pane) == 0xA4, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::TextBox) == 0x104, "Class doesn't match game class size");

#endif