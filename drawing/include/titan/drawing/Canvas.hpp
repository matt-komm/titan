#ifndef __CANVAS_H__
#define __CANVAS_H__

#include "titan/core/Types.hpp"
#include "titan/core/Quantity.hpp"
#include "titan/drawing/Context.hpp"

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
        virtual Canvas* create(Quantity width, Quantity height, Quantity resolution) = 0;
        virtual Context* getContext() = 0;
        ~Canvas();
};

}

#endif

