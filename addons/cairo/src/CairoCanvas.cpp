#include "CairoCanvas.hpp"

namespace titan
{
namespace plugins
{

CairoCanvas::CairoCanvas(uint32 pxWidth, uint32 pxHeight, ColorType::type format):
	Canvas(pxWidth,pxHeight,format)
{
	_cairoContext= new CairoContext(this);
}

CairoCanvas::~CairoCanvas()
{
	delete _cairoContext;
}

Context& CairoCanvas::getContext()
{
	return *_cairoContext;
}

void CairoCanvas::save(std::string name, OutputFormat::type outputFormat)
{

}

}
}
