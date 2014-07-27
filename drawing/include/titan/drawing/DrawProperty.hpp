#ifndef __DRAWPROPERTY_H__
#define __DRAWPROPERTY_H__

#include "titan/drawing/CanvasInterface.hpp"

namespace titan
{

class DrawProperty
{
    protected:
    public:
		DrawProperty()
    	{

    	}

        virtual void apply(CanvasInterface& canvas) = 0;
        virtual bool operator==(const DrawProperty& drawProperty) = 0;
        virtual bool operator!=(const DrawProperty& drawProperty) = 0;
        virtual ~DrawProperty()
        {

        }
};

}

#endif

