#ifndef __CAIROCANVAS_H__
#define __CAIROCANVAS_H__

#include "titan/drawing/Canvas.hpp"
#include "CairoContext.hpp"

#include <cairo.h>

namespace titan
{
namespace plugins
{


class CairoCanvas:
	public titan::Canvas
{
    protected:
		cairo_surface_t* _cairoSurface;
		CairoContext* _context;
    public:
		CairoCanvas(uint32 pxWidth, uint32 pxHeight, float32 pxmmResolution);
        ~CairoCanvas();
        virtual Context* getContext()
        {
        	return _context;
        }


        virtual Canvas* create(Quantity width, Quantity height, Quantity resolution);

};


}
}

#endif

