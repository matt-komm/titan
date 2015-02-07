#ifndef __LINE_H__
#define __LINE_H__

#include "titan/core/Quantity.hpp"
#include "titan/drawing/CanvasInterface.hpp"
#include "titan/drawing/DrawType.hpp"
#include "titan/drawing/Stroke.hpp"
#include "titan/xml/Serializable.hpp"

namespace titan
{

class Line:
    public DrawType
{
    protected:
        Quantity _x1, _x2, _y1, _y2;
        Stroke _stroke;
        BoundingBox _boundingBox;

    public:
        Line(Quantity x1=0*mm,Quantity y1=0*mm,Quantity x2=0*mm,Quantity y2=0*mm);
        inline void setX1(const Quantity& x1)
        {
            _x1=x1;
            _boundingBox.setX1(x1);
        }
        inline void setX2(const Quantity& x2)
        {
            _x2=x2;
            _boundingBox.setX2(x2);
        }
        inline void setY1(const Quantity& y1)
        {
            _y1=y1;
            _boundingBox.setY1(y1);
        }
        inline void setY2(const Quantity& y2)
        {
            _y2=y2;
            _boundingBox.setY2(y2);
        }
        virtual void draw(const Drawing& drawing, CanvasInterface& canvas);
        virtual const BoundingBox& getBoundingBox() const;
        ~Line();
};

}


#endif

