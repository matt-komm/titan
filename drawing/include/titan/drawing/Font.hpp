#ifndef __FONT_H__
#define __FONT_H__

#include "titan/drawing/Color.hpp"

#include "titan/core/Types.hpp"

#include <string>

namespace titan
{


class Font
{
    protected:
        std::string _fontName;
        float32 _fontSize;
        Color _fontColor;
        FontStyle::type _fontStyle;


    public:
        Font(std::string fontName="Arial", float32 fontSize=12.0, Color fontColor=Color::argb32(), FontStyle::type fontStyle=FontStyle::NORMAL);
        static Font byName(std::string fontName="Arial", float32 fontSize=12.0, Color fontColor=Color::argb32(), FontStyle::type fontStyle=FontStyle::NORMAL);
        ~Font();
        
        inline const std::string& getFontName() const
        {
            return _fontName;
        }
        
        inline std::string& getFontName()
        {
            return _fontName;
        }
        
        inline float32 getFontSize()
        {
            return _fontSize;
        }
        
        inline const Color& getColor() const
        {
        	return _fontColor;
        }

        inline Color& getColor()
        {
        	return _fontColor;
        }

        inline FontStyle::type getFontStyle()
        {
        	return _fontStyle;
        }

        inline void setFontName(const std::string& fontName)
        {
            _fontName=fontName;
        }
        
        inline void setFontSize(float32 fontSize)
        {
            _fontSize=fontSize;
        }
        
        inline void setColor(const Color& fontColor)
        {
        	_fontColor=fontColor;
        }

        inline void setFontStyle(FontStyle::type fontStyle)
        {
        	_fontStyle=fontStyle;
        }

        inline bool operator==(const Font& font)
        {
            return _fontName==font._fontName && _fontSize==font._fontSize && _fontStyle==font._fontStyle;
        }
        
        inline bool operator!=(const Font& font)
        {
            return _fontName!=font._fontName || _fontSize!=font._fontSize || _fontStyle!=font._fontStyle;
        }
};

}
#endif

