#ifndef __LINE_H__
#define __LINE_H__

#include "titan/core/Quantity.hpp"
#include "titan/drawing/Canvas.hpp"
#include "titan/drawing/DrawType.hpp"
#include "titan/drawing/Stroke.hpp"

namespace titan
{

class Line:
	public DrawType
{
    protected:
        Quantity _x1, _x2, _y1, _y2;
        Stroke _stroke;
    public:
        Line(Quantity x1=0*mm,Quantity y1=0*mm,Quantity x2=0*mm,Quantity y2=0*mm);
        virtual void draw(Canvas& canvas);
        ~Line();
};

}

#endif

