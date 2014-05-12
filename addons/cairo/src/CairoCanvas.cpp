#include "CairoCanvas.hpp"

namespace titan
{
namespace plugins
{

CairoCanvas::CairoCanvas(uint32 pxWidth, uint32 pxHeight, float32 pxmmResolution):
	titan::Canvas(pxWidth,pxHeight,pxmmResolution),
	_cairoSurface(nullptr)
{
	cairo_t *cr = cairo_create (_cairoSurface);
}

CairoCanvas::~CairoCanvas()
{
}

Canvas* CairoCanvas::create(Quantity width, Quantity height, Quantity resolution)
{
	return new CairoCanvas(100,100,100);
}

Context* getContext()
{

}

}
}
