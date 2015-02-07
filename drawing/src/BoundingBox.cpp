#include "titan/drawing/BoundingBox.hpp"

namespace titan
{

BoundingBox::BoundingBox(const Quantity& x1,const Quantity& y1,const Quantity& x2,const Quantity& y2):
    _x1(x1),
    _y1(y1),
    _x2(x2),
    _y2(y2)
{
}

BoundingBox::~BoundingBox()
{
}

}
