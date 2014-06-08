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
		CairoContext* _cairoContext;
		cairo_surface_t* _cairo_surface;
    public:
		CairoCanvas(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorTyp=ColorType::OUTPUTDEFAULT);
        ~CairoCanvas();

        inline cairo_surface_t* getCairoSurface()
        {
        	return _cairo_surface;
        }

        virtual Context& getContext();

        virtual void freeSurface();


};


}
}

#endif

