#ifndef __COLOR_H__
#define __COLOR_H__

#include "titan/core/Types.hpp"

#include <iostream>

namespace titan
{

class Color
{
    protected:
        uint8 _alpha;
        uint8 _red;
        uint8 _green;
        uint8 _blue;

        Color(uint8 alpha=255, uint8 red=255, uint8 green=255, uint8 blue=255);
    public:
        
        static Color argb32(float32 alpha=1.0, float32 red=1.0, float32 green=1.0, float32 blue=1.0);

        inline float32 getAlpha() const
        {
            return _alpha/255.0;
        }
        
        inline float32 getRed() const
        {
            return _red/255.0;
        }
        
        inline float32 getGreen() const
        {
            return _green/255.0;
        }
        
        inline float32 getBlue() const
        {
            return _blue/255.0;
        }
        
        inline void setAlpha(float32 alpha)
        {
            _alpha=((uint32)(alpha*255.0))%256;
        }
        
        inline void setRed(float32 red)
        {
            _red=((uint32)(red*255.0))%256;
        }
        
        inline void setGreen(float32 green)
        {
            _green=((uint32)(green*255.0))%256;
        }
        
        inline void setBlue(float32 blue)
        {
            _blue=((uint32)(blue*255.0))%256;
        }

        inline bool operator==(const Color& color)
        {
            return _alpha==color._alpha && _red==color._red && _green == color._green && _blue == color._blue;
        }

        inline bool operator!=(const Color& color)
        {
            return (_alpha!=color._alpha || _red!=color._red || _green != color._green || _blue != color._blue);
        }

        ~Color();
};

}

#endif

