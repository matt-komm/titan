#include "titan/drawing/Canvas.hpp"

namespace titan
{

Canvas::Canvas(uint32 pxWidth, uint32 pxHeight, float32 pxmmResolution):
    _pxWidth(pxWidth),
    _pxHeight(pxHeight),
    _pxmmResolution(pxmmResolution)
{
}

Canvas::~Canvas()
{
}

}
