#ifndef _UI_UICAPTEXTURE_HPP
#define _UI_UICAPTEXTURE_HPP

#include <basis/seadTypes.h>
#include <stdint.h>

#include <container/seadListImpl.h>
#include <container/seadPtrArray.h>
#include <mk8/nw/lyt/Texture.h>

namespace ui {
class UICapTexture {
  public:
    int field0;
    nw::lyt::TextureInfo* textureInfo;
    int field8;
    int fieldC;
    uint8_t field_10;
    uint8_t field_11;
    uint8_t field_12;
    uint8_t field_13;
    int field14;
    int field18;
    int field1C;

    UICapTexture();
};
} // namespace ui

static_assert(sizeof(ui::UICapTexture) == 0x20, "Class doesn't match game class size");

#endif