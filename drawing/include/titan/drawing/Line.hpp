#ifndef __LINE_H__
#define __LINE_H__

#include "titan/core/Quantity.hpp"
#include "titan/drawing/Canvas.hpp"
#include "titan/drawing/Drawable.hpp"
#include "titan/drawing/Stroke.hpp"

namespace titan
{

class Line:
	public Drawable
{
    protected:
        Quantity _x1, _x2, _y1, _y2;
        Stroke _stroke;
    public:
        Line();
        Line(Quantity x1,Quantity y1,Quantity x2,Quantity y2);
        virtual void draw(Canvas& canvas);
        ~Line();
};

}

#endif

