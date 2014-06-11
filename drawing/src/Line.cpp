#include "titan/drawing/Line.hpp"

namespace titan
{

Line::Line(Quantity x1,Quantity y1,Quantity x2,Quantity y2):
	DrawType(),
	_x1(x1),
	_x2(x2),
	_y1(y1),
	_y2(y2)
{
}

void Line::draw(Canvas& canvas)
{
	//get apropriate axes from canvas
	// -> caculate px
	//call backend
}

Line::~Line()
{
}

}
