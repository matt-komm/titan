#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include "titan/core/Types.hpp"
#include "titan/drawing/Canvas.hpp"

namespace titan
{

class Drawable
{
    protected:
		int32 _zIndex;
    public:
        Drawable();
        virtual void draw(Canvas& canvas) = 0;
        ~Drawable();
};

}

#endif

