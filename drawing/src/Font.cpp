#include "titan/drawing/Font.hpp"

namespace titan
{

Font::Font(std::string fontName,float32 fontSize, Color fontColor, FontStyle::type fontStyle):
    _fontName(fontName),
    _fontSize(fontSize),
    _fontColor(fontColor),
    _fontStyle(fontStyle)
{
}

Font Font::byName(std::string fontName,float32 fontSize, Color fontColor, FontStyle::type fontStyle)
{
    return Font(fontName,fontSize,fontColor,fontStyle);
}


Font::~Font()
{
}

}
