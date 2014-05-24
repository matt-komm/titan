#include "titan/drawing/Canvas.hpp"

namespace titan
{

Canvas::Canvas(uint32 pxWidth, uint32 pxHeight, ColorType::type format):
    _pxWidth(pxWidth),
    _pxHeight(pxHeight),
    _format(format)
{
}

Canvas::~Canvas()
{
}

}
