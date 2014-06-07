#include "CairoContext.hpp"
#include "CairoCanvas.hpp"

namespace titan
{
namespace plugins
{


CairoContext::CairoContext(CairoCanvas* cairoCanvas):
	_cairoCanvas(cairoCanvas)
{
}

CairoContext::~CairoContext()
{
}

void CairoContext::setStroke(Stroke& stroke)
{

}
void CairoContext::setFill(Fill& stroke)
{

}
void CairoContext::drawLine(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{

}
void CairoContext::drawRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{

}
void CairoContext::fillRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{

}



}
}
