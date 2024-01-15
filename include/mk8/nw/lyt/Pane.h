#ifndef _NW_LYT_PANE_H
#define _NW_LYT_PANE_H

typedef class PaneBase PaneBase;
typedef class Pane Pane;

#include <stdint.h>
#include <basis/seadTypes.h>
#include <mk8/nw/lyt/Types.h>

#include <dynamic_libs/gx2_types.h>

namespace nw {
namespace lyt {

typedef class TextureInfo TextureInfo;

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
    Vector3f paneTranslation;
    Vector3f paneRotation;
    Vector2f paneScale;
    Vector2f paneSize;
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
    Vector2f fontSize;
    float charSpace;
    float lineSpace;
    float textIDOffset;
    Vector2f shadow;
    Vector2f shadowScale;
    uint8_t shadowCols[8];
    float shadowItalicRatio;
    uint32_t perCharacterTransformOffset;
};

class Material {
    char name[28];
    uint8_t foreColor[4];
    uint8_t backColor[4];
    uint32_t flags;
    /*
    0-3	        Unknown.
    4	        Has Material Color.
    5	        Unknown.
    6	        Has Channel Control.
    7	        Has Blend Mode.
    8	        Has Alpha Compare.
    9-13	    TEV Stage Count.
    14-16	    Indirect Texture Stage Count.
    17-18	    Indirect Texture SRT Count.
    19	        Has TEV Swap Table.
    20-23	    TexCoord Gen Count.
    24-27	    Texture SRT Count.
    28-31	    Texture Map Count.
    */
};

} // namespace res

namespace internal {

class PaneBase {
  public:
    void* mNext;
    void* mPrev;

    PaneBase();

    virtual ~PaneBase() = 0;
};
} // namespace internal

class TexMap {
  public:
    int field_00;
    uint16_t m_width;
    uint16_t m_height;
    u32 m_flags;
    GX2Sampler m_sampler;
    GX2Texture* m_texture;

    void Set(TextureInfo const* texture);
};

class Material {
  public:
    uint8_t foreColor[4];
    uint8_t backColor[4];
    int field_08;
    int field_0C;
    TexMap* texMap;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;

    virtual ~Material();
};

class Pane : public internal::PaneBase {

    typedef class CalculateMtxContext CalculateMtxContext;
    typedef class DrawInfo DrawInfo;

  public:
    float unkF;
    Pane* parentPane;
    Pane* nextPane;
    Pane* prevPane;
    Vector3f translation;
    Vector3f rotate;
    Vector2f scale;
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

    virtual ~Pane();
    virtual void RTII_unk1();
    virtual void unk2() = 0;
    virtual void unk3() = 0;
    virtual void unk4() = 0;

    virtual void SetColorElement(uint32_t, u8 value);

    virtual void unk5() = 0;
    virtual void SetVtxColorElement(uint32_t, u8 value);

    virtual Material* GetMaterial() const;
    virtual int GetMaterialNum() const;

    virtual Pane* FindPaneByName(char const* name, bool recursive);
    virtual Material* FindMaterialByName(char const* userData, bool recursive);

    virtual void unk6() = 0;
    virtual void unk7() = 0;
    virtual void unk8() = 0;

    virtual void CalculateMtx(CalculateMtxContext& ctx, bool);
    virtual void Draw(DrawInfo& info);
    virtual void DrawSelf(DrawInfo& info);
    virtual void LoadMtx(DrawInfo& info);

    virtual Pane* FindPaneByNameRecursive(char const* name);
    virtual Material* FindMaterialByNameRecursive(char const* userData);

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
    Vector2f shadow;
    Vector2f shadowScale;
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
static_assert(sizeof(nw::lyt::TexMap) == 0x1c, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::Material) == 0x3c, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::Pane) == 0xA4, "Class doesn't match game class size");
static_assert(sizeof(nw::lyt::TextBox) == 0x104, "Class doesn't match game class size");

#endif