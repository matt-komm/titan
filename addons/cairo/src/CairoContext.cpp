#include "CairoContext.hpp"
#include "CairoCanvas.hpp"

#include <iostream>

namespace titan
{
namespace plugins
{


CairoContext::CairoContext(CairoCanvas& cairoCanvas):
	_cairoCanvas(cairoCanvas)
{
	_cairo_context=cairo_create(_cairoCanvas.getCairoSurface());
}

CairoContext::~CairoContext()
{
	cairo_destroy(_cairo_context);
}

void CairoContext::setStroke(Stroke& stroke)
{

}
void CairoContext::setFill(Fill& stroke)
{

}
void CairoContext::drawLine(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
	cairo_set_source_rgba(_cairo_context,0.0,0.0,0.0,1.0);
	cairo_move_to(_cairo_context,x1,y1);
	cairo_line_to(_cairo_context,x2,y2);
}
void CairoContext::drawRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{

}
void CairoContext::fillRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
	//std::cout<<"fill:" <<cairo_status_to_string(cairo_status(_cairo_context))<<std::endl;
	cairo_set_source_rgba(_cairo_context,0.0,0.0,0.0,1.0);
	cairo_rectangle(_cairo_context,x1,y1,x2-x1,y2-y1);
	cairo_fill(_cairo_context);
	//cairo_paint(_cairo_context);
}



}
}
