#ifndef __DRAWTYPE_H__
#define __DRAWTYPE_H__

#include "titan/core/Types.hpp"
#include "titan/drawing/CanvasInterface.hpp"
#include "titan/drawing/BoundingBox.hpp"
#include "titan/drawing/Drawing.hpp"


namespace titan
{

class DrawType
{
    protected:
		int32 _zIndex;
    public:

		struct less
		{
			bool operator()(const titan::DrawType* dt1, const titan::DrawType* dt2) const;
		};

		DrawType(int32 zIndex=0):
        	_zIndex(zIndex)
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

        virtual void draw(const Drawing& drawing, CanvasInterface& canvas) = 0;
        virtual const BoundingBox& getBoundingBox() const = 0;
        virtual ~DrawType()
        {
        }
};

}

#endif

