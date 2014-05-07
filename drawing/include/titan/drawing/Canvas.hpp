#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "titan/core/Types.hpp"
#include "titan/core/Quantity.hpp"

#include <map>

namespace titan
{

class Canvas
{
    protected:
        uint32 _pxWidth;
        uint32 _pxHeight;
        float32 _pxmmResolution;
        Canvas(uint32 pxWidth, uint32 pxHeight, float32 pxmmResolution);
    public:
        static Canvas whr(Quantity width, Quantity height, Quantity resolution);
        ~Canvas();
};

}

#endif

