#include "HTMLCanvas.hpp"

#include <iostream>

namespace titan
{
namespace plugins
{

HTMLCanvas::HTMLCanvas(uint32 pxWidth, uint32 pxHeight, const std::string& outputName, OutputType::type outputType, ColorType::type colorType):
	CanvasInterface(pxWidth,pxHeight,outputName,outputType,colorType)
{
    _htmlContext = new HTMLContext(*this);
}

HTMLCanvas::~HTMLCanvas()
{
}

ContextInterface& HTMLCanvas::getContext()
{
    return *_htmlContext;
}

void HTMLCanvas::freeSurface()
{
	
}

}
}
