#include "titan/drawing/Canvas.hpp"

namespace titan
{

Canvas::Canvas(uint32 pxWidth, uint32 pxHeight, float32 pxmmResolution):
    _pxWidth(pxWidth),
    _pxHeight(pxHeight),
    _pxmmResolution(pxmmResolution)
{
}

Canvas Canvas::whr(Quantity width, Quantity height, Quantity resolution)
{
    /*
    float32 pxWidth = width.convert(mm)/resolution.convert(mm);
    float32 pxHeight = height.convert(mm)/resolution.convert(mm);
    Canvas cv(pxWidth,pxHeight,resolution.convert(mm));
    return cv;
    */
    
}

Canvas::~Canvas()
{
}

}
