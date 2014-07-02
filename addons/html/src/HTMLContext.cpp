#include "HTMLContext.hpp"
#include "HTMLCanvas.hpp"

#include <iostream>

namespace titan
{
namespace plugins
{


HTMLContext::HTMLContext(HTMLCanvas& htmlCanvas):
	_htmlCanvas(htmlCanvas),
	_currentColor(Color::argb32())
{
}

HTMLContext::~HTMLContext()
{
}

void HTMLContext::setStroke(const Stroke& stroke)
{
	_currentStroke=stroke;
}

void HTMLContext::setFill(const Fill& fill)
{
	_currentFill=fill;
}

void HTMLContext::setAntialising(Antialising::type antialising)
{
	
}

void HTMLContext::setFont(const Font& font)
{
	_currentFont=font;
}

void HTMLContext::drawText(uint32 x, uint32 y, const std::string& text)
{
	
}

void HTMLContext::drawLine(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
	
}
void HTMLContext::drawRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
	
}

void HTMLContext::fillRect(uint32 x1, uint32 y1, uint32 x2, uint32 y2)
{
}



}
}
