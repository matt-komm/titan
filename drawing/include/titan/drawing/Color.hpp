#ifndef __COLOR_H__
#define __COLOR_H__

#include "titan/core/Types.hpp"

namespace titan
{

class Color
{
    protected:
        uint8 _alpha;
        uint8 _red;
        uint8 _green;
        uint8 _blue;
    public:
        Color();
        
        static Color argb(uint8 alpha=255, uint8 red=255, uint8 green=255, uint8 blue=255);
        
        inline uint8 getAlpha()
        {
            return _alpha;
        }
        
        inline uint8 getRed()
        {
            return _red;
        }
        
        inline uint8 getGreen()
        {
            return _green;
        }
        
        inline uint8 getBlue()
        {
            return _blue;
        }
        
        inline void setAlpha(uint8 alpha)
        {
            _alpha=alpha;
        }
        
        inline void setRed(uint8 red)
        {
            _red=red;
        }
        
        inline void setGreen(uint8 green)
        {
            _green=green;
        }
        
        inline void setBlue(uint8 blue)
        {
            _blue=blue;
        }
        
        
        
        ~Color();
};

}

#endif

