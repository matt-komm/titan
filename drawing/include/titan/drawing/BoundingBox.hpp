#ifndef __BOUNDINGBOX_H__
#define __BOUNDINGBOX_H__

#include "titan/core/Quantity.hpp"

namespace titan
{

class BoundingBox
{
    protected:
		Quantity _x1,_y1,_x2,_y2;
    public:
		BoundingBox(const Quantity& x1=0*mm,const Quantity& y1=0*mm,const Quantity& x2=0*mm,const Quantity& y2=0*mm);
        ~BoundingBox();

        inline void setX1(const Quantity& x1)
		{
			_x1=x1;
		}
		inline void setX2(const Quantity& x2)
		{
			_x1=x2;
		}
		inline void setY1(const Quantity& y1)
		{
			_y1=y1;
		}
		inline void setY2(const Quantity& y2)
		{
			_y2=y2;
		}
};

}

#endif

