#ifndef __DRAWABLETYPE_H__
#define __DRAWABLETYPE_H__

#include "titan/core/Types.hpp"
#include "titan/drawing/Canvas.hpp"
#include "titan/drawing/BoundingBox.hpp"

namespace titan
{

class DrawType
{
    protected:
		int32 _zIndex;
    public:
		DrawType():
        	_zIndex(0)
    	{
    	}
        inline int32 getZIndex() const
        {
        	return _zIndex;
        }

        inline void setZIndex(int32 zIndex)
        {
        	_zIndex=zIndex;
        }

        virtual void draw(Canvas& canvas) = 0;
        virtual const BoundingBox& getBoundingBox() const = 0;
        virtual ~DrawType()
        {
        }
};

}

#endif

