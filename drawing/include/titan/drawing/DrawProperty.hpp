#ifndef __DRAWPROPERTY_H__
#define __DRAWPROPERTY_H__

#include "titan/drawing/Canvas.hpp"

namespace titan
{

class DrawProperty
{
    protected:
    public:
		DrawProperty()
    	{

    	}

        virtual void apply(Canvas& canvas) = 0;
        virtual bool operator==(const DrawProperty& drawProperty) = 0;
        virtual bool operator!=(const DrawProperty& drawProperty) = 0;
        virtual ~DrawProperty()
        {

        }
};

}

#endif

