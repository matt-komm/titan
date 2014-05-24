#include "CairoCanvas.hpp"

namespace titan
{
namespace plugins
{

CairoCanvas::CairoCanvas(uint32 pxWidth, uint32 pxHeight, ColorType::type format):
	Canvas(pxWidth,pxHeight,format)
{
}

CairoCanvas::~CairoCanvas()
{
}

std::shared_ptr<Context> CairoCanvas::getContext()
{
	return std::shared_ptr<Context>(nullptr);
}

}
}
