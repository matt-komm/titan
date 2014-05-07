#ifndef __DRAWABLE_H__
#define __DRAWABLE_H__

#include "titan/core/Types.hpp"
#include "titan/drawing/Renderer.hpp"

class Drawable
{
    protected:
		int32 _zIndex;
    public:
        Drawable();
        virtual void draw(Renderer& renderer) = 0;
        ~Drawable();
};

#endif

