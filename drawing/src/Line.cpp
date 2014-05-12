#include "titan/drawing/Line.hpp"

namespace titan
{

Line::Line():
    _x1(0*mm),
    _x2(0*mm),
    _y1(0*mm),
    _y2(0*mm)
{
}

Line::Line(Quantity x1,Quantity y1,Quantity x2,Quantity y2):
	_x1(x1),
	_x2(x2),
	_y1(y1),
	_y2(y2)
{
}

void Line::draw(Canvas& canvas)
{
}

Line::~Line()
{
}

}
