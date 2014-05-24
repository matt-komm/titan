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
    public:
		CairoCanvas(uint32 pxWidth, uint32 pxHeight, ColorType::type format);
        ~CairoCanvas();

        virtual std::shared_ptr<Context> getContext();

};


}
}

#endif

