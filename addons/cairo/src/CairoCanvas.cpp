#include "CairoCanvas.hpp"

#include <iostream>

namespace titan
{
namespace plugins
{

CairoCanvas::CairoCanvas(uint32 pxWidth, uint32 pxHeight, ColorType::type format):
	Canvas(pxWidth,pxHeight,format),
	_cairoContext(nullptr),
	_cairo_surface(nullptr)
{
	switch (format)
	{
		case ColorType::ARGB32:
			_cairo_surface = cairo_image_surface_create(
				CAIRO_FORMAT_ARGB32,
				pxWidth,
				pxHeight
			);
			break;
		default:
			throw std::string("cannot create canvas with format");
	}
	if (!_cairo_surface)
	{
		throw std::string("no cairo surface created");
	}
}

CairoCanvas::~CairoCanvas()
{
	delete _cairoContext;
	cairo_surface_destroy(_cairo_surface);
}

Context& CairoCanvas::getContext()
{
	if (!_cairoContext)
	{
		_cairoContext = new CairoContext(*this);
	}
	return *_cairoContext;
}

void CairoCanvas::save(std::string name, OutputFormat::type outputFormat)
{
	switch(outputFormat)
	{
		case OutputFormat::PNG:
			cairo_surface_write_to_png(_cairo_surface,name.c_str());
			break;

		default:
			throw std::string("cannot write image into format");
	}
}

}
}
